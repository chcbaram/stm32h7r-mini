#include "hw_def.h"




#ifdef _USE_HW_ASSERT
#include "log.h"



void assert_failed(uint8_t* file, uint32_t line)
{
  char *name_buf;

  if (strrchr((char *) file,'/') == NULL) 
  {
    name_buf = strrchr((char *)file,'\\')+1;
  }
  else 
  {
    name_buf = strrchr((char *)file,'/')+1;
  }

  if (logIsOpen())
  {
    logPrintf("assert found\n");
    logPrintf("     - file : %s\n", name_buf);
    logPrintf("     - line : %d\n", line);
  }

  if (CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk)  
  { 
    __BKPT(0);
  }   
}

void __assert_func(const char *file, int line, const char *func, const char *expr)
{  
  char *name_buf;

  if (strrchr((char *) file,'/') == NULL) 
  {
    name_buf = strrchr((char *)file,'\\')+1;
  }
  else 
  {
    name_buf = strrchr((char *)file,'/')+1;
  }

  if (logIsOpen())
  {
    logPrintf("assert found\n");
    logPrintf("     - file : %s\n", name_buf);
    logPrintf("     - func : %s\n", func);
    logPrintf("     - line : %d\n", line);
    logPrintf("     - expr : (%s)\n", expr);
  }

  if (CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk)  
  { 
    __BKPT(0);
  }   
  while(1);
}

#endif