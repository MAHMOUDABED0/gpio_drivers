/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 *  Created on: Mar 11, 2022
 *      Author: 3abed
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include "STM32_GPIO_DRIVER.h"

void colck_En(){
 RCC_ENABLE_GPIOA();
 RCC_ENABLE_GPIOB();

}
void GPIO_init(){

	Gpio_pinconfig PinConfig;

	//PA1 input Highz
	PinConfig.gpiox_pinnuber = gpio_pin1;
	PinConfig.gpiox_mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinConfig);

	//PB1 output push pull mode
	PinConfig.gpiox_pinnuber = gpio_pin11;
	PinConfig.gpiox_mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.gpiox_outspeed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);

	//PA13 input Highz
	PinConfig.gpiox_pinnuber = gpio_pin13;
	PinConfig.gpiox_mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinConfig);

	//PB13 output push pull mode
	PinConfig.gpiox_pinnuber = gpio_pin13;
	PinConfig.gpiox_mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.gpiox_outspeed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);

}
void my_wait(int x){
	unsigned int i,j;
	for (i = 0; i < x; ++i){
		for(j = 0; j < 255 ; ++j);
	}
}

int main()
{
	colck_En();
	GPIO_init();

	while (1){
		// PA1 >> Connected external PUR
		if (MCAL_GPIO_ReadPin(GPIOA, gpio_pin1) == 0) //Press
		{
			MCAL_GPIO_TogglePin(GPIOB, gpio_pin1);
			while (MCAL_GPIO_ReadPin(GPIOA, gpio_pin1) == 0); // Single press
		}
		// PA13 >> Connected external PUR
		if (MCAL_GPIO_ReadPin(GPIOA, gpio_pin13) == 1) //Press Multi pressing
		{
			MCAL_GPIO_TogglePin(GPIOB, gpio_pin13);
		}
		my_wait(1);

	}

	return 0;
}
