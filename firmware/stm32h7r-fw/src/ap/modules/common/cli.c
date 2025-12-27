#include "ap_def.h"



static bool init(void);
static void update(void);


MODULE_DEF(cli) 
{
  .name = "cli",
  .priority = MODULE_PRI_LOW,
  .init = init,
  .update = update
};



bool init(void)
{
  bool ret;

  ret = cliOpen(HW_UART_CH_CLI, 115200);  
  return ret;
}

void update(void)
{
  static bool is_first = true;

  if (is_first)
  {
    is_first = false;
    cliBegin(); 
  }

  cliMain();
}


