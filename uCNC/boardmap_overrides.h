#ifndef BOADMAP_OVERRIDES_H
#define BOADMAP_OVERRIDES_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "boardmap_reset.h"
#define MCU MCU_STM32F1X
#define BOARD "src/hal/boards/stm32/boardmap_bluepill.h"
#define KINEMATIC KINEMATIC_CARTESIAN
#define AXIS_COUNT 5
#define BAUDRATE 115200
#define BOARD_NAME "'TrapDoor5Motor'"
#define ITP_TIMER 2
#define SERVO_TIMER 3
#define ONESHOT_TIMER 1
#define IC74HC595_COUNT 0
#define IC74HC165_COUNT 0
#define STEP0_BIT 14
#define STEP0_PORT B
#define STEP1_BIT 10
#define STEP1_PORT A
#define STEP2_BIT 5
#define STEP2_PORT B
#define STEP3_BIT 9
#define STEP3_PORT A
#define STEP4_BIT 3
#define STEP4_PORT A
#define DIR0_BIT 13
#define DIR0_PORT B
#define DIR1_BIT 9
#define DIR1_PORT A
#define DIR2_BIT 4
#define DIR2_PORT B
#define DIR3_BIT 8
#define DIR3_PORT A
#define DIR4_BIT 2
#define DIR4_PORT A
#define STEP0_EN_BIT 12
#define STEP0_EN_PORT B
#define STEP1_EN_BIT 8
#define STEP1_EN_PORT A
#define STEP2_EN_BIT 3
#define STEP2_EN_PORT B
#define STEP3_EN_BIT 7
#define STEP3_EN_PORT A
#define STEP4_EN_BIT 1
#define STEP4_EN_PORT A
#define LIMIT_X_BIT 15
#define LIMIT_X_PORT B
#define LIMIT_X_PULLUP
#define LIMIT_X_ISR
#define LIMIT_Y_BIT 15
#define LIMIT_Y_PORT A
#define LIMIT_Y_PULLUP
#define LIMIT_Y_ISR
#define LIMIT_Z_BIT 6
#define LIMIT_Z_PORT B
#define LIMIT_Z_PULLUP
#define LIMIT_Z_ISR
#define LIMIT_A_BIT 4
#define LIMIT_A_PORT A
#define LIMIT_A_PULLUP
#define LIMIT_A_ISR
#define LIMIT_B_BIT 0
#define LIMIT_B_PORT A
#define LIMIT_B_PULLUP
#define LIMIT_B_ISR
#define ESTOP_BIT 5
#define ESTOP_PORT A
#define ESTOP_PULLUP
#define ESTOP_ISR
#define ANALOG0_CHANNEL -1
#define ANALOG1_CHANNEL -1
#define ANALOG2_CHANNEL -1
#define ANALOG3_CHANNEL -1
#define ANALOG4_CHANNEL -1
#define ANALOG5_CHANNEL -1
#define ANALOG6_CHANNEL -1
#define ANALOG7_CHANNEL -1
#define ANALOG8_CHANNEL -1
#define ANALOG9_CHANNEL -1
#define ANALOG10_CHANNEL -1
#define ANALOG11_CHANNEL -1
#define ANALOG12_CHANNEL -1
#define ANALOG13_CHANNEL -1
#define ANALOG14_CHANNEL -1
#define ANALOG15_CHANNEL -1
#define USB_DM_BIT 11
#define USB_DM_PORT A
#define USB_DP_BIT 12
#define USB_DP_PORT A
#define TOOL_COUNT 0
//Custom configurations
#define BOARDMAP_BLUEPILL_H true


#ifdef __cplusplus
}
#endif
#endif
