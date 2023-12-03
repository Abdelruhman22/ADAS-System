#include <BIT_MATH.h>
#include "GPIO_Config.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include <STD_TYPES.h>

void MCAL_GPIO_void_SetPinDirection(u8_t Port_ID , u8_t Pin_ID , u8_t OperationMode){
	switch(Port_ID){
		case GPIO_A:
			if(Pin_ID <= 7){
				GPIO->GPIOx[GPIO_A].GPIO_CRL &=~ ((0b1111) << (Pin_ID *4));
				GPIO->GPIOx[GPIO_A].GPIO_CRL |=  ((OperationMode) << (Pin_ID *4));
			}
			else if(Pin_ID <= 15){
				Pin_ID -= 8;
				GPIO->GPIOx[GPIO_A].GPIO_CRH &=~ ((0b1111) << (Pin_ID *4));
				GPIO->GPIOx[GPIO_A].GPIO_CRH |=  ((OperationMode) << (Pin_ID *4));
			}
			break;
		case GPIO_B:
			if(Pin_ID <= 7){
				GPIO->GPIOx[GPIO_B].GPIO_CRL &=~ ((0b1111) << (Pin_ID *4));
				GPIO->GPIOx[GPIO_B].GPIO_CRL |=  ((OperationMode) << (Pin_ID *4));
			}
			else if(Pin_ID <= 15){
				Pin_ID -= 8;
				GPIO->GPIOx[GPIO_B].GPIO_CRH &=~ ((0b1111) << (Pin_ID *4));
				GPIO->GPIOx[GPIO_B].GPIO_CRH |=  ((OperationMode) << (Pin_ID *4));
			}
			break;
		case GPIO_C:
			if(Pin_ID <= 7){
				GPIO->GPIOx[GPIO_C].GPIO_CRL &=~ ((0b1111) << (Pin_ID *4));
				GPIO->GPIOx[GPIO_C].GPIO_CRL |=  ((OperationMode) << (Pin_ID *4));
			}
			else if(Pin_ID <= 15){
				Pin_ID -= 8;
				GPIO->GPIOx[GPIO_C].GPIO_CRH &=~ ((0b1111) << (Pin_ID *4));
				GPIO->GPIOx[GPIO_C].GPIO_CRH |=  ((OperationMode) << (Pin_ID *4));
			}
			break;
	}
}

void MCAL_GPIO_void_SetPinValue(u8_t Port_ID , u8_t Pin_ID , u8_t Value){
	switch(Port_ID){
		case GPIO_A:
			if(Value == High){
				SET_BIT(GPIO->GPIOx[GPIO_A].GPIO_ODR, Pin_ID);
			}
			else if(Value == Low){
				CLEAR_BIT(GPIO->GPIOx[GPIO_A].GPIO_ODR, Pin_ID);
			}
			break;
		case GPIO_B:
			if(Value == High){
				SET_BIT(GPIO->GPIOx[GPIO_B].GPIO_ODR, Pin_ID);
			}
			else if(Value == Low){
				CLEAR_BIT(GPIO->GPIOx[GPIO_B].GPIO_ODR, Pin_ID);
			}
			break;
		case GPIO_C:
			if(Value == High){
				SET_BIT(GPIO->GPIOx[GPIO_C].GPIO_ODR, Pin_ID);
			}
			else if(Value == Low){
				CLEAR_BIT(GPIO->GPIOx[GPIO_C].GPIO_ODR, Pin_ID);
			}
			break;
	}
}

void MCAL_GPIO_void_GetPinValue(u8_t Port_ID , u8_t Pin_ID , u8_t* Value){
	switch(Port_ID){
		case GPIO_A:
			*Value =GET_BIT(GPIO->GPIOx[GPIO_A].GPIO_IDR, Pin_ID);
			break;
		case GPIO_B:
			*Value =GET_BIT(GPIO->GPIOx[GPIO_B].GPIO_IDR, Pin_ID);
			break;
		case GPIO_C:
			*Value =GET_BIT(GPIO->GPIOx[GPIO_C].GPIO_IDR, Pin_ID);
			break;
	}
}
void MCAL_GPIO_void_TogglePin(u8_t Port_ID , u8_t Pin_ID){
	switch(Port_ID){
		case GPIO_A:
			TOGGLE_BIT(GPIO->GPIOx[GPIO_A].GPIO_ODR, Pin_ID);
			break;
		case GPIO_B:
			TOGGLE_BIT(GPIO->GPIOx[GPIO_B].GPIO_ODR, Pin_ID);
			break;
		case GPIO_C:
			TOGGLE_BIT(GPIO->GPIOx[GPIO_C].GPIO_ODR, Pin_ID);
			break;
	}
}
