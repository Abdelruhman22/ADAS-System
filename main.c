#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_Interface.h"
#include "RCC_Interface.h"
#include "NVIC_Interface.h"
#include "SYSTICK_Interface.h"


void SYSTICK_TIMEOUT(void){
	MCAL_NVIC_Void_SetPendigFlag(6);
}
int main()
{
	MCAL_RCC_void_InitSysClock();
	MCAL_RCC_void_EnableClock(RCC_APB2 , 2);
	MCAL_RCC_void_EnableClock(RCC_APB2 , 3);
	MCAL_RCC_void_EnableClock(RCC_APB2 , 4);
	MCAL_GPIO_void_SetPinDirection(GPIO_A ,GPIO_PIN0 ,OUTPUT_PP_SPEED_2MHZ);
	//***************TEST For USART*************************************************
	//SET PA9 as AF(Tx) for USART1
	MCAL_GPIO_void_SetPinDirection(GPIO_A ,GPIO_PIN9 ,OUTPUT_AFPP_SPEED_2MHZ);
	//SET PA10 as INPUT FLOATING(Rx) for USART1
	MCAL_GPIO_void_SetPinDirection(GPIO_A ,GPIO_PIN10 ,INPUT_FLOATING);
	//***************TEST For USART*************************************************
	MCAL_NVIC_Void_EnableInterrupt(6);
	MCAL_SYSTICK_Void_Init();
	MCAL_SYSTICK_Void_SetIntervalPeriodic(5000000 ,&SYSTICK_TIMEOUT);

  while (1)
    {

    }
}

void EXTI0_IRQHandler(void){
	MCAL_GPIO_void_TogglePin(GPIO_A ,GPIO_PIN0);
}
