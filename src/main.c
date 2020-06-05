#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <inttypes.h>

#include "mpu_9250.h"


int main(int argc, char** argv)
{
	const char* device_path = "/dev/i2c-1";
	const int fd = open(device_path, O_RDWR);
	(void) ioctl(fd, I2C_SLAVE, I2CDETECT_ADDRESS_AD0); // AD0 is pulled down on breakout board

  while(true)
  {
    const uint8_t write_buffer[1] = { 0x3b };
    uint8_t read_buffer[14] = { 0 };

    write(fd, write_buffer, sizeof(write_buffer));
    read(fd, read_buffer, sizeof(read_buffer));

    const int32_t accel_xout = (read_buffer[ 0] << 8) | read_buffer[ 1];
    const int32_t accel_yout = (read_buffer[ 2] << 8) | read_buffer[ 3];
    const int32_t accel_zout = (read_buffer[ 4] << 8) | read_buffer[ 5];
    const int32_t temp       = (read_buffer[ 6] << 8) | read_buffer[ 7];
    const int32_t gyro_xout  = (read_buffer[ 8] << 8) | read_buffer[ 9];
    const int32_t gyro_yout  = (read_buffer[10] << 8) | read_buffer[11];
    const int32_t gyro_zout  = (read_buffer[12] << 8) | read_buffer[13];

    printf(
          "%d,%d,%d,%d,%d,%d,%d\n"
        , accel_xout
        , accel_yout
        , accel_zout
        , gyro_xout
        , gyro_yout
        , gyro_zout
        , temp
        );
  }


	return close(fd);
	(void) argc;
	(void) argv;
}
