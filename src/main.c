#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <inttypes.h>

#include "mpu_9250.h"


float get_accelerometer_conversion_factor(
    const int accelerometer_data_rate
    )
{
  return 0.0f;
}


int get_accelerometer_data_rate(
    const int accelerometer_data_rate_requested
    )
{
  return 0;
}


float get_gyroscope_conversion_factor(
    const int gyroscope_data_rate
    )
{
  return 0.0f;
}


int get_gyroscope_data_rate(
    const int gyroscope_data_rate_requested
    )
{
  return 0;
}


void setup_mpu_9250(
      float* accelerometer_conversion_factor
    , float* gyroscope_conversion_factor
    , const int fd
    , const int gyroscope_data_rate
    , const int accelerometer_data_rate
    )
{
  const int _a = get_accelerometer_data_rate(accelerometer_data_rate);
  const int _g = get_gyroscope_data_rate(gyroscope_data_rate);

  const uint8_t config_buffer1[] =
  {
      MPU_9250_REG_GYRO_CONFIG
    , MPU_9250_WRITE_GYRO_CONFIG(0, 0, 0, 0b11, 0) // 2000 dps
    , MPU_9250_WRITE_ACCEL_CONFIG_1(0, 0, 0, 0b11) // 16g
  };

  const uint8_t config_buffer2[] =
  {
      MPU_9250_REG_PWR_MGMT_1
    , MPU_9250_WRITE_PWR_MGMT_1(0, 0, 0, 0, 0, 1)
  };

  write(fd, config_buffer1, sizeof(config_buffer1));
  write(fd, config_buffer2, sizeof(config_buffer2));

  *accelerometer_conversion_factor = get_accelerometer_conversion_factor(_a);
  *gyroscope_conversion_factor = get_gyroscope_conversion_factor(_a);
}


int main(int argc, char** argv)
{
	const char* device_path = "/dev/i2c-1";
	const int fd = open(device_path, O_RDWR);
	(void) ioctl(fd, I2C_SLAVE, I2CDETECT_ADDRESS_AD0); // AD0 is pulled down on breakout board

  // the sensor allows continuous writes and it automatically increments registers
  // exploit this fact to do a gigantic singular write call to config the sensor
  // pick the first register we want to configure, and then configure everything afterward

  while(true)
  {
    const uint8_t write_buffer[1] = { 0x3b };
    uint8_t read_buffer[14] = { 0 };

    write(fd, write_buffer, sizeof(write_buffer));
    read(fd, read_buffer, sizeof(read_buffer));

    const int16_t accel_xout = (read_buffer[ 0] << 8) | read_buffer[ 1];
    const int16_t accel_yout = (read_buffer[ 2] << 8) | read_buffer[ 3];
    const int16_t accel_zout = (read_buffer[ 4] << 8) | read_buffer[ 5];
    const int16_t gyro_xout  = (read_buffer[ 8] << 8) | read_buffer[ 9];
    const int16_t gyro_yout  = (read_buffer[10] << 8) | read_buffer[11];
    const int16_t gyro_zout  = (read_buffer[12] << 8) | read_buffer[13];

    printf(
          "%f,%f,%f,%f,%f,%f\n"
        , accel_xout * 16.0f / 32768.0f
        , accel_yout * 16.0f / 32768.0f
        , accel_zout * 16.0f / 32768.0f
        , gyro_xout * 2000.0f / 32768.0f
        , gyro_yout * 2000.0f / 32768.0f
        , gyro_zout * 2000.0f / 32768.0f
        );
  }


	return close(fd);
	(void) argc;
	(void) argv;
}
