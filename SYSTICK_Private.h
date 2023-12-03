#ifndef _SYSTICK_PRIVATE_H
#define _SYSTICK_PRIVATE_H

typedef struct
{
	volatile u32_t SYSTICK_CTRL;
	volatile u32_t SYSTICK_LOAD;
	volatile u32_t SYSTICK_VAL;
}SYSTICK_Rigisters_t;

#define     SYSTICK    ((SYSTICK_Rigisters_t*)0xE000E010)

#endif
