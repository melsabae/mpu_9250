#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


#include <zmq.h>


#include "mpu_9250.h"


const char* pub_endpoint = "ipc:///tmp/xsub";


typedef struct
{
  struct timespec begin_timestamp;
  struct timespec end_timestamp;
  float accel_x;
  float accel_y;
  float accel_z;
  float gyro_x;
  float gyro_y;
  float gyro_z;
} MPU_9250_Thing;


__attribute__((warn_unused_result))
int setup_mpu_9250(
      float* accel_conversion_factor
    , float* gyro_conversion_factor
    , const int fd
    , const int accel_data_rate
    , const int gyro_data_rate
    )
{
  // the sensor allows continuous writes and it automatically increments registers
  // exploit this fact to do a gigantic singular write call to config the sensor
  // pick the first register we want to configure, and then configure everything afterward
  const uint8_t config_buffer1[] =
  {
      MPU_9250_REG_GYRO_CONFIG
    , MPU_9250_WRITE_GYRO_CONFIG(0, 0, 0, gyro_data_rate, 0)
    , MPU_9250_WRITE_ACCEL_CONFIG_1(0, 0, 0, accel_data_rate)
  };

  const uint8_t config_buffer2[] =
  {
      MPU_9250_REG_PWR_MGMT_1
    , MPU_9250_WRITE_PWR_MGMT_1(0, 0, 0, 0, 0, 1)
  };

  if(0 != mpu_9250_raw_write(fd, config_buffer1, sizeof(config_buffer1)))
  {
    return -2;
  }

  if(0 != mpu_9250_raw_write(fd, config_buffer2, sizeof(config_buffer2)))
  {
    return -3;
  }

  *gyro_conversion_factor = mpu_9250_get_gyro_conversion_factor(gyro_data_rate);
  *accel_conversion_factor = mpu_9250_get_accel_conversion_factor(accel_data_rate);

  return 0;
}


int main(int argc, char** argv)
{
	const char* device_path = "/dev/i2c-1";
  const size_t mpu_9250_ad_pin = I2CDETECT_ADDRESS_AD0;
  int fd = 0;

  void* ctx = zmq_ctx_new();

  if(NULL == ctx)
  {
    fprintf(stderr, "failed to get a zmq socket");
    return -1;
  }

  void* pub = zmq_socket(ctx, ZMQ_PUB);

  if(NULL == pub)
  {
    fprintf(stderr, "failed to get a pub socket");
    return -2;
  }

  if(0 != zmq_connect(pub, pub_endpoint))
  {
    fprintf(stderr, "failed to connect pub socket to endpoint");
    return -3;
  }

  int return_code = mpu_9250_open_device(&fd, device_path, mpu_9250_ad_pin);

  if(0 != return_code)
  {
    fprintf(
        stderr
        , "failed to open device %s, return code %d\n"
        , device_path
        , return_code
        );

    return -4;
  }


  float acf = 0.0f;
  float gcf = 0.0f;


  // +-2G accelerometer, +-250 degrees per second
  return_code = setup_mpu_9250(&acf, &gcf, fd, 0b00, 0b00);

  if(0 != return_code)
  {
    fprintf(stderr, "failed to config device, return code %d\n", return_code);

    if(0 != close(fd))
    {
      return -5;
    }

    return -6;
  }


  const uint8_t write_buffer[1] = { (uint8_t) MPU_9250_REG_ACCEL_XOUT_H };
  uint8_t read_buffer[14] = { 0 };

  MPU_9250_Thing thing;
  uint8_t serialized_buffer[sizeof(MPU_9250_Thing)] = { 0 };

  while(true)
  {
    const int begin_ret = clock_gettime(CLOCK_REALTIME, &thing.begin_timestamp);
    if(0 != begin_ret)
    {
      fprintf(stderr, "failed to get begin timestamp, return code %d\n", begin_ret);
      fflush(stderr);
      continue;
    }

    const int write_ret = mpu_9250_raw_write(fd, write_buffer, sizeof(write_buffer));

    if(0 != write_ret)
    {
      fprintf(stderr, "failed to write device, return code %d\n", write_ret);
      fflush(stderr);
      continue;
    }

    const int read_ret = mpu_9250_raw_read(read_buffer, fd, sizeof(read_buffer));
    const int end_ret = clock_gettime(CLOCK_REALTIME, &thing.end_timestamp);

    if(0 != end_ret)
    {
      fprintf(stderr, "failed to end timestamp, return code %d\n", end_ret);
      fflush(stderr);
      continue;
    }

    if(0 != read_ret)
    {
      fprintf(stderr, "failed to read device, return code %d\n", read_ret);
      fflush(stderr);
      continue;
    }

    thing.accel_x = acf * ((float) (int16_t) ((read_buffer[ 0] << 8) | read_buffer[ 1]));
    thing.accel_y = acf * ((float) (int16_t) ((read_buffer[ 2] << 8) | read_buffer[ 3]));
    thing.accel_z = acf * ((float) (int16_t) ((read_buffer[ 4] << 8) | read_buffer[ 5]));
    thing.gyro_x  = gcf * ((float) (int16_t) ((read_buffer[ 8] << 8) | read_buffer[ 9]));
    thing.gyro_y  = gcf * ((float) (int16_t) ((read_buffer[10] << 8) | read_buffer[11]));
    thing.gyro_z  = gcf * ((float) (int16_t) ((read_buffer[12] << 8) | read_buffer[13]));

    memcpy(serialized_buffer, &thing, sizeof(thing));

    //printf(
    //    "%ld.%lu,%ld.%lu%.8f,%.8f,%.8f,%.8f,%.8f,%.8f\n"
    //  , thing.begin_timestamp.tv_sec
    //  , thing.begin_timestamp.tv_usec
    //  , thing.end_timestamp.tv_sec
    //  , thing.end_timestamp.tv_usec
    //  , thing.accel_x
    //  , thing.accel_y
    //  , thing.accel_z
    //  , thing.gyro_x
    //  , thing.gyro_y
    //  , thing.gyro_z
    //);

    //printf("%zu,%zu\n", sizeof(thing.end_timestamp.tv_sec), sizeof(thing.end_timestamp.tv_nsec));

    if(sizeof(thing) != zmq_send(pub, serialized_buffer, sizeof(thing), 0))
    {
      fprintf(stderr, "failed to send data to pub socket");
      continue;
    }
  }


	return close(fd);
	(void) argc;
	(void) argv;
}
