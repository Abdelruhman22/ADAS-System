
#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_

typedef struct{
	volatile u32_t GPIO_CRL;
	volatile u32_t GPIO_CRH;
	volatile u32_t GPIO_IDR;
	volatile u32_t GPIO_ODR;
	volatile u32_t GPIO_BSR;
	volatile u32_t GPIO_BRR;
	volatile u32_t GPIO_LCK;
}GPIO_Registers_t;

typedef struct{
	GPIO_Registers_t GPIOx[3];
}GPIO_PORTS_t;

#define GPIO ((volatile GPIO_PORTS_t*)0x40010800)

typedef struct{
	volatile u32_t AFIO_EVCR;
	volatile u32_t AFIO_MAPR;
	volatile u32_t AFIO_EXTICR[4];
	volatile u32_t AFIO_MAPR2;
}AFIO_Registers_t;

#define AFIO ((volatile AFIO_Registers_t*)0x40010000)



#endif /* GPIO_PRIVATE_H_ */
