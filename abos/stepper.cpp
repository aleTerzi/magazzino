// 
// 
// 

#include "stepper.h"

void StepperClass::init()
{
	defaultStepperSet(x_stepper_motor_);
	defaultStepperSet(y_stepper_motor_);
	defaultStepperSet(z_stepper_motor_);
}

/*PRIVATE*/
void StepperClass::defaultStepperSet(stepperMotor& myStepper)
{
	myStepper.stepper = 0;
	myStepper.direction = false;
	myStepper.enable = false;
	myStepper.SPEED = DEFAULT_SPEED;
	myStepper.SHIFT = DEFAULT_SHIFT;
}

StepperClass Stepper;

