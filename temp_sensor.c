/*
 * temp_sensor.c
 *
 *  Created on: 21 Şub 2020
 *      Author: acakbudak
 */

#include "stm32f446re.h"

uint32_t val;

void delay(void){

	for(uint32_t i=0; i<50000; i++);

}


int main(void)
{
	adc1_init();
	start_conversion();
	delay();

}

void ADC_IRQHandler(void)
{
	if(ADC1_SR & 0x2)
	{
		val= ADC1_DR;
		delay();
		temp_calculation(val);
	}

}
