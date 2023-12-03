#ifndef _SYSTICK_INTERFACE_H
#define _SYSTICK_INTERFACE_H


void MCAL_SYSTICK_Void_Init(void);
void MCAL_SYSTICK_Void_BusyWait(u32_t Ticks );
void MCAL_SYSTICK_Void_SetIntervalSingle  (u32_t Ticks, void (*F_ptr)(void) );
void MCAL_SYSTICK_Void_SetIntervalPeriodic(u32_t Ticks, void (*F_ptr)(void) );
void MCAL_SYSTICK_Void_StopInterval(void);
void MCAL_SYSTICK_Void_GetElapsedTime_ms(u32_t* Value);
void MCAL_SYSTICK_Void_GetRemainingTime_ms(u32_t* Value);

typedef enum{STK_SRC_AHB , STK_SRC_AHB_8}STK_CLK_SRC_OPTIONS;
typedef enum{STK_SINGLE_INTERVAL , STK_PERIOD_INTERVAL}STK_PERIODICITY_OPTIONS;

typedef enum{EN,TICKINT,CLKSOURCE,Re0,Re1,Re2,Re3,Re4,Re5,Re6,Re7,Re8,Re9,Re10,Re11,Re12,COUNTFLAG}SYSTICK_CTRL_BITS_t;

	#endif
