#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SYSTICK_Config.h"
#include "SYSTICK_Interface.h"
#include "SYSTICK_Private.h"

static void(*SYSTICK_CALLBACK)(void);
static u8_t SYSTICK_ModeOfInterval;

void MCAL_SYSTICK_Void_Init(void){
	if(STK_CLK_SRC == STK_SRC_AHB){
		/*Enable STK Interrupt - Set clock source AHB */
		SYSTICK->SYSTICK_CTRL = 0x00000006;
	}
	else if(STK_CLK_SRC == STK_SRC_AHB_8){
		/* Disable STK - Enable STK Interrupt - Set clock source AHB/8 */
		SYSTICK->SYSTICK_CTRL = 0x00000002;
	}
}

void MCAL_SYSTICK_Void_BusyWait(u32_t Ticks ){
	/* Load ticks to load register */
	SYSTICK->SYSTICK_LOAD = Ticks;
	/* Start Timer */
	SET_BIT(SYSTICK->SYSTICK_CTRL, EN);
	/* Wait till flag is raised */
	while( (GET_BIT(SYSTICK->SYSTICK_CTRL,COUNTFLAG)) == 0);
	/* Stop Timer */
	CLEAR_BIT(SYSTICK->SYSTICK_CTRL, EN);
	SYSTICK->SYSTICK_LOAD = 0;
	SYSTICK->SYSTICK_VAL  = 0;

}

void MCAL_SYSTICK_Void_SetIntervalSingle  (u32_t Ticks, void (*F_ptr)(void) ){
	/* Load ticks to load register */
	SYSTICK->SYSTICK_LOAD = Ticks;
	/* Start Timer */
	SET_BIT(SYSTICK->SYSTICK_CTRL, EN);
	/* Save CallBack */
	SYSTICK_CALLBACK = F_ptr;
	/* Set Mode to Single */
	SYSTICK_ModeOfInterval = STK_SINGLE_INTERVAL;
}
void MCAL_SYSTICK_Void_SetIntervalPeriodic(u32_t Ticks, void (*F_ptr)(void) ){
	/* Load ticks to load register */
	SYSTICK->SYSTICK_LOAD = Ticks;
	/* Start Timer */
	SET_BIT(SYSTICK->SYSTICK_CTRL, EN);
	/* Save CallBack */
	SYSTICK_CALLBACK = F_ptr;
	/* Set Mode to Single */
	SYSTICK_ModeOfInterval = STK_PERIOD_INTERVAL;
}
void MCAL_SYSTICK_Void_StopInterval(void){
	/* Stop Timer */
	CLEAR_BIT(SYSTICK->SYSTICK_CTRL, EN);
	SYSTICK->SYSTICK_LOAD = 0;
	SYSTICK->SYSTICK_VAL  = 0;
}
void MCAL_SYSTICK_Void_GetElapsedTime_ms(u32_t* Value){
	*Value = SYSTICK->SYSTICK_LOAD - SYSTICK->SYSTICK_VAL;
}
void MCAL_SYSTICK_Void_GetRemainingTime_ms(u32_t* Value){
	*Value = SYSTICK->SYSTICK_VAL;
}

void SysTick_Handler(void)
{
	 u8_t Local_Flag_Clear=0;

	if (SYSTICK_ModeOfInterval == STK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLEAR_BIT(SYSTICK->SYSTICK_CTRL, TICKINT);
		/* Stop Timer */
		CLEAR_BIT(SYSTICK->SYSTICK_CTRL,EN);
		SYSTICK->SYSTICK_LOAD = 0;
		SYSTICK->SYSTICK_VAL  = 0;
	}
	/* Callback notification */
	SYSTICK_CALLBACK();
	/* Clear interrupt flag */
	Local_Flag_Clear = GET_BIT(SYSTICK->SYSTICK_CTRL,COUNTFLAG);
}


