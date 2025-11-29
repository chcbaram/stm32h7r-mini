#include "main.h"


/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{

  /* Configure the system Power Supply */

  if (HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY) != HAL_OK)
  {
    /* Initialization error */
    Error_Handler();
  }

  /* Enable the XSPIM_P1 interface */
  HAL_PWREx_EnableXSPIM1();
}
