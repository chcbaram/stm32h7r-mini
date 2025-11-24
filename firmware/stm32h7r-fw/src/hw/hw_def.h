#ifndef HW_DEF_H_
#define HW_DEF_H_



#include "bsp.h"


#define _DEF_FIRMWATRE_VERSION    "V251122R1"
#define _DEF_BOARD_NAME           "STM32H7R-FW"


#define _USE_HW_ASSERT
#define _USE_HW_FAULT
#define _USE_HW_SD


#define _USE_HW_LED
#define      HW_LED_MAX_CH          1

#define _USE_HW_UART
#define      HW_UART_MAX_CH         1
#define      HW_UART_CH_SWD         _DEF_UART1
#define      HW_UART_CH_CLI         HW_UART_CH_SWD

#define _USE_HW_CLI
#define      HW_CLI_CMD_LIST_MAX    32
#define      HW_CLI_CMD_NAME_MAX    16
#define      HW_CLI_LINE_HIS_MAX    8
#define      HW_CLI_LINE_BUF_MAX    64

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

#define _USE_HW_GPIO
#define      HW_GPIO_MAX_CH         GPIO_PIN_MAX

#define _USE_HW_SPI
#define      HW_SPI_MAX_CH          SPI_PIN_MAX

#define _USE_HW_SPI_FLASH
#define      HW_SPI_FLASH_ADDR      0x91000000

#define _USE_HW_SWTIMER
#define      HW_SWTIMER_MAX_CH      8

#define _USE_HW_BUTTON
#define      HW_BUTTON_MAX_CH       BUTTON_PIN_MAX


//-- CLI
//
#define _USE_CLI_HW_UART            1
#define _USE_CLI_HW_LOG             1
#define _USE_CLI_HW_ASSERT          1
#define _USE_CLI_HW_RTC             1
#define _USE_CLI_HW_RESET           1
#define _USE_CLI_HW_QSPI            1
#define _USE_CLI_HW_GPIO            1
#define _USE_CLI_HW_SPI_FLASH       1
#define _USE_CLI_HW_BUTTON          1
#define _USE_CLI_HW_SD              1

typedef enum
{
  UART_PIN_USART1,
} UartPinName_t;

typedef enum
{
  FLASH_SPI_CS,
  SD_DETECT,
  GPIO_PIN_MAX
} GpioPinName_t;

typedef enum
{
  SPI_CH_FLASH,
  SPI_PIN_MAX,
} SpiPinName_t;

typedef enum
{
  BTN_CH1,
  BUTTON_PIN_MAX,
} ButtonPinName_t;

#endif
