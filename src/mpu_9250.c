#include <linux/i2c-dev.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "mpu_9250.h"


int mpu_9250_open_device(
      int* fd
    , const char* device_path
    , const size_t mpu_9250_ad_pin
    )
{
  const int _fd = open(device_path, O_RDWR);

  if(_fd <= STDERR_FILENO)
  {
    return -1;
  }

  if(0 != ioctl(_fd, I2C_SLAVE, mpu_9250_ad_pin))
  {
    if(0 != close(_fd)) { return -2; }
    return -3;
  }

  *fd = _fd;
  return 0;
}


int mpu_9250_raw_read(
      uint8_t* data
    , const int fd
    , const size_t len
    )
{
  if(0 != flock(fd, LOCK_EX)) { return -1; }
  if(((ssize_t) len) != read(fd, data, len)) { return -2; }
  if(0 != flock(fd, LOCK_UN)) { return -3; }
  return 0;
}


int mpu_9250_raw_write(
      const int fd
    , const uint8_t* data
    , const size_t len
    )
{
  if(0 != flock(fd, LOCK_EX)) { return -1; }
  if(((ssize_t) len) != write(fd, data, len)) { return -2; }
  if(0 != flock(fd, LOCK_UN)) { return -3; }
  return 0;
}


float mpu_9250_get_accel_conversion_factor(
    const uint8_t accel_data_rate
    )
{
  // shift the value back into the low bit place, add 1, then raise 2 to this power
  // to get 2, 4, 8, and 16
  const float magic =
    (float) (1 << ((MPU_9250_WRITE_ACCEL_CONFIG_1_ACCEL_FS_SEL(accel_data_rate) >> 3) + 1));

  // +- 2g, 4g, 8g, or 16g every 16 bits
  return magic / 32768.0f;
}


float mpu_9250_get_gyro_conversion_factor(
    const uint8_t gyro_data_rate
    )
{
  // shift the value back into the low bit place, then raise 2 to this power
  // to get 1, 2, 4, or 8
  const float numerator =
    (float) (1 << (MPU_9250_WRITE_GYRO_CONFIG_GYRO_FS_SEL(gyro_data_rate) >> 3));

  // +- 250, 500, 1000, or 2000 degrees per second per 16 bits
  return 250.0f * numerator / 32768.0f;
}

