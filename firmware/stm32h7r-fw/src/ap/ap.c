#include "ap.h"



void updateSD(void);


static bool is_init = false;



void apInit(void)
{

  moduleInit();

  is_init = true;
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
      ledToggle(_DEF_LED1);
    }
    usbUpdate();

    moduleUpdate();
  }
}

void cliLoopIdle(void)
{
  if (is_init)
  {
    usbUpdate();
  }
}

