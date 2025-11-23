#ifndef HW_H_
#define HW_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "hw_def.h"


#include "led.h"
#include "uart.h"
#include "cli.h"
#include "log.h"
#include "fault.h"
#include "swtimer.h"
#include "reset.h"
#include "rtc.h"
#include "qbuffer.h"
#include "qspi.h"
#include "gpio.h"
#include "spi.h"
#include "spi_flash.h"
#include "fault.h"

bool hwInit(void);


#ifdef __cplusplus
}
#endif

#endif