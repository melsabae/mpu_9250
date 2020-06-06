#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#include "mpu_9250.h"


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

  int return_code = mpu_9250_open_device(&fd, device_path, mpu_9250_ad_pin);

  if(0 != return_code)
  {
    fprintf(
        stderr
        , "failed to open device %s, return code %d\n"
        , device_path
        , return_code
        );

    return -1;
  }


  float acf = 0.0f;
  float gcf = 0.0f;

  // +-2G accelerometer, +-250 degrees per second
  setup_mpu_9250(&acf, &gcf, fd, 0b00, 0b00);


  const uint8_t write_buffer[1] = { (uint8_t) MPU_9250_REG_ACCEL_XOUT_H };
  uint8_t read_buffer[14] = { 0 };

  struct timeval begin;
  struct timeval end;

  while(true)
  {
    const int begin_ret = gettimeofday(&begin, NULL);
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
    const int end_ret = gettimeofday(&end, NULL);

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

    const int16_t accel_xout = (read_buffer[ 0] << 8) | read_buffer[ 1];
    const int16_t accel_yout = (read_buffer[ 2] << 8) | read_buffer[ 3];
    const int16_t accel_zout = (read_buffer[ 4] << 8) | read_buffer[ 5];
    const int16_t gyro_xout  = (read_buffer[ 8] << 8) | read_buffer[ 9];
    const int16_t gyro_yout  = (read_buffer[10] << 8) | read_buffer[11];
    const int16_t gyro_zout  = (read_buffer[12] << 8) | read_buffer[13];

    printf(
          "%ld.%lu,%ld.%lu%.8f,%.8f,%.8f,%.8f,%.8f,%.8f\n"
          , begin.tv_sec
          , begin.tv_usec
          , end.tv_sec
          , end.tv_usec
        , accel_xout * acf
        , accel_yout * acf
        , accel_zout * acf
        , gyro_xout *  gcf
        , gyro_yout *  gcf
        , gyro_zout *  gcf
        );
  }


	return close(fd);
	(void) argc;
	(void) argv;
}
