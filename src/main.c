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
    const uint8_t adr
    )
{
  // shift the value back into the low bit place, add 1, then raise 2 to this power
  // to get 2, 4, 8, and 16
  const float magic =
    (float) (1 << ((MPU_9250_WRITE_ACCEL_CONFIG_1_ACCEL_FS_SEL(adr) >> 3) + 1));

  // +- 2g, 4g, 8g, or 16g every 16 bits
  return magic / 32768.0f;
}


float get_gyroscope_conversion_factor(
    const int gdr
    )
{
  // shift the value back into the low bit place, then raise 2 to this power
  // to get 1, 2, 4, or 8
  const float magic =
    (float) (1 << (MPU_9250_WRITE_GYRO_CONFIG_GYRO_FS_SEL(gdr) >> 3));

  // +- 250, 500, 1000, or 2000 degrees per second per 16 bits
  return 250.0f * magic / 32768.0f;
}


void setup_mpu_9250(
      float* accel_conversion_factor
    , float* gyro_conversion_factor
    , const int fd
    , const int accel_data_rate
    , const int gyro_data_rate
    )
{
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

  write(fd, config_buffer1, sizeof(config_buffer1));
  write(fd, config_buffer2, sizeof(config_buffer2));

  *gyro_conversion_factor = get_gyroscope_conversion_factor(gyro_data_rate);
  *accel_conversion_factor = get_accelerometer_conversion_factor(accel_data_rate);
}


int main(int argc, char** argv)
{
	const char* device_path = "/dev/i2c-1";
	const int fd = open(device_path, O_RDWR);
	(void) ioctl(fd, I2C_SLAVE, I2CDETECT_ADDRESS_AD0); // AD0 is pulled down on breakout board

  // the sensor allows continuous writes and it automatically increments registers
  // exploit this fact to do a gigantic singular write call to config the sensor
  // pick the first register we want to configure, and then configure everything afterward


  float acf = 0.0f;
  float gcf = 0.0f;

  // +-2G accelerometer, +-250 degrees per second
  setup_mpu_9250(&acf, &gcf, fd, 0b00, 0b00);


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
          "%.8f,%.8f,%.8f,%.8f,%.8f,%.8f\n"
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
