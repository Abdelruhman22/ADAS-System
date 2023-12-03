#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H

typedef struct{
	//For stm32f103c8
	volatile u32_t Register_0;
	volatile u32_t Register_1;
	//For other families
	volatile u32_t Register_2;
	volatile u32_t Register_3;
	volatile u32_t Register_4;
	volatile u32_t Register_5;
	volatile u32_t Register_6;
	volatile u32_t Register_7;
	//Reserved Memory
	volatile u32_t Register_8;
	volatile u32_t Register_9;
	volatile u32_t Register_10;
	volatile u32_t Register_11;
	volatile u32_t Register_12;
	volatile u32_t Register_13;
	volatile u32_t Register_14;
	volatile u32_t Register_15;
	volatile u32_t Register_16;
	volatile u32_t Register_17;
	volatile u32_t Register_18;
	volatile u32_t Register_19;
	volatile u32_t Register_20;
	volatile u32_t Register_21;
	volatile u32_t Register_22;
	volatile u32_t Register_23;
	volatile u32_t Register_24;
	volatile u32_t Register_25;
	volatile u32_t Register_26;
	volatile u32_t Register_27;
	volatile u32_t Register_28;
	volatile u32_t Register_29;
	volatile u32_t Register_30;
	volatile u32_t Register_31;
}NVIC_RegisterX_t;

typedef struct{
	NVIC_RegisterX_t NVIC_ISERx;
	NVIC_RegisterX_t NVIC_ICERx;
	NVIC_RegisterX_t NVIC_ISPRx;
	NVIC_RegisterX_t NVIC_ICPRx;
	NVIC_RegisterX_t NVIC_IABR0x;
	NVIC_RegisterX_t NVIC_IABR1x;
}NVIC_Registers_t;

#define NVIC ((volatile NVIC_Registers_t*)0xE000E100)
#define NVIC_IPRx  ((volatile u8_t*)0xE000E400)
#define SCB_AIRCR *((volatile u32_t*)0xE000ED0C)

#endif
