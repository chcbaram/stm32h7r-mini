#ifndef HW_DEF_H_
#define HW_DEF_H_



#include "bsp.h"
#include "assert_def.h"


#define _DEF_FIRMWATRE_VERSION    "V251122R1"
#define _DEF_BOARD_NAME           "STM32H7R-FW"


#define _USE_HW_ASSERT



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


//-- CLI
//
#define _USE_CLI_HW_UART            1


typedef enum
{
  UART_PIN_USART1,
} UartPinName_t;

#endif
