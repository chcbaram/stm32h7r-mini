#include "ap.h"



void updateSD(void);



void apInit(void)
{
  cliOpen(HW_UART_CH_CLI, 115200);  
  cliBegin();    
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
    updateSD();
  }
}

void updateSD(void)
{
  sd_state_t sd_state;


  sd_state = sdUpdate();
  if (sd_state == SDCARD_CONNECTED)
  {
    logPrintf("\n[  ] SDCARD_CONNECTED\n");
  }
  if (sd_state == SDCARD_DISCONNECTED)
  {
    logPrintf("\n[  ] SDCARD_DISCONNECTED\n");
  }
}