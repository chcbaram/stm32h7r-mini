#include "ap.h"



void ledISR(void *arg)
{
  ledToggle(_DEF_LED1);
}

void apInit(void)
{
  cliOpen(HW_UART_CH_CLI, 115200);  
  cliBegin();    

  swtimer_handle_t timer_ch;
  timer_ch = swtimerGetHandle();
  if (timer_ch >= 0)
  {
    swtimerSet(timer_ch, 500, LOOP_TIME, ledISR, NULL);
    swtimerStart(timer_ch);  
  }  
}

void apMain(void)
{
  uint32_t pre_time;

  pre_time = millis();
  while(1)
  {
    if (millis()-pre_time >= 500)
    {
      pre_time = millis();
      // ledToggle(_DEF_LED1);
    }

    cliMain();
  }
}
