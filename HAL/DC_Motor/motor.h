#ifndef MOTOR_H_
#define MOTOR_H_

#include "../../LIB/std_types.h"

#define MOTOR_PORT_ID    PORTB_ID
#define MOTOR_PIN1_ID    PIN1_ID
#define MOTOR_PIN0_ID    PIN0_ID

typedef enum{
	CW,A_CW,OFF
}DcMotor_State;

void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif

