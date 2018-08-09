// 
// 
// 

#include "stepper.h"

/*PUBLIC*/
void StepperClass::init()
{
	Serial.println(y_stepper_motor.STEPPER_PIN);
	Serial.println(z_stepper_motor.STEPPER_PIN);
	Serial.println(x_stepper_motor.STEPPER_PIN);
}

void StepperClass::tryThsi()
{
	cmToStep(y_stepper_motor, -1);
	moveStepper(y_stepper_motor);
	delay(500);
	cmToStep(y_stepper_motor, 1);
	moveStepper(y_stepper_motor);
	delay(500);
	//cmToStep(z_stepper_motor, 1);
	//moveStepper(z_stepper_motor);
	//delay(500);
	//cmToStep(z_stepper_motor, -1);
	//moveStepper(z_stepper_motor);
	delay(2000);
	
	cmToStep(x_stepper_motor, 1);
	moveStepper(x_stepper_motor);
	delay(500);
	cmToStep(x_stepper_motor, -1);
	moveStepper(x_stepper_motor);
	
	//cmToStep(y_stepper_motor, -1);
	//moveStepper(y_stepper_motor);
}


/*PRIVATE*/
void StepperClass::cmToStep(stepperMotor& my_stepper, int space)
{
	my_stepper.stepper = abs(3200 * space / my_stepper.SHIFT);
	Serial.println(my_stepper.stepper);	
	if(my_stepper.DEFAULT_ROTATION)
	{
		if (space > 0)
			my_stepper.direction = true;
		else
			my_stepper.direction = false;
	}
	else
	{
		if (space > 0)
			my_stepper.direction = false;
		else
			my_stepper.direction = true;
	}
}


void StepperClass::hitStopForResetPosition(stepperMotor move_this)
{
	
}

void StepperClass::moveStepper(stepperMotor& move_this)
{
	digitalWrite(move_this.DIRECTION_PIN, move_this.direction);
	for(long int i = 0; i < move_this.stepper; i++)
	{
		digitalWrite(move_this.STEPPER_PIN, HIGH);
		delayMicroseconds(70);
		digitalWrite(move_this.STEPPER_PIN, LOW);
		delayMicroseconds(70);
	}
	move_this.stepper = 0;
}


StepperClass Stepper;

