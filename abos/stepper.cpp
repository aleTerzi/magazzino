// 
// 
// 

#include "stepper.h"

/*PUBLIC*/
void StepperClass::init()
{
	defaultStepperSet(x_stepper_motor_);
	defaultStepperSet(y_stepper_motor_);
	defaultStepperSet(z_stepper_motor_);
}

/*PRIVATE*/
void StepperClass::defaultStepperSet(stepperMotor& myStepper)
{
	myStepper.DEFAULT_ROTATION = true;
	myStepper.stepper = 0;
	myStepper.direction = false;
	myStepper.enable = false;
	myStepper.SPEED = DEFAULT_SPEED;
	myStepper.SHIFT = DEFAULT_SHIFT;
}

void StepperClass::cmToStep(stepperMotor& my_stepper, int space)
{
	my_stepper.stepper = 3200 * space / my_stepper.SHIFT;
	if(my_stepper.DEFAULT_ROTATION)
	{
		if (space < 0)
			my_stepper.direction = false;
		else
			my_stepper.direction = true;
	}
	else
	{
		if (space < 0)
			my_stepper.direction = true;
		else
			my_stepper.direction = false;
	}
}


void StepperClass::hitStopForResetPosition(stepperMotor move_this)
{
	
}

void StepperClass::moveStepper(stepperMotor& move_this)
{
	for(auto i = 0; i < move_this.stepper; i--)
	{
		
	}
}


StepperClass Stepper;

