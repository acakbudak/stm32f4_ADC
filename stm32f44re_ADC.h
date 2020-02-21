/*
 * stm32f44re_ADC.h
 *
 *	An application with temperature sensor implemented inside
 *
 *  Created on: 21 Şub 2020
 *      Author: acakbudak
 */

#ifndef INC_STM32F44RE_ADC_H_
#define INC_STM32F44RE_ADC_H_


#include "stm32f446re.h"


/*
 * Address implemention of ADC registers
 */
#define ADC_BASEADDR  0x40012000U
#define ADC1_BASEADDR (ADC_BASEADDR + 0X000)
#define ADC2_BASEADDR (ADC_BASEADDR + 0X100)
#define ADC3_BASEADDR (ADC_BASEADDR + 0X200)
#define ADCC_BASEADDR (ADC_BASEADDR + 0X300)


#define ADC1_SR  		*((uint32_t*)(ADC1_BASEADDR + 0x00))
#define ADC1_CR1    	*((uint32_t*)(ADC1_BASEADDR + 0x04))
#define ADC1_CR2  		*((uint32_t*)(ADC1_BASEADDR + 0x08))
#define ADC1_SMPR1  	*((uint32_t*)(ADC1_BASEADDR + 0x0C))
#define ADC1_SMPR2 		*((uint32_t*)(ADC1_BASEADDR + 0x10))
#define ADC1_SQR1  		*((uint32_t*)(ADC1_BASEADDR + 0x2C))
#define ADC1_SQR2  		*((uint32_t*)(ADC1_BASEADDR + 0x30))
#define ADC1_SQR3  		*((uint32_t*)(ADC1_BASEADDR + 0x34))
#define ADC1_DR  		*((uint32_t*)(ADC1_BASEADDR + 0x4C))

#define ADC_CSR  		*((uint32_t*)(ADCC_BASEADDR + 0x00))
#define ADC_CCR  		*((uint32_t*)(ADCC_BASEADDR + 0x04))
#define ADC_CDR  		*((uint32_t*)(ADCC_BASEADDR + 0x08))


/*
 * ADC1 API implemention
 */

void adc1_init(void);
void start_conversion(void);
uint32_t temp_calculation(uint32_t get_value);



#endif /* INC_STM32F44RE_ADC_H_ */
