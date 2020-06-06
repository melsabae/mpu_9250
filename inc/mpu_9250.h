#ifndef __MPU_9250_H__
#define __MPU_9250_H__
#ifdef __cplusplus
extern "C" {
#endif


#include <inttypes.h>


#define DATASHEET_ADDRESS_AD0          (0xD0)
#define I2CDETECT_ADDRESS_AD0          (DATASHEET_ADDRESS_AD0 >> 1)
#define DATASHEET_ADDRESS_AD1          (((DATASHEET_ADDRESS_AD0) << 1) + 1)
#define I2CDETECT_ADDRESS_AD1          (DATASHEET_ADDRESS_AD1 >> 1)


#define MPU_9250_WRITE_SELF_TEST_X_GYRO(val)                  ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_SELF_TEST_Y_GYRO(val)                  ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_SELF_TEST_Z_GYRO(val)                  ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_SELF_TEST_X_ACCEL(val)                 ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_SELF_TEST_Y_ACCEL(val)                 ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_SELF_TEST_Z_ACCEL(val)                 ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_XG_OFFSET_H(val)                       ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_XG_OFFSET_L(val)                       ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_YG_OFFSET_H(val)                       ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_YG_OFFSET_L(val)                       ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_ZG_OFFSET_H(val)                       ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_ZG_OFFSET_L(val)                       ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_SMPLRT_DIV(val)                        ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_CONFIG_FIFO_MODE(val)                  ((uint8_t) (((val) & 0x01) << 6))
#define MPU_9250_WRITE_CONFIG_EXT_SYNC_SET(val)               ((uint8_t) (((val) & 0x07) << 3))
#define MPU_9250_WRITE_CONFIG_DLPF_CFG(val)                   ((uint8_t) (((val) & 0x07) << 0))
#define MPU_9250_WRITE_GYRO_CONFIG_X_GYRO_CTEN(val)           ((uint8_t) (((val) & 0x01) << 7))
#define MPU_9250_WRITE_GYRO_CONFIG_Y_GYRO_CTEN(val)           ((uint8_t) (((val) & 0x01) << 6))
#define MPU_9250_WRITE_GYRO_CONFIG_Z_GYRO_CTEN(val)           ((uint8_t) (((val) & 0x01) << 5))
#define MPU_9250_WRITE_GYRO_CONFIG_GYRO_FS_SEL(val)           ((uint8_t) (((val) & 0x03) << 3))
#define MPU_9250_WRITE_GYRO_CONFIG_CHOICE_B(val)              ((uint8_t) (((val) & 0x03) << 0))
#define MPU_9250_WRITE_ACCEL_CONFIG_1_AX_ST_EN(val)           ((uint8_t) (((val) & 0x01) << 7))
#define MPU_9250_WRITE_ACCEL_CONFIG_1_AY_ST_EN(val)           ((uint8_t) (((val) & 0x01) << 6))
#define MPU_9250_WRITE_ACCEL_CONFIG_1_AZ_ST_EN(val)           ((uint8_t) (((val) & 0x01) << 5))
#define MPU_9250_WRITE_ACCEL_CONFIG_1_ACCEL_FS_SEL(val)       ((uint8_t) (((val) & 0x03) << 3))
#define MPU_9250_WRITE_ACCEL_CONFIG_2_ACCEL_FCHOICE_B(val)    ((uint8_t) (((val) & 0x03) << 2))
#define MPU_9250_WRITE_ACCEL_CONFIG_2_ACCEL_A_DLPF_CFG(val)   ((uint8_t) (((val) & 0x03) << 0))
#define MPU_9250_WRITE_LP_ACCEL_ODR_LPOSC_CLKSEL(val)         ((uint8_t) (((val) & 0x0F) << 0))
#define MPU_9250_WRITE_WOM_THR(val)                           ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_FIFO_EN_TEMP_FIFO_EN(val)              ((uint8_t) (((val) & 0x01) << 7))
#define MPU_9250_WRITE_FIFO_EN_GYRO_XO_UT(val)                ((uint8_t) (((val) & 0x01) << 6))
#define MPU_9250_WRITE_FIFO_EN_GYRO_YO_UT(val)                ((uint8_t) (((val) & 0x01) << 5))
#define MPU_9250_WRITE_FIFO_EN_GYRO_ZO_UT(val)                ((uint8_t) (((val) & 0x01) << 4))
#define MPU_9250_WRITE_FIFO_EN_ACCEL(val)                     ((uint8_t) (((val) & 0x01) << 3))
#define MPU_9250_WRITE_FIFO_EN_SLV2(val)                      ((uint8_t) (((val) & 0x01) << 2))
#define MPU_9250_WRITE_FIFO_EN_SLV1(val)                      ((uint8_t) (((val) & 0x01) << 1))
#define MPU_9250_WRITE_FIFO_EN_SLV0(val)                      ((uint8_t) (((val) & 0x01) << 0))
#define MPU_9250_WRITE_I2C_MST_CTRL_MULT_MST_EN(val)          ((uint8_t) (((val) & 0x01) << 7))
#define MPU_9250_WRITE_I2C_MST_CTRL_WAIT_FOR_ES(val)          ((uint8_t) (((val) & 0x01) << 6))
#define MPU_9250_WRITE_I2C_MST_CTRL_SLV_3_FIFO_EN(val)        ((uint8_t) (((val) & 0x01) << 5))
#define MPU_9250_WRITE_I2C_MST_CTRL_I2C_MST_P_NSR(val)        ((uint8_t) (((val) & 0x01) << 4))
#define MPU_9250_WRITE_I2C_MST_CTRL_I2C_MST_CLK(val)          ((uint8_t) (((val) & 0x0F) << 0))
#define MPU_9250_WRITE_SLV0_ADDR_I2C_SLV0_RNW(val)            ((uint8_t) (((val) & 0x01) << 7))
#define MPU_9250_WRITE_SLV0_ADDR_I2C_ID_0(val)                ((uint8_t) (((val) & 0x7F) << 0))
#define MPU_9250_WRITE_SLV0_REG(val)                          ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_EN(val)             ((uint8_t) (((val) & 0x01) << 7))
#define MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_BYTE_SW(val)        ((uint8_t) (((val) & 0x01) << 6))
#define MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_REG_DIS(val)        ((uint8_t) (((val) & 0x01) << 5))
#define MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_GRP(val)            ((uint8_t) (((val) & 0x01) << 4))
#define MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_LENG(val)           ((uint8_t) (((val) & 0x0F) << 0))
#define MPU_9250_WRITE_SLV0_DO(val)                           ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_SLV1_ADDR_I2C_SLV1_RNW(val)            MPU_9250_WRITE_SLV0_ADDR_I2C_SLV0_RNW(val)
#define MPU_9250_WRITE_SLV1_ADDR_I2C_ID_1(val)                MPU_9250_WRITE_SLV0_ADDR_I2C_ID_0(val)
#define MPU_9250_WRITE_SLV1_REG(val)                          MPU_9250_WRITE_SLV0_REG(val)
#define MPU_9250_WRITE_SLV1_CTRL_I2C_SLV1_EN(val)             MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_EN(val)
#define MPU_9250_WRITE_SLV1_CTRL_I2C_SLV1_BYTE_SW(val)        MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_BYTE_SW(val)
#define MPU_9250_WRITE_SLV1_CTRL_I2C_SLV1_REG_DIS(val)        MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_REG_DIS(val)
#define MPU_9250_WRITE_SLV1_CTRL_I2C_SLV1_GRP(val)            MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_GRP(val)
#define MPU_9250_WRITE_SLV1_CTRL_I2C_SLV1_LENG(val)           MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_LENG(val)
#define MPU_9250_WRITE_SLV1_DO(val)                           MPU_9250_WRITE_SLV0_DO(val)
#define MPU_9250_WRITE_SLV2_ADDR_I2C_SLV2_RNW(val)            MPU_9250_WRITE_SLV0_ADDR_I2C_SLV0_RNW(val)
#define MPU_9250_WRITE_SLV2_ADDR_I2C_ID_2(val)                MPU_9250_WRITE_SLV0_ADDR_I2C_ID_0(val)
#define MPU_9250_WRITE_SLV2_REG(val)                          MPU_9250_WRITE_SLV0_REG(val)
#define MPU_9250_WRITE_SLV2_CTRL_I2C_SLV2_EN(val)             MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_EN(val)
#define MPU_9250_WRITE_SLV2_CTRL_I2C_SLV2_BYTE_SW(val)        MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_BYTE_SW(val)
#define MPU_9250_WRITE_SLV2_CTRL_I2C_SLV2_REG_DIS(val)        MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_REG_DIS(val)
#define MPU_9250_WRITE_SLV2_CTRL_I2C_SLV2_GRP(val)            MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_GRP(val)
#define MPU_9250_WRITE_SLV2_CTRL_I2C_SLV2_LENG(val)           MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_LENG(val)
#define MPU_9250_WRITE_SLV2_DO(val)                           MPU_9250_WRITE_SLV0_DO(val)
#define MPU_9250_WRITE_SLV3_ADDR_I2C_SLV3_RNW(val)            MPU_9250_WRITE_SLV0_ADDR_I2C_SLV0_RNW(val)
#define MPU_9250_WRITE_SLV3_ADDR_I2C_ID_3(val)                MPU_9250_WRITE_SLV0_ADDR_I2C_ID_0(val)
#define MPU_9250_WRITE_SLV3_REG(val)                          MPU_9250_WRITE_SLV0_REG(val)
#define MPU_9250_WRITE_SLV3_CTRL_I2C_SLV3_EN(val)             MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_EN(val)
#define MPU_9250_WRITE_SLV3_CTRL_I2C_SLV3_BYTE_SW(val)        MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_BYTE_SW(val)
#define MPU_9250_WRITE_SLV3_CTRL_I2C_SLV3_REG_DIS(val)        MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_REG_DIS(val)
#define MPU_9250_WRITE_SLV3_CTRL_I2C_SLV3_GRP(val)            MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_GRP(val)
#define MPU_9250_WRITE_SLV3_CTRL_I2C_SLV3_LENG(val)           MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_LENG(val)
#define MPU_9250_WRITE_SLV3_DO(val)                           MPU_9250_WRITE_SLV0_DO(val)
#define MPU_9250_WRITE_SLV4_ADDR_I2C_SLV4_RNW(val)            MPU_9250_WRITE_SLV0_ADDR_I2C_SLV0_RNW(val)
#define MPU_9250_WRITE_SLV4_ADDR_I2C_ID_4(val)                MPU_9250_WRITE_SLV0_ADDR_I2C_ID_0(val)
#define MPU_9250_WRITE_SLV4_REG(val)                          MPU_9250_WRITE_SLV0_REG(val)
#define MPU_9250_WRITE_SLV4_CTRL_I2C_SLV4_EN(val)             MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_EN(val)
#define MPU_9250_WRITE_SLV4_CTRL_I2C_SLV4_BYTE_SW(val)        MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_BYTE_SW(val)
#define MPU_9250_WRITE_SLV4_CTRL_I2C_SLV4_REG_DIS(val)        MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_REG_DIS(val)
#define MPU_9250_WRITE_SLV4_CTRL_I2C_SLV4_GRP(val)            MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_GRP(val)
#define MPU_9250_WRITE_SLV4_CTRL_I2C_SLV4_LENG(val)           MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_LENG(val)
#define MPU_9250_WRITE_SLV4_DO(val)                           MPU_9250_WRITE_SLV0_DO(val)
#define MPU_9250_WRITE_INT_PIN_CFG_ACTL(val)                  ((uint8_t) (((val) & 0x01) << 7))
#define MPU_9250_WRITE_INT_PIN_CFG_OPEN(val)                  ((uint8_t) (((val) & 0x01) << 6))
#define MPU_9250_WRITE_INT_PIN_CFG_LATCH_INT_EN(val)          ((uint8_t) (((val) & 0x01) << 5))
#define MPU_9250_WRITE_INT_PIN_CFG_INT_ANYRD_2CLEAR(val)      ((uint8_t) (((val) & 0x01) << 4))
#define MPU_9250_WRITE_INT_PIN_CFG_ACTL_FSY_NC(val)           ((uint8_t) (((val) & 0x01) << 3))
#define MPU_9250_WRITE_INT_PIN_CFG_FSYNC_INT_MODE_EN(val)     ((uint8_t) (((val) & 0x01) << 2))
#define MPU_9250_WRITE_INT_PIN_CFG_BYPASS_EN(val)             ((uint8_t) (((val) & 0x01) << 1))
#define MPU_9250_WRITE_INT_ENABLE_WOM_EN(val)                 ((uint8_t) (((val) & 0x01) << 6))
#define MPU_9250_WRITE_INT_ENABLE_FIFO_OFLOW_EN(val)          ((uint8_t) (((val) & 0x01) << 4))
#define MPU_9250_WRITE_INT_ENABLE_FSYNC_INT_EN(val)           ((uint8_t) (((val) & 0x01) << 3))
#define MPU_9250_WRITE_INT_ENABLE_RAW_RDY_EN(val)             ((uint8_t) (((val) & 0x01) << 0))
#define MPU_9250_WRITE_MST_DELAY_CTRL_DELAY_ES_SHADOW(val)    ((uint8_t) (((val) & 0x01) << 7))
#define MPU_9250_WRITE_MST_DELAY_CTRL_I2C_SLV4_DLY_EN(val)    ((uint8_t) (((val) & 0x01) << 4))
#define MPU_9250_WRITE_MST_DELAY_CTRL_I2C_SLV3_DLY_EN(val)    ((uint8_t) (((val) & 0x01) << 3))
#define MPU_9250_WRITE_MST_DELAY_CTRL_I2C_SLV2_DLY_EN(val)    ((uint8_t) (((val) & 0x01) << 2))
#define MPU_9250_WRITE_MST_DELAY_CTRL_I2C_SLV1_DLY_EN(val)    ((uint8_t) (((val) & 0x01) << 1))
#define MPU_9250_WRITE_MST_DELAY_CTRL_I2C_SLV0_DLY_EN(val)    ((uint8_t) (((val) & 0x01) << 0))
#define MPU_9250_WRITE_SIGNAL_PATH_RESET_GYRO_RESET(val)      ((uint8_t) (((val) & 0x01) << 2))
#define MPU_9250_WRITE_SIGNAL_PATH_RESET_ACCEL_RESET(val)     ((uint8_t) (((val) & 0x01) << 1))
#define MPU_9250_WRITE_SIGNAL_PATH_RESET_TEMP_RESET(val)      ((uint8_t) (((val) & 0x01) << 0))
#define MPU_9250_WRITE_MOT_DETECT_CTRL_ACCEL_INT_EN(val)      ((uint8_t) (((val) & 0x01) << 7))
#define MPU_9250_WRITE_MOT_DETECT_CTRL_ACCEL_INT_EL_MODE(val) ((uint8_t) (((val) & 0x01) << 6))
#define MPU_9250_WRITE_USER_CTRL_FIFO_EN(val)                 ((uint8_t) (((val) & 0x01) << 6))
#define MPU_9250_WRITE_USER_CTRL_I2C_MST_EN(val)              ((uint8_t) (((val) & 0x01) << 5))
#define MPU_9250_WRITE_USER_CTRL_I2C_IF_DIS(val)              ((uint8_t) (((val) & 0x01) << 4))
#define MPU_9250_WRITE_USER_CTRL_FIFO_RST(val)                ((uint8_t) (((val) & 0x01) << 2))
#define MPU_9250_WRITE_USER_CTRL_I2C_MST_RST(val)             ((uint8_t) (((val) & 0x01) << 1))
#define MPU_9250_WRITE_USER_CTRL_SIG_COND_RST(val)            ((uint8_t) (((val) & 0x01) << 0))
#define MPU_9250_WRITE_PWR_MGMT_1_H_RESET(val)                ((uint8_t) (((val) & 0x01) << 7))
#define MPU_9250_WRITE_PWR_MGMT_1_SLEEP(val)                  ((uint8_t) (((val) & 0x01) << 6))
#define MPU_9250_WRITE_PWR_MGMT_1_CYCLE(val)                  ((uint8_t) (((val) & 0x01) << 5))
#define MPU_9250_WRITE_PWR_MGMT_1_GYRO_STANDBY(val)           ((uint8_t) (((val) & 0x01) << 4))
#define MPU_9250_WRITE_PWR_MGMT_1_PD_PTAT(val)                ((uint8_t) (((val) & 0x01) << 3))
#define MPU_9250_WRITE_PWR_MGMT_1_CLKSEL(val)                 ((uint8_t) (((val) & 0x07) << 0))
#define MPU_9250_WRITE_PWR_MGMT_2_DIS_XA(val)                 ((uint8_t) (((val) & 0x01) << 5))
#define MPU_9250_WRITE_PWR_MGMT_2_DIS_YA(val)                 ((uint8_t) (((val) & 0x01) << 4))
#define MPU_9250_WRITE_PWR_MGMT_2_DIS_ZA(val)                 ((uint8_t) (((val) & 0x01) << 3))
#define MPU_9250_WRITE_PWR_MGMT_2_DIS_XG(val)                 ((uint8_t) (((val) & 0x01) << 2))
#define MPU_9250_WRITE_PWR_MGMT_2_DIS_YG(val)                 ((uint8_t) (((val) & 0x01) << 1))
#define MPU_9250_WRITE_PWR_MGMT_2_DIS_ZG(val)                 ((uint8_t) (((val) & 0x01) << 0))
#define MPU_9250_WRITE_FIFO_COUNTH(val)                       ((uint8_t) (((val) & 0x1F) << 0))
#define MPU_9250_WRITE_FIFO_COUNTL(val)                       ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_FIFO_R_W(val)                          ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_XA_OFFSET_H(val)                       ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_XA_OFFSET_L(val)                       ((uint8_t) (((val) & 0x7F) << 1))
#define MPU_9250_WRITE_YA_OFFSET_H(val)                       ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_YA_OFFSET_L(val)                       ((uint8_t) (((val) & 0x7F) << 1))
#define MPU_9250_WRITE_ZA_OFFSET_H(val)                       ((uint8_t) (((val) & 0xFF) << 0))
#define MPU_9250_WRITE_ZA_OFFSET_L(val)                       ((uint8_t) (((val) & 0x7F) << 1))


#define MPU_9250_READ_SELF_TEST_X_GYRO(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_SELF_TEST_Y_GYRO(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_SELF_TEST_Z_GYRO(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_SELF_TEST_X_ACCEL(val)                  ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_SELF_TEST_Y_ACCEL(val)                  ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_SELF_TEST_Z_ACCEL(val)                  ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_XG_OFFSET_H(val)                        ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_XG_OFFSET_L(val)                        ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_YG_OFFSET_H(val)                        ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_YG_OFFSET_L(val)                        ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_ZG_OFFSET_H(val)                        ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_ZG_OFFSET_L(val)                        ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_SMPLRT_DIV(val)                         ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_CONFIG_FIFO_MODE(val)                   ((uint8_t) ((val) & (0x01 << 6)))
#define MPU_9250_READ_CONFIG_EXT_SYNC_SET(val)                ((uint8_t) ((val) & (0x07 << 3)))
#define MPU_9250_READ_CONFIG_DLPF_CFG(val)                    ((uint8_t) ((val) & (0x07 << 0)))
#define MPU_9250_READ_GYRO_CONFIG_X_GYRO_CTEN(val)            ((uint8_t) ((val) & (0x01 << 7)))
#define MPU_9250_READ_GYRO_CONFIG_Y_GYRO_CTEN(val)            ((uint8_t) ((val) & (0x01 << 6)))
#define MPU_9250_READ_GYRO_CONFIG_Z_GYRO_CTEN(val)            ((uint8_t) ((val) & (0x01 << 5)))
#define MPU_9250_READ_GYRO_CONFIG_GYRO_FS_SEL(val)            ((uint8_t) ((val) & (0x03 << 3)))
#define MPU_9250_READ_GYRO_CONFIG_CHOICE_B(val)               ((uint8_t) ((val) & (0x03 << 0)))
#define MPU_9250_READ_ACCEL_CONFIG_1_AX_ST_EN(val)            ((uint8_t) ((val) & (0x01 << 7)))
#define MPU_9250_READ_ACCEL_CONFIG_1_AY_ST_EN(val)            ((uint8_t) ((val) & (0x01 << 6)))
#define MPU_9250_READ_ACCEL_CONFIG_1_AZ_ST_EN(val)            ((uint8_t) ((val) & (0x01 << 5)))
#define MPU_9250_READ_ACCEL_CONFIG_1_ACCEL_FS_SEL(val)        ((uint8_t) ((val) & (0x03 << 3)))
#define MPU_9250_READ_ACCEL_CONFIG_2_ACCEL_FCHOICE_B(val)     ((uint8_t) ((val) & (0x03 << 2)))
#define MPU_9250_READ_ACCEL_CONFIG_2_ACCEL_A_DLPF_CFG(val)    ((uint8_t) ((val) & (0x03 << 0)))
#define MPU_9250_READ_LP_ACCEL_ODR_LPOSC_CLKSEL(val)          ((uint8_t) ((val) & (0x0F << 0)))
#define MPU_9250_READ_WOM_THR(val)							              ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_FIFO_EN_TEMP_FIFO_EN(val)               ((uint8_t) ((val) & (0x01 << 7)))
#define MPU_9250_READ_FIFO_EN_GYRO_XO_UT(val)                 ((uint8_t) ((val) & (0x01 << 6)))
#define MPU_9250_READ_FIFO_EN_GYRO_YO_UT(val)                 ((uint8_t) ((val) & (0x01 << 5)))
#define MPU_9250_READ_FIFO_EN_GYRO_ZO_UT(val)                 ((uint8_t) ((val) & (0x01 << 4)))
#define MPU_9250_READ_FIFO_EN_ACCEL(val)                      ((uint8_t) ((val) & (0x01 << 3)))
#define MPU_9250_READ_FIFO_EN_SLV2(val)                       ((uint8_t) ((val) & (0x01 << 2)))
#define MPU_9250_READ_FIFO_EN_SLV1(val)                       ((uint8_t) ((val) & (0x01 << 1)))
#define MPU_9250_READ_FIFO_EN_SLV0(val)                       ((uint8_t) ((val) & (0x01 << 0)))
#define MPU_9250_READ_I2C_MST_CTRL_MULT_MST_EN(val)           ((uint8_t) ((val) & (0x01 << 7)))
#define MPU_9250_READ_I2C_MST_CTRL_WAIT_FOR_ES(val)           ((uint8_t) ((val) & (0x01 << 6)))
#define MPU_9250_READ_I2C_MST_CTRL_SLV_3_FIFO_EN(val)         ((uint8_t) ((val) & (0x01 << 5)))
#define MPU_9250_READ_I2C_MST_CTRL_I2C_MST_P_NSR(val)         ((uint8_t) ((val) & (0x01 << 4)))
#define MPU_9250_READ_I2C_MST_CTRL_I2C_MST_CLK(val)           ((uint8_t) ((val) & (0x0F << 0)))
#define MPU_9250_READ_SLV0_ADDR_I2C_SLV0_RNW(val)             ((uint8_t) ((val) & (0x01 << 7)))
#define MPU_9250_READ_SLV0_ADDR_I2C_ID_0(val)                 ((uint8_t) ((val) & (0x7F << 0)))
#define MPU_9250_READ_SLV0_REG(val)                           ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_SLV0_CTRL_I2C_SLV0_EN(val)              ((uint8_t) ((val) & (0x01 << 7)))
#define MPU_9250_READ_SLV0_CTRL_I2C_SLV0_BYTE_SW(val)         ((uint8_t) ((val) & (0x01 << 6)))
#define MPU_9250_READ_SLV0_CTRL_I2C_SLV0_REG_DIS(val)         ((uint8_t) ((val) & (0x01 << 5)))
#define MPU_9250_READ_SLV0_CTRL_I2C_SLV0_GRP(val)             ((uint8_t) ((val) & (0x01 << 4)))
#define MPU_9250_READ_SLV0_CTRL_I2C_SLV0_LENG(val)            ((uint8_t) ((val) & (0x0F << 0)))
#define MPU_9250_READ_SLV1_ADDR_I2C_SLV1_RNW(val)             MPU_9250_READ_SLV0_ADDR_I2C_SLV0_RNW(val)
#define MPU_9250_READ_SLV1_ADDR_I2C_ID_1(val)                 MPU_9250_READ_SLV0_ADDR_I2C_ID_0(val)
#define MPU_9250_READ_SLV1_REG(val)                           MPU_9250_READ_SLV0_REG(val)
#define MPU_9250_READ_SLV1_CTRL_I2C_SLV1_EN(val)              MPU_9250_READ_SLV0_CTRL_I2C_SLV0_EN(val)
#define MPU_9250_READ_SLV1_CTRL_I2C_SLV1_BYTE_SW(val)         MPU_9250_READ_SLV0_CTRL_I2C_SLV0_BYTE_SW(val)
#define MPU_9250_READ_SLV1_CTRL_I2C_SLV1_REG_DIS(val)         MPU_9250_READ_SLV0_CTRL_I2C_SLV0_REG_DIS(val)
#define MPU_9250_READ_SLV1_CTRL_I2C_SLV1_GRP(val)             MPU_9250_READ_SLV0_CTRL_I2C_SLV0_GRP(val)
#define MPU_9250_READ_SLV1_CTRL_I2C_SLV1_LENG(val)            MPU_9250_READ_SLV0_CTRL_I2C_SLV0_LENG(val)
#define MPU_9250_READ_SLV2_ADDR_I2C_SLV2_RNW(val)             MPU_9250_READ_SLV0_ADDR_I2C_SLV0_RNW(val)
#define MPU_9250_READ_SLV2_ADDR_I2C_ID_2(val)                 MPU_9250_READ_SLV0_ADDR_I2C_ID_0(val)
#define MPU_9250_READ_SLV2_REG(val)                           MPU_9250_READ_SLV0_REG(val)
#define MPU_9250_READ_SLV2_CTRL_I2C_SLV2_EN(val)              MPU_9250_READ_SLV0_CTRL_I2C_SLV0_EN(val)
#define MPU_9250_READ_SLV2_CTRL_I2C_SLV2_BYTE_SW(val)         MPU_9250_READ_SLV0_CTRL_I2C_SLV0_BYTE_SW(val)
#define MPU_9250_READ_SLV2_CTRL_I2C_SLV2_REG_DIS(val)         MPU_9250_READ_SLV0_CTRL_I2C_SLV0_REG_DIS(val)
#define MPU_9250_READ_SLV2_CTRL_I2C_SLV2_GRP(val)             MPU_9250_READ_SLV0_CTRL_I2C_SLV0_GRP(val)
#define MPU_9250_READ_SLV2_CTRL_I2C_SLV2_LENG(val)            MPU_9250_READ_SLV0_CTRL_I2C_SLV0_LENG(val)
#define MPU_9250_READ_SLV3_ADDR_I2C_SLV3_RNW(val)             MPU_9250_READ_SLV0_ADDR_I2C_SLV0_RNW(val)
#define MPU_9250_READ_SLV3_ADDR_I2C_ID_3(val)                 MPU_9250_READ_SLV0_ADDR_I2C_ID_0(val)
#define MPU_9250_READ_SLV3_REG(val)                           MPU_9250_READ_SLV0_REG(val)
#define MPU_9250_READ_SLV3_CTRL_I2C_SLV3_EN(val)              MPU_9250_READ_SLV0_CTRL_I2C_SLV0_EN(val)
#define MPU_9250_READ_SLV3_CTRL_I2C_SLV3_BYTE_SW(val)         MPU_9250_READ_SLV0_CTRL_I2C_SLV0_BYTE_SW(val)
#define MPU_9250_READ_SLV3_CTRL_I2C_SLV3_REG_DIS(val)         MPU_9250_READ_SLV0_CTRL_I2C_SLV0_REG_DIS(val)
#define MPU_9250_READ_SLV3_CTRL_I2C_SLV3_GRP(val)             MPU_9250_READ_SLV0_CTRL_I2C_SLV0_GRP(val)
#define MPU_9250_READ_SLV3_CTRL_I2C_SLV3_LENG(val)            MPU_9250_READ_SLV0_CTRL_I2C_SLV0_LENG(val)
#define MPU_9250_READ_SLV4_ADDR_I2C_SLV4_RNW(val)             MPU_9250_READ_SLV0_ADDR_I2C_SLV0_RNW(val)
#define MPU_9250_READ_SLV4_ADDR_I2C_ID_4(val)                 MPU_9250_READ_SLV0_ADDR_I2C_ID_0(val)
#define MPU_9250_READ_SLV4_REG(val)                           MPU_9250_READ_SLV0_REG(val)
#define MPU_9250_READ_SLV4_CTRL_I2C_SLV4_EN(val)              MPU_9250_READ_SLV0_CTRL_I2C_SLV0_EN(val)
#define MPU_9250_READ_SLV4_CTRL_I2C_SLV4_BYTE_SW(val)         MPU_9250_READ_SLV0_CTRL_I2C_SLV0_BYTE_SW(val)
#define MPU_9250_READ_SLV4_CTRL_I2C_SLV4_REG_DIS(val)         MPU_9250_READ_SLV0_CTRL_I2C_SLV0_REG_DIS(val)
#define MPU_9250_READ_SLV4_CTRL_I2C_SLV4_GRP(val)             MPU_9250_READ_SLV0_CTRL_I2C_SLV0_GRP(val)
#define MPU_9250_READ_SLV4_CTRL_I2C_SLV4_LENG(val)            MPU_9250_READ_SLV0_CTRL_I2C_SLV0_LENG(val)
#define MPU_9250_READ_INT_PIN_CFG_ACTL(val)                   ((uint8_t) ((val) & (0x01 << 7)))
#define MPU_9250_READ_INT_PIN_CFG_OPEN(val)                   ((uint8_t) ((val) & (0x01 << 6)))
#define MPU_9250_READ_INT_PIN_CFG_LATCH_INT_EN(val)           ((uint8_t) ((val) & (0x01 << 5)))
#define MPU_9250_READ_INT_PIN_CFG_INT_ANYRD_2CLEAR(val)       ((uint8_t) ((val) & (0x01 << 4)))
#define MPU_9250_READ_INT_PIN_CFG_ACTL_FSY_NC(val)            ((uint8_t) ((val) & (0x01 << 3)))
#define MPU_9250_READ_INT_PIN_CFG_FSYNC_INT_MODE_EN(val)      ((uint8_t) ((val) & (0x01 << 2)))
#define MPU_9250_READ_INT_PIN_CFG_BYPASS_EN(val)              ((uint8_t) ((val) & (0x01 << 1)))
#define MPU_9250_READ_INT_ENABLE_WOM_EN(val)                  ((uint8_t) ((val) & (0x01 << 6)))
#define MPU_9250_READ_INT_ENABLE_FIFO_OFLOW_EN(val)           ((uint8_t) ((val) & (0x01 << 4)))
#define MPU_9250_READ_INT_ENABLE_FSYNC_INT_EN(val)            ((uint8_t) ((val) & (0x01 << 3)))
#define MPU_9250_READ_INT_ENABLE_RAW_RDY_EN(val)              ((uint8_t) ((val) & (0x01 << 0)))
#define MPU_9250_READ_MST_DELAY_CTRL_DELAY_ES_SHADOW(val)     ((uint8_t) ((val) & (0x01 << 7)))
#define MPU_9250_READ_MST_DELAY_CTRL_I2C_SLV4_DLY_EN(val)     ((uint8_t) ((val) & (0x01 << 4)))
#define MPU_9250_READ_MST_DELAY_CTRL_I2C_SLV3_DLY_EN(val)     ((uint8_t) ((val) & (0x01 << 3)))
#define MPU_9250_READ_MST_DELAY_CTRL_I2C_SLV2_DLY_EN(val)     ((uint8_t) ((val) & (0x01 << 2)))
#define MPU_9250_READ_MST_DELAY_CTRL_I2C_SLV1_DLY_EN(val)     ((uint8_t) ((val) & (0x01 << 1)))
#define MPU_9250_READ_MST_DELAY_CTRL_I2C_SLV0_DLY_EN(val)     ((uint8_t) ((val) & (0x01 << 0)))
#define MPU_9250_READ_SIGNAL_PATH_RESET_GYRO_RESET(val)       ((uint8_t) ((val) & (0x01 << 2)))
#define MPU_9250_READ_SIGNAL_PATH_RESET_ACCEL_RESET(val)      ((uint8_t) ((val) & (0x01 << 1)))
#define MPU_9250_READ_SIGNAL_PATH_RESET_TEMP_RESET(val)       ((uint8_t) ((val) & (0x01 << 0)))
#define MPU_9250_READ_MOT_DETECT_CTRL_ACCEL_INT_EN(val)       ((uint8_t) ((val) & (0x01 << 7)))
#define MPU_9250_READ_MOT_DETECT_CTRL_ACCEL_INT_EL_MODE(val)  ((uint8_t) ((val) & (0x01 << 6)))
#define MPU_9250_READ_USER_CTRL_FIFO_EN(val)                  ((uint8_t) ((val) & (0x01 << 6)))
#define MPU_9250_READ_USER_CTRL_I2C_MST_EN(val)               ((uint8_t) ((val) & (0x01 << 5)))
#define MPU_9250_READ_USER_CTRL_I2C_IF_DIS(val)               ((uint8_t) ((val) & (0x01 << 4)))
#define MPU_9250_READ_USER_CTRL_FIFO_RST(val)                 ((uint8_t) ((val) & (0x01 << 2)))
#define MPU_9250_READ_USER_CTRL_I2C_MST_RST(val)              ((uint8_t) ((val) & (0x01 << 1)))
#define MPU_9250_READ_USER_CTRL_SIG_COND_RST(val)             ((uint8_t) ((val) & (0x01 << 0)))
#define MPU_9250_READ_PWD_MGMT_1_H_RESET(val)                 ((uint8_t) ((val) & (0x01 << 7)))
#define MPU_9250_READ_PWD_MGMT_1_SLEEP(val)                   ((uint8_t) ((val) & (0x01 << 6)))
#define MPU_9250_READ_PWD_MGMT_1_CYCLE(val)                   ((uint8_t) ((val) & (0x01 << 5)))
#define MPU_9250_READ_PWD_MGMT_1_GYRO_STANDBY(val)            ((uint8_t) ((val) & (0x01 << 4)))
#define MPU_9250_READ_PWD_MGMT_1_PD_PTAT(val)                 ((uint8_t) ((val) & (0x01 << 3)))
#define MPU_9250_READ_PWD_MGMT_1_CLKSEL(val)                  ((uint8_t) ((val) & (0x07 << 0)))
#define MPU_9250_READ_PWR_MGMT_2_DIS_XA(val)                  ((uint8_t) ((val) & (0x01 << 5)))
#define MPU_9250_READ_PWR_MGMT_2_DIS_YA(val)                  ((uint8_t) ((val) & (0x01 << 4)))
#define MPU_9250_READ_PWR_MGMT_2_DIS_ZA(val)                  ((uint8_t) ((val) & (0x01 << 3)))
#define MPU_9250_READ_PWR_MGMT_2_DIS_XG(val)                  ((uint8_t) ((val) & (0x01 << 2)))
#define MPU_9250_READ_PWR_MGMT_2_DIS_YG(val)                  ((uint8_t) ((val) & (0x01 << 1)))
#define MPU_9250_READ_PWR_MGMT_2_DIS_ZG(val)                  ((uint8_t) ((val) & (0x01 << 0)))
#define MPU_9250_READ_FIFO_COUNTH(val)                        ((uint8_t) ((val) & (0x1F << 0)))
#define MPU_9250_READ_FIFO_COUNTL(val)                        ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_FIFO_R_W(val)                           ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_XA_OFFSET_H(val)                        ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_XA_OFFSET_L(val)                        ((uint8_t) ((val) & (0x7F << 1)))
#define MPU_9250_READ_YA_OFFSET_H(val)                        ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_YA_OFFSET_L(val)                        ((uint8_t) ((val) & (0x7F << 1)))
#define MPU_9250_READ_ZA_OFFSET_H(val)                        ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_ZA_OFFSET_L(val)                        ((uint8_t) ((val) & (0x7F << 1)))
#define MPU_9250_READ_I2C_SLV4_DI(val)                        ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_I2C_MST_STATUS_PASS_THROUGH(val)        ((uint8_t) ((val) & (0x01 << 7)))
#define MPU_9250_READ_I2C_MST_STATUS_I2C_SLV4_DONE(val)       ((uint8_t) ((val) & (0x01 << 6)))
#define MPU_9250_READ_I2C_MST_STATUS_I2C_LOST_ARB(val)        ((uint8_t) ((val) & (0x01 << 5)))
#define MPU_9250_READ_I2C_MST_STATUS_I2C_SLV4_NACK(val)       ((uint8_t) ((val) & (0x01 << 4)))
#define MPU_9250_READ_I2C_MST_STATUS_I2C_SLV3_NACK(val)       ((uint8_t) ((val) & (0x01 << 3)))
#define MPU_9250_READ_I2C_MST_STATUS_I2C_SLV2_NACK(val)       ((uint8_t) ((val) & (0x01 << 2)))
#define MPU_9250_READ_I2C_MST_STATUS_I2C_SLV1_NACK(val)       ((uint8_t) ((val) & (0x01 << 1)))
#define MPU_9250_READ_I2C_MST_STATUS_I2C_SLV0_NACK(val)       ((uint8_t) ((val) & (0x01 << 0)))
#define MPU_9250_READ_INT_STATUS_WOM_INT(val)                 ((uint8_t) ((val) & (0x01 << 6)))
#define MPU_9250_READ_INT_STATUS_FIFO_OFLOW_INT(val)          ((uint8_t) ((val) & (0x01 << 4)))
#define MPU_9250_READ_INT_STATUS_FSYNC_INT(val)               ((uint8_t) ((val) & (0x01 << 3)))
#define MPU_9250_READ_INT_STATUS_RAW_DATA_RDY_INT(val)        ((uint8_t) ((val) & (0x01 << 0)))
#define MPU_9250_READ_ACCEL_X_OUT_H(val)                      ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_ACCEL_X_OUT_L(val)                      ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_ACCEL_Y_OUT_H(val)                      ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_ACCEL_Y_OUT_L(val)                      ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_ACCEL_Z_OUT_H(val)                      ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_ACCEL_Z_OUT_L(val)                      ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_TEMP_OUT_H(val)                         ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_TEMP_OUT_L(val)                         ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_GYRO_X_OUT_H(val)                       ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_GYRO_X_OUT_L(val)                       ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_GYRO_Y_OUT_H(val)                       ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_GYRO_Y_OUT_L(val)                       ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_GYRO_Z_OUT_H(val)                       ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_GYRO_Z_OUT_L(val)                       ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_00(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_01(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_02(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_03(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_04(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_05(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_06(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_07(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_08(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_09(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_10(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_11(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_12(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_13(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_14(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_15(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_16(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_17(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_18(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_19(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_20(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_21(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_22(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_EXT_SENS_DATA_23(val)                   ((uint8_t) ((val) & (0xFF << 0)))
#define MPU_9250_READ_WHO_AM_I(val)                           ((uint8_t) ((val) & (0xFF << 0)))


#define MPU_9250_WRITE_CONFIG(fifo_mode, ext_sync_set, dlpf_cfg)                                                           \
	  MPU_9250_WRITE_CONFIG_FIFO_MODE(fifo_mode)                                                                           \
	| MPU_9250_WRITE_CONFIG_EXT_SYNC_SET(ext_sync_set)                                                                     \
	| MPU_9250_WRITE_CONFIG_DLPF_CFG(dlpf_cfg)


#define MPU_9250_WRITE_GYRO_CONFIG(x_gyro_cten, y_gyro_cten, z_gyro_cten, fs_sel, choice_b)                                \
	  MPU_9250_WRITE_GYRO_CONFIG_X_GYRO_CTEN(x_gyro_cten)                                                                  \
	| MPU_9250_WRITE_GYRO_CONFIG_Y_GYRO_CTEN(y_gyro_cten)                                                                  \
	| MPU_9250_WRITE_GYRO_CONFIG_Z_GYRO_CTEN(z_gyro_cten)                                                                  \
	| MPU_9250_WRITE_GYRO_CONFIG_GYRO_FS_SEL(fs_sel)                                                                       \
	| MPU_9250_WRITE_GYRO_CONFIG_CHOICE_B(choice_b)


#define MPU_9250_WRITE_ACCEL_CONFIG_1(ax_st_en, ay_st_en, az_st_en, accel_fs_sel)                                          \
	  MPU_9250_WRITE_ACCEL_CONFIG_1_AX_ST_EN(ax_st_en)                                                                     \
	| MPU_9250_WRITE_ACCEL_CONFIG_1_AY_ST_EN(ay_st_en)                                                                     \
	| MPU_9250_WRITE_ACCEL_CONFIG_1_AZ_ST_EN(az_st_en)                                                                     \
	| MPU_9250_WRITE_ACCEL_CONFIG_1_ACCEL_FS_SEL(accel_fs_sel)


#define MPU_9250_WRITE_ACCEL_CONFIG_2(fchoice_b, a_dlpf_cfg)                                                               \
	  MPU_9250_WRITE_ACCEL_CONFIG_2_ACCEL_FCHOICE_B(fchoice_b)                                                             \
	| MPU_9250_WRITE_ACCEL_CONFIG_2_ACCEL_A_DLPF_CFG(a_dlpf_cfg)


#define MPU_9250_WRITE_FIFO_EN(temp_fifo_en, gyro_xo_ut, gyro_yo_ut, gyro_zo_ut, accel, slv2, slv1, slv0)                  \
	  MPU_9250_WRITE_FIFO_EN_TEMP_FIFO_EN(temp_fifo_en)                                                                    \
	| MPU_9250_WRITE_FIFO_EN_GYRO_XO_UT(gyro_xo_ut)                                                                        \
	| MPU_9250_WRITE_FIFO_EN_GYRO_YO_UT(gyro_yo_ut)                                                                        \
	| MPU_9250_WRITE_FIFO_EN_GYRO_ZO_UT(gyro_zo_ut)                                                                        \
	| MPU_9250_WRITE_FIFO_EN_ACCEL(accel)                                                                                  \
	| MPU_9250_WRITE_FIFO_EN_SLV2(slv2)                                                                                    \
	| MPU_9250_WRITE_FIFO_EN_SLV1(slv1)                                                                                    \
	| MPU_9250_WRITE_FIFO_EN_SLV0(slv0)


#define MPU_9250_WRITE_I2C_MST_CTRL(mult_mst_en, wait_for_es, slv3_fifo_en, i2c_mst_p_nsr, i2c_mst_clk)                    \
	  MPU_9250_WRITE_I2C_MST_CTRL_MULT_MST_EN(mult_mst_en)                                                                 \
	| MPU_9250_WRITE_I2C_MST_CTRL_WAIT_FOR_ES(wait_for_es)                                                                 \
	| MPU_9250_WRITE_I2C_MST_CTRL_SLV_3_FIFO_EN(slv3_fifo_en)                                                              \
	| MPU_9250_WRITE_I2C_MST_CTRL_I2C_MST_P_NSR(i2c_mst_p_nsr)                                                             \
	| MPU_9250_WRITE_I2C_MST_CTRL_I2C_MST_CLK(i2c_mst_clk)


#define MPU_9250_WRITE_SLV0_ADDR(i2c_slv0_rnw, i2c_id_0)                                                                   \
	  MPU_9250_WRITE_SLV0_ADDR_I2C_SLV0_RNW(i2c_slv0_rnw)                                                                  \
	| MPU_9250_WRITE_SLV0_ADDR_I2C_ID_0(i2c_id_0)


#define MPU_9250_WRITE_SLV0_CTRL(i2c_slv0_en, i2c_slv0_byte_sw, i2c_slv0_val_dis, i2c_slv0_grp, i2c_slv0_leng)             \
	  MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_EN(i2c_slv0_en)                                                                    \
	| MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_BYTE_SW(i2c_slv0_byte_sw)                                                          \
	| MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_REG_DIS(i2c_slv0_val_dis)                                                          \
	| MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_GRP(i2c_slv0_grp)                                                                  \
	| MPU_9250_WRITE_SLV0_CTRL_I2C_SLV0_LENG(i2c_slv0_leng)


#define MPU_9250_WRITE_SLV1_ADDR(i2c_slv1_rnw, i2c_id_1) MPU_9250_WRITE_SLV0_ADDR(i2c_slv1_rnw, i2c_id_1)
#define MPU_9250_WRITE_SLV2_ADDR(i2c_slv2_rnw, i2c_id_2) MPU_9250_WRITE_SLV0_ADDR(i2c_slv2_rnw, i2c_id_2)
#define MPU_9250_WRITE_SLV3_ADDR(i2c_slv3_rnw, i2c_id_3) MPU_9250_WRITE_SLV0_ADDR(i2c_slv3_rnw, i2c_id_3)
#define MPU_9250_WRITE_SLV4_ADDR(i2c_slv4_rnw, i2c_id_4) MPU_9250_WRITE_SLV0_ADDR(i2c_slv4_rnw, i2c_id_4)


#define MPU_9250_WRITE_SLV1_CTRL(i2c_slv1_en, i2c_slv1_byte_sw, i2c_slv1_val_dis, i2c_slv1_grp, i2c_slv1_leng)                    \
	MPU_9250_WRITE_SLV0_CTRL(i2c_slv1_en, i2c_slv1_byte_sw, i2c_slv1_val_dis, i2c_slv1_grp, i2c_slv1_leng)


#define MPU_9250_WRITE_SLV2_CTRL(i2c_slv2_en, i2c_slv2_byte_sw, i2c_slv2_val_dis, i2c_slv2_grp, i2c_slv2_leng)                    \
	MPU_9250_WRITE_SLV0_CTRL(i2c_slv1_en, i2c_slv2_byte_sw, i2c_slv2_val_dis, i2c_slv1_grp, i2c_slv1_leng)


#define MPU_9250_WRITE_SLV3_CTRL(i2c_slv3_en, i2c_slv3_byte_sw, i2c_slv3_val_dis, i2c_slv3_grp, i2c_slv3_leng)                    \
	MPU_9250_WRITE_SLV0_CTRL(i2c_slv1_en, i2c_slv1_byte_sw, i2c_slv3_val_dis, i2c_slv1_grp, i2c_slv1_leng)


#define MPU_9250_WRITE_SLV4_CTRL(i2c_slv4_en, i2c_slv4_byte_sw, i2c_slv4_val_dis, i2c_slv4_grp, i2c_slv4_leng)                    \
	MPU_9250_WRITE_SLV0_CTRL(i2c_slv1_en, i2c_slv1_byte_sw, i2c_slv4_val_dis, i2c_slv1_grp, i2c_slv1_leng)


#define MPU_9250_WRITE_INT_PIN_CFG(actl, open, latch_int_en, int_anyrd_2clear, actl_fsy_nc, fsync_int_mode_en, bypass_en)  \
	  MPU_9250_WRITE_INT_PIN_CFG_ACTL(actl)                                                                                \
	| MPU_9250_WRITE_INT_PIN_CFG_OPEN(open)                                                                                \
	| MPU_9250_WRITE_INT_PIN_CFG_LATCH_INT_EN(latch_int_en)                                                                \
	| MPU_9250_WRITE_INT_PIN_CFG_INT_ANYRD_2CLEAR(int_anyrd_2clear)                                                        \
	| MPU_9250_WRITE_INT_PIN_CFG_ACTL_FSY_NC(actl_fsy_nc)                                                                  \
	| MPU_9250_WRITE_INT_PIN_CFG_FSYNC_INT_MODE_EN(fsync_int_mode_en)                                                      \
	| MPU_9250_WRITE_INT_PIN_CFG_BYPASS_EN(bypass_en)


#define MPU_9250_WRITE_INT_ENABLE(wom_en, fifo_oflow_en, fsync_int_en, raw_rdy_en)                                         \
	  MPU_9250_WRITE_INT_ENABLE_WOM_EN(wom_en)                                                                       \
	| MPU_9250_WRITE_INT_ENABLE_FIFO_OFLOW_EN(fifo_oflow_en)                                                         \
	| MPU_9250_WRITE_INT_ENABLE_FSYNC_INT_EN(fsync_int_en)                                                           \
	| MPU_9250_WRITE_INT_ENABLE_RAW_RDY_EN(raw_rdy_en)


#define MPU_9250_WRITE_MST_DELAY_CTRL(i2c_slv4_dly_en, i2c_slv3_dly_en, i2c_slv2_dly_en, i2c_slv1_dly_en, i2c_slv0_dly_en) \
	  MPU_9250_WRITE_MST_DELAY_CTRL_I2C_SLV4_DLY_EN(i2c_slv4_dly_en)                                                 \
	| MPU_9250_WRITE_MST_DELAY_CTRL_I2C_SLV3_DLY_EN(i2c_slv3_dly_en)                                                 \
	| MPU_9250_WRITE_MST_DELAY_CTRL_I2C_SLV2_DLY_EN(i2c_slv2_dly_en)                                                 \
	| MPU_9250_WRITE_MST_DELAY_CTRL_I2C_SLV1_DLY_EN(i2c_slv1_dly_en)                                                 \
	| MPU_9250_WRITE_MST_DELAY_CTRL_I2C_SLV0_DLY_EN(i2c_slv0_dly_en)


#define MPU_9250_WRITE_SIGNAL_PATH_RESET(gyro_reset, accel_reset, temp_reset)                                              \
	  MPU_9250_WRITE_SIGNAL_PATH_RESET_GYRO_RESET(gyro_reset)                                                        \
	| MPU_9250_WRITE_SIGNAL_PATH_RESET_ACCEL_RESET(accel_reset)                                                      \
	| MPU_9250_WRITE_SIGNAL_PATH_RESET_TEMP_RESET(temp_reset)


#define MPU_9250_WRITE_MOT_DETECT_CTRL(accel_int_en, accel_int_el_mode)                                                    \
	  MPU_9250_WRITE_MOT_DETECT_CTRL_ACCEL_INT_EN(accel_int_en)                                                      \
	| MPU_9250_WRITE_MOT_DETECT_CTRL_ACCEL_INT_EL_MODE(accel_int_el_mode)


#define MPU_9250_WRITE_USER_CTRL(fifo_en, i2c_mst_en, i2c_if_dis, fifo_rst, i2c_mst_rst, sig_cond_rst)                     \
	  MPU_9250_WRITE_USER_CTRL_FIFO_EN(fifo_en)                                                                      \
	| MPU_9250_WRITE_USER_CTRL_I2C_MST_EN(i2c_mst_en)                                                                \
	| MPU_9250_WRITE_USER_CTRL_I2C_IF_DIS(i2c_if_dis)                                                                \
	| MPU_9250_WRITE_USER_CTRL_FIFO_RST(fifo_rst)                                                                    \
	| MPU_9250_WRITE_USER_CTRL_I2C_MST_RST(i2c_mst_rst)                                                              \
	| MPU_9250_WRITE_USER_CTRL_SIG_COND_RST(sig_cond_rst)


#define MPU_9250_WRITE_PWR_MGMT_1(h_reset, sleep, cycle, gyro_standby, pd_ptat, clksel)                                    \
	  MPU_9250_WRITE_PWR_MGMT_1_H_RESET(h_reset)                                                                     \
	| MPU_9250_WRITE_PWR_MGMT_1_SLEEP(sleep)                                                                         \
	| MPU_9250_WRITE_PWR_MGMT_1_CYCLE(cycle)                                                                         \
	| MPU_9250_WRITE_PWR_MGMT_1_GYRO_STANDBY(gyro_standby)                                                           \
	| MPU_9250_WRITE_PWR_MGMT_1_PD_PTAT(pd_ptat)                                                                     \
	| MPU_9250_WRITE_PWR_MGMT_1_CLKSEL(clksel)


#define MPU_9250_WRITE_PWR_MGMT_2(dis_xa, dis_ya, dis_za, dis_xg, dis_yg, dis_zg)                                          \
	  MPU_9250_WRITE_PWR_MGMT_2_DIS_XA(dis_xa)                                                                       \
	| MPU_9250_WRITE_PWR_MGMT_2_DIS_YA(dis_ya)                                                                       \
	| MPU_9250_WRITE_PWR_MGMT_2_DIS_ZA(dis_za)                                                                       \
	| MPU_9250_WRITE_PWR_MGMT_2_DIS_XG(dis_xg)                                                                       \
	| MPU_9250_WRITE_PWR_MGMT_2_DIS_YG(dis_yg)                                                                       \
	| MPU_9250_WRITE_PWR_MGMT_2_DIS_ZG(dis_zg)


typedef enum
{
	  MPU_9250_REG_SELF_TEST_X_GYRO   = 0x00
	, MPU_9250_REG_SELF_TEST_Y_GYRO   = 0x01
	, MPU_9250_REG_SELF_TEST_Z_GYRO   = 0x02
	, MPU_9250_REG_SELF_TEST_X_ACCEL  = 0x0D
	, MPU_9250_REG_SELF_TEST_Y_ACCEL  = 0x0E
	, MPU_9250_REG_SELF_TEST_Z_ACCEL  = 0x0F
	, MPU_9250_REG_XG_OFFSET_H        = 0x13
	, MPU_9250_REG_XG_OFFSET_L        = 0x14
	, MPU_9250_REG_YG_OFFSET_H        = 0x15
	, MPU_9250_REG_YG_OFFSET_L        = 0x16
	, MPU_9250_REG_ZG_OFFSET_H        = 0x17
	, MPU_9250_REG_ZG_OFFSET_L        = 0x18
	, MPU_9250_REG_SMPLRT_DIV         = 0x19
	, MPU_9250_REG_CONFIG             = 0x1A
	, MPU_9250_REG_GYRO_CONFIG        = 0x1B
	, MPU_9250_REG_ACCEL_CONFIG_1 	  = 0x1C
	, MPU_9250_REG_ACCEL_CONFIG_2 	  = 0x1D
	, MPU_9250_REG_LP_ACCEL_ODR       = 0x1E
	, MPU_9250_REG_WOM_THR            = 0x1F
	, MPU_9250_REG_FIFO_EN            = 0x23
	, MPU_9250_REG_I2C_MST_CTRL       = 0x24
	, MPU_9250_REG_I2C_SLV0_ADDR      = 0x25
	, MPU_9250_REG_I2C_SLV0_REG       = 0x26
	, MPU_9250_REG_I2C_SLV0_CTRL      = 0x27
	, MPU_9250_REG_I2C_SLV1_ADDR      = 0x28
	, MPU_9250_REG_I2C_SLV1_REG       = 0x29
	, MPU_9250_REG_I2C_SLV1_CTRL      = 0x2A
	, MPU_9250_REG_I2C_SLV2_ADDR      = 0x2B
	, MPU_9250_REG_I2C_SLV2_REG       = 0x2C
	, MPU_9250_REG_I2C_SLV2_CTRL      = 0x2D
	, MPU_9250_REG_I2C_SLV3_ADDR      = 0x2E
	, MPU_9250_REG_I2C_SLV3_REG       = 0x2F
	, MPU_9250_REG_I2C_SLV3_CTRL      = 0x30
	, MPU_9250_REG_I2C_SLV4_ADDR      = 0x31
	, MPU_9250_REG_I2C_SLV4_REG       = 0x32
	, MPU_9250_REG_I2C_SLV4_DO        = 0x33
	, MPU_9250_REG_I2C_SLV4_CTRL      = 0x34
	, MPU_9250_REG_I2C_SLV4_DI        = 0x35
	, MPU_9250_REG_I2C_MST_STATUS     = 0x36
	, MPU_9250_REG_I2C_PIN_CFG        = 0x37
	, MPU_9250_REG_INT_ENABLE         = 0x38
	, MPU_9250_REG_INT_STATUS         = 0x3A
	, MPU_9250_REG_ACCEL_XOUT_H       = 0x3B
	, MPU_9250_REG_ACCEL_XOUT_L       = 0x3C
	, MPU_9250_REG_ACCEL_YOUT_H       = 0x3D
	, MPU_9250_REG_ACCEL_YOUT_L       = 0x3E
	, MPU_9250_REG_ACCEL_ZOUT_H       = 0x3F
	, MPU_9250_REG_ACCEL_ZOUT_L       = 0x40
	, MPU_9250_REG_TEMP_OUT_H         = 0x41
	, MPU_9250_REG_TEMP_OUT_L         = 0x42
	, MPU_9250_REG_GYRO_XOUT_H        = 0x43
	, MPU_9250_REG_GYRO_XOUT_L        = 0x44
	, MPU_9250_REG_GYRO_YOUT_H        = 0x45
	, MPU_9250_REG_GYRO_YOUT_L        = 0x46
	, MPU_9250_REG_GYRO_ZOUT_H        = 0x47
	, MPU_9250_REG_GYRO_ZOUT_L        = 0x48
	, MPU_9250_REG_EXT_SENS_DATA_00   = 0x49
	, MPU_9250_REG_EXT_SENS_DATA_01   = 0x4A
	, MPU_9250_REG_EXT_SENS_DATA_02   = 0x4B
	, MPU_9250_REG_EXT_SENS_DATA_03   = 0x4C
	, MPU_9250_REG_EXT_SENS_DATA_04   = 0x4D
	, MPU_9250_REG_EXT_SENS_DATA_05   = 0x4E
	, MPU_9250_REG_EXT_SENS_DATA_06   = 0x4F
	, MPU_9250_REG_EXT_SENS_DATA_07   = 0x50
	, MPU_9250_REG_EXT_SENS_DATA_08   = 0x51
	, MPU_9250_REG_EXT_SENS_DATA_09   = 0x52
	, MPU_9250_REG_EXT_SENS_DATA_10   = 0x53
	, MPU_9250_REG_EXT_SENS_DATA_11   = 0x54
	, MPU_9250_REG_EXT_SENS_DATA_12   = 0x55
	, MPU_9250_REG_EXT_SENS_DATA_13   = 0x56
	, MPU_9250_REG_EXT_SENS_DATA_14   = 0x57
	, MPU_9250_REG_EXT_SENS_DATA_15   = 0x58
	, MPU_9250_REG_EXT_SENS_DATA_16   = 0x59
	, MPU_9250_REG_EXT_SENS_DATA_17   = 0x5A
	, MPU_9250_REG_EXT_SENS_DATA_18   = 0x5B
	, MPU_9250_REG_EXT_SENS_DATA_19   = 0x5C
	, MPU_9250_REG_EXT_SENS_DATA_20   = 0x5D
	, MPU_9250_REG_EXT_SENS_DATA_21   = 0x5E
	, MPU_9250_REG_EXT_SENS_DATA_22   = 0x5F
	, MPU_9250_REG_EXT_SENS_DATA_23   = 0x60
	, MPU_9250_REG_I2C_SLV0_DO        = 0x63
	, MPU_9250_REG_I2C_SLV1_DO        = 0x64
	, MPU_9250_REG_I2C_SLV2_DO        = 0x65
	, MPU_9250_REG_I2C_SLV3_DO        = 0x66
	, MPU_9250_REG_I2C_MST_DELAY_CTRL = 0x67
	, MPU_9250_REG_SIGNAL_PATH_RESET  = 0x68
	, MPU_9250_REG_MOT_DETECT_CTRL    = 0x69
	, MPU_9250_REG_USER_CTRL          = 0x6A
	, MPU_9250_REG_PWR_MGMT_1         = 0x6B
	, MPU_9250_REG_PWR_MGMT_2         = 0x6C
	, MPU_9250_REG_FIFO_COUNT_H       = 0x72
	, MPU_9250_REG_FIFO_COUNT_L       = 0x73
	, MPU_9250_REG_FIFO_R_W           = 0x74
	, MPU_9250_REG_WMO_AMI_I          = 0x75
	, MPU_9250_REG_XA_OFFSET_H        = 0x77
	, MPU_9250_REG_XA_OFFSET_L        = 0x78
	, MPU_9250_REG_YA_OFFSET_H        = 0x7A
	, MPU_9250_REG_YA_OFFSET_L        = 0x7B
	, MPU_9250_REG_ZA_OFFSET_H        = 0x7D
	, MPU_9250_REG_ZA_OFFSET_L        = 0x7E
} MPU_9250_Register;


int mpu_9250_open_device(
      int* fd
    , const char* device_path
    , const size_t mpu_9250_ad_pin
    ) __attribute__((warn_unused_result)) ;


int mpu_9250_raw_read(
      uint8_t* data
    , const int fd
    , const size_t len
    ) __attribute__((warn_unused_result)) ;


int mpu_9250_raw_write(
      const int fd
    , const uint8_t* data
    , const size_t len
    ) __attribute__((warn_unused_result)) ;


float mpu_9250_get_accel_conversion_factor(
    const uint8_t accel_data_rate
    ) __attribute__((warn_unused_result)) ;


float mpu_9250_get_gyro_conversion_factor(
    const uint8_t gyro_data_rate
    ) __attribute__((warn_unused_result)) ;


#ifdef __cplusplus
}
#endif
#endif // __MPU_9250_H__

