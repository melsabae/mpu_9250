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


	uint8_t write_buffer[5] = { 0x75 };
	uint8_t read_buffer[5] = { 0 };

	write(fd, write_buffer, 1);
	read(fd, read_buffer, 5);

	for(int i = 0; i < 5; i ++)
	{
		printf("%.2X ", read_buffer[i]);
	}

	close(fd);


	return 0;

	(void) argc;
	(void) argv;
}
