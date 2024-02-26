#include "motor.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/PWM/pwm.h"


void DcMotor_Init(void){
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);

	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);

}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	PWM_Timer0_Start(speed);
	if(state ==CW)
	{
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_HIGH);
					GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);

	}
	if(state == A_CW)
	{
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
					GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_HIGH);

	}
	else if (state == OFF){
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
					GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);

	}
}




