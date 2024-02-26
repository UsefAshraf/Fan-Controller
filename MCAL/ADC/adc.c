
#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "../../LIB/common_macros.h" /* To use the macros like SET_BIT */

void ADC_init(const ADC_ConfigType *Config_Ptr)
{
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6);
	ADMUX = (ADMUX & 0xE0);
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr->prescaler);
	ADCSRA |= (1<<ADEN);
}

uint16 ADC_readChannel(uint8 channel_num){
	ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}






