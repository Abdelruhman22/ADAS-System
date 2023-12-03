#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

/***********************************
-----------CRYSTAL OPTIONS----------
************************************
1) RCC_HSE_CRYSTAL
2) RCC_HSE_RC 
3) RCC_HSI 
4) RCC_PLL
************************************/
#define RCC_CLOCK_TYPE	RCC_HSI


/*********************************************************
*PLL INPUT CLK SOURCE OPTIONS                            *
note:Use only if you have RCC_PLL as (CRYSTAL OPTIONS)   *
**********************************************************
1) RCC_PLL_IN_HSI_DIV_2
2) RCC_PLL_IN_HSE_DIV_2 
3) RCC_PLL_IN_HSE
*********************************************************/
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT_SOURCE 	RCC_PLL_IN_HSI_DIV_2
#define RCC_PLL_MUL_VALUE   4
#endif


#endif
