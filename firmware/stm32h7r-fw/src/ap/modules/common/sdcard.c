#include "ap_def.h"



static bool init(void);
static void update(void);


MODULE_DEF(sdcard) 
{
  .name = "sdcard",
  .priority = MODULE_PRI_NORMAL,
  .init = init,
  .update = update
};



bool init(void)
{
  return true;
}

void update(void)
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


