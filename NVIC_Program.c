#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_Config.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"


void MCAL_NVIC_Void_SetPeripheralPriority(u8_t Peripheral_Number , u8_t Group_Priority, u8_t Sub_Priority){
	u8_t Local_Priority = Sub_Priority | (Group_Priority << ((Number_of_Groups_SubGroups - 0x05FA0300)/256));
	NVIC_IPRx[Peripheral_Number] = Local_Priority << 4;
	SCB_AIRCR = Number_of_Groups_SubGroups;
}

void MCAL_NVIC_Void_EnableInterrupt (u8_t Peripheral_Number){
	if(Peripheral_Number <= 31){
		NVIC->NVIC_ISERx.Register_0 = (1 << Peripheral_Number);
	}
	else if (Peripheral_Number <= 59){
		Peripheral_Number -=32;
		NVIC->NVIC_ISERx.Register_1 = (1 << Peripheral_Number);
	}
}

void MCAL_NVIC_Void_DisapleInterrupt(u8_t Peripheral_Number){
	if(Peripheral_Number <= 31){
		NVIC->NVIC_ICERx.Register_0 = (1 << Peripheral_Number);
	}
	else if (Peripheral_Number <= 59){
		Peripheral_Number -=32;
		NVIC->NVIC_ICERx.Register_1 = (1 << Peripheral_Number);
	}

}

void MCAL_NVIC_Void_SetPendigFlag   (u8_t Peripheral_Number){
	if(Peripheral_Number <= 31){
		NVIC->NVIC_ISPRx.Register_0 = (1 << Peripheral_Number);
	}
	else if (Peripheral_Number <= 59){
		Peripheral_Number -=32;
		NVIC->NVIC_ISPRx.Register_1 = (1 << Peripheral_Number);
	}

}

void MCAL_NVIC_Void_ClearPendigFlag (u8_t Peripheral_Number){
	if(Peripheral_Number <= 31){
		NVIC->NVIC_ICPRx.Register_0 = (1 << Peripheral_Number);
	}
	else if (Peripheral_Number <= 59){
		Peripheral_Number -=32;
		NVIC->NVIC_ICPRx.Register_1 = (1 << Peripheral_Number);
	}

}

void MCAL_NVIC_Void_GetActiveFlag   (u8_t Peripheral_Number , u8_t* Value){
	if(Peripheral_Number <= 31){
		*Value = GET_BIT(NVIC->NVIC_IABR0x.Register_0 , Peripheral_Number);
	}
	else if (Peripheral_Number <= 59){
		Peripheral_Number -=32;
		*Value = GET_BIT(NVIC->NVIC_IABR0x.Register_0 , Peripheral_Number);
	}

}
