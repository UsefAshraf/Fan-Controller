
#include "pwm.h"
#include <avr/io.h>
#include "../../MCAL/GPIO/gpio.h"

void PWM_Timer0_Start(uint8 duty_cycle){
	uint8 comp_value;
	comp_value = duty_cycle *2.55;
	TCNT0=0;
	OCR0=comp_value;
	DDRB = DDRB | (1<<PB3);
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

}
