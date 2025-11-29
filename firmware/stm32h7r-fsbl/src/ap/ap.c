#include "ap.h"


#define USE_JUMP_TO_SRAM      0


static void bootUp(void);
static void jumpToBoot(void);



void apInit(void)
{
  bootUp();  
}

void apMain(void)
{
  uint32_t pre_time;

  pre_time = millis();
  while(1)
  {
    if (millis()-pre_time >= 50)
    {
      pre_time = millis();
      ledToggle(_DEF_LED1);
    }
  }
}

void bootUp(void)
{
  jumpToBoot();  
}

#if USE_JUMP_TO_SRAM
void jumpToBoot(void)
{
  void (**jump_func)(void);  


  logPrintf("[  ] Jump To Boot (SRAM)\n");  

  if (!flashRead(FLASH_ADDR_BOOT, (uint8_t *)SRAM_ADDR_BOOT, FLASH_SIZE_BOOT))
  {
    logPrintf("[E_] flashRead()\n");
    return;
  }

  jump_func = (void (**)(void))(SRAM_ADDR_BOOT + 4); 

  if (((uint32_t)*jump_func) >= SRAM_ADDR_BOOT && ((uint32_t)*jump_func) < (SRAM_ADDR_BOOT + FLASH_SIZE_BOOT))
  {  
    logPrintf("[OK] addr : 0x%X\n", (uint32_t)*jump_func);
    bspDeInit();

    (*jump_func)();
  }
  else
  {
    logPrintf("[E_] Invalid Jump Address\n");
  }  
}
#else
void jumpToBoot(void)
{
  void (**jump_func)(void);


  logPrintf("[  ] Jump To Boot (FLASH)\n");


  qspiSetXipMode(true);
  logPrintf("[  ] XiP Mode\n");

  jump_func = (void (**)(void))(FLASH_ADDR_BOOT + 4); 

  if (((uint32_t)*jump_func) >= FLASH_ADDR_BOOT && ((uint32_t)*jump_func) < (FLASH_ADDR_BOOT + FLASH_SIZE_BOOT))
  {  
    logPrintf("[OK] addr : 0x%X\n", (uint32_t)*jump_func);
    bspDeInit();

    (*jump_func)();
  }
  else
  {
    logPrintf("[E_] Invalid Jump Address\n");
  }  
}
#endif