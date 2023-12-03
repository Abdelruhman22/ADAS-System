/***************************************************************/
/*Layer:  Service                                              */
/*Author: ADAS Team                                            */
/***************************************************************/


#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H

/* Register Definitions *************************/
typedef struct{
	volatile u32_t RCC_CR;
	volatile u32_t RCC_CFGR;
	volatile u32_t RCC_CIR;
	volatile u32_t RCC_APB2RSTR;
	volatile u32_t RCC_APB1RSTR;
	volatile u32_t RCC_AHBENR;
	volatile u32_t RCC_APB2ENR;
	volatile u32_t RCC_APB1ENR;
	volatile u32_t RCC_BDCR;
	volatile u32_t RCC_CSR;
}RCC_Registers_t;


#define RCC ((volatile RCC_Registers_t*)0x40021000)



#endif		
