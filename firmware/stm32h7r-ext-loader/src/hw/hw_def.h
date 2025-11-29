#ifndef HW_DEF_H_
#define HW_DEF_H_



#include "bsp.h"


#define _DEF_FIRMWATRE_VERSION    "V251129R1"
#define _DEF_BOARD_NAME           "STM32HR-MINI-EXT-LOADER"


#define _USE_HW_FLASH

#define _USE_HW_LED
#define      HW_LED_MAX_CH          1

#define _USE_HW_QSPI
#define      HW_QSPI_BASE_ADDR      0x90000000


#endif
