#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H


void MCAL_NVIC_Void_SetPeripheralPriority(u8_t Peripheral_Number , u8_t Group_Priority, u8_t Sub_Priority);
void MCAL_NVIC_Void_EnableInterrupt (u8_t Peripheral_Number);
void MCAL_NVIC_Void_DisapleInterrupt(u8_t Peripheral_Number);
void MCAL_NVIC_Void_SetPendigFlag   (u8_t Peripheral_Number);
void MCAL_NVIC_Void_ClearPendigFlag (u8_t Peripheral_Number);
void MCAL_NVIC_Void_GetActiveFlag   (u8_t Peripheral_Number, u8_t* Value);

#define GROUP_4Bit_SubGR_0Bit 0x05FA0300
#define GROUP_3Bit_SubGR_1Bit 0x05FA0400
#define GROUP_2Bit_SubGR_2Bit 0x05FA0500
#define GROUP_1Bit_SubGR_3Bit 0x05FA0600
#define GROUP_0Bit_SubGR_4Bit 0x05FA0700

#endif
