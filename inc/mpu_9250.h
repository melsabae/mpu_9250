#ifndef __MPU_9250_H__
#define __MPU_9250_H__


#define DATASHEET_ADDRESS_AD0          (0xD0)
#define I2CDETECT_ADDRESS_AD0          (DATASHEET_ADDRESS_AD0 >> 1)
#define DATASHEET_ADDRESS_AD1          (((DATASHEET_ADDRESS_AD0) << 1) + 1)
#define I2CDETECT_ADDRESS_AD1          (DATASHEET_ADDRESS_AD1 >> 1)


#ifdef __cplusplus
extern "C" {
#endif


#include <inttypes.h>


typedef struct
{
} MPU_9250_Calibration;


#ifdef __cplusplus
  }
#endif

#endif // __MPU_9250_H__

