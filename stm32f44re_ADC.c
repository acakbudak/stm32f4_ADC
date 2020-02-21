/*
 * stm32f44re_ADC.c
 *
 *  Created on: 21 Þub 2020
 *      Author: acakbudak
 */


#include "stm32f44re_ADC.h"

static void temperature_init(void)
{
	//Temperature sensor enable and Vbat disable
	ADC_CCR |= (2 << 22);
}

void adc1_init(void)
{
	//enable the clock
	RCC->APB2ENR |= (1 << 8);

	// enable the end of conversion interrupt
	ADC1_CR1 |= (1 << 5);
	//NVIC config
	*NVIC_ISER0 |= (1 << 18);

	// setting the sampling rate to max value
	ADC1_SMPR1 |= (8 << 24);

	//configs in sequence registers
	ADC1_SQR1 &= ~(0xF << 20);
	ADC1_SQR3 |= (18 << 0);

	//enable the ADC1
	ADC1_CR2 |= (1 << 0);
	//due to reference manual ADON and TSVREFE bits should be set at the same time
	temperature_init();
	ADC1_CR2 |= (1 << 1);


}


uint32_t temp_calculation(uint32_t get_value)
{
	//Temperature (in °C) = {(VSENSE – V25) / Avg_Slope} + 25
	get_value = get_value/4096*2;
	uint32_t result=((get_value-0.76)/2.5)+25;
	return result;

}

void start_conversion(void)
{
	ADC1_CR2 |= (1 << 30);
}
