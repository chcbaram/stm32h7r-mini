#ifndef HW_DEF_H_
#define HW_DEF_H_



#include "bsp.h"


#define _DEF_FIRMWATRE_VERSION    "V251129R1"
#define _DEF_BOARD_NAME           "STM32H7R-FSBL"


#define _USE_HW_ASSERT
#define _USE_HW_FAULT
#define _USE_HW_FLASH


#define _USE_HW_LED
#define      HW_LED_MAX_CH          1

#define _USE_HW_UART
#define      HW_UART_MAX_CH         UART_PIN_MAX
#define      HW_UART_CH_SWD         _DEF_UART1
#define      HW_UART_CH_CLI         HW_UART_CH_SWD

#define _USE_HW_LOG
#define      HW_LOG_CH              _DEF_UART1
#define      HW_LOG_BOOT_BUF_MAX    (4 * 1024)
#define      HW_LOG_LIST_BUF_MAX    (8 * 1024)

#define _USE_HW_RTC
#define      HW_RTC_BOOT_MODE       RTC_BKP_DR3
#define      HW_RTC_RESET_BITS      RTC_BKP_DR4

#define _USE_HW_RESET
#define      HW_RESET_BOOT          1

#define _USE_HW_QSPI
#define      HW_QSPI_BASE_ADDR      0x90000000


#define FLASH_SIZE_TAG              0x400
#define FLASH_SIZE_VEC              0x400
#define FLASH_SIZE_VER              0x400
#define FLASH_SIZE_BOOT             ( 256*1024)

#define FLASH_ADDR_BOOT             0x90000000

#define SRAM_ADDR_BOOT              0x24020000



//-- CLI
//
#define _USE_CLI_HW_UART            1
#define _USE_CLI_HW_LOG             1
#define _USE_CLI_HW_ASSERT          1
#define _USE_CLI_HW_RTC             1
#define _USE_CLI_HW_RESET           1
#define _USE_CLI_HW_QSPI            1


typedef enum
{
  UART_PIN_USART1,
  UART_PIN_MAX
} UartPinName_t;

#endif
