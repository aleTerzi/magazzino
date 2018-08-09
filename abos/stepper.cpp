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
	Serial.println(hitStopForResetPosition(x_stepper_motor));
	Serial.println(hitStopForResetPosition(y_stepper_motor));
	Serial.println(hitStopForResetPosition(z_stepper_motor));
}

bool StepperClass::useStepper()
{
	if(Menu.statusMenu())
	{
		engineBrakeOn();
		const int go_here = Menu.outputMenu();
		if(go_here == 4)
		{
			engineBrakeOff();
			return true;
		}
		if (go_here == 30)
		{
			Serial.println("Sono qui");
			Menu.outputMenuWithText();
			autoHome();
			//delay(5000);
			return true;
		}
		if (go_here == 310)
		{
			moveWithButton(x_stepper_motor, 10);
			return true;
		}
		if (go_here == 311)
		{
			moveWithButton(x_stepper_motor, 1);
			return true;
		}
		if (go_here == 312)
		{
			moveWithButton(x_stepper_motor, 0.1);
			return true;
		}
		if (go_here == 320)
		{
			moveWithButton(y_stepper_motor, 10);
			return true;
		}
		if (go_here == 321)
		{
			moveWithButton(y_stepper_motor, 1);
			return true;
		}
		if (go_here == 322)
		{
			moveWithButton(y_stepper_motor, 0.1);
			return true;
		}
		if (go_here == 330)
		{
			moveWithButton(z_stepper_motor, 10);
			return true;
		}
		if (go_here == 331)
		{
			moveWithButton(z_stepper_motor, 1);
			return true;
		}
		if (go_here == 332)
		{
			moveWithButton(z_stepper_motor, 0.1);
			return true;
		}
	}
	return false;
}

void StepperClass::autoHome()
{
	//set here if need x auto home <--

	//Auto home Y stepper.
	while (!hitStopForResetPosition(y_stepper_motor))
	{
		cmToStep(y_stepper_motor, -120);
		moveStepper(y_stepper_motor);
	}
	cmToStep(y_stepper_motor, 2);
	y_stepper_motor.SPEED *= 10;
	moveStepper(y_stepper_motor);
	while (!hitStopForResetPosition(y_stepper_motor))
	{
		cmToStep(y_stepper_motor, -120);
		moveStepper(y_stepper_motor);
	}
	y_stepper_motor.SPEED = DEFAULT_SPEED_Y;
	//Auto home X stepper.
	while (!hitStopForResetPosition(z_stepper_motor))
	{
		cmToStep(z_stepper_motor, -120);
		moveStepper(z_stepper_motor);
	}
	cmToStep(z_stepper_motor, 1);
	z_stepper_motor.SPEED *= 4;
	moveStepper(z_stepper_motor);
	while (!hitStopForResetPosition(z_stepper_motor))
	{
		cmToStep(z_stepper_motor, -120);
		moveStepper(z_stepper_motor);
	}
	z_stepper_motor.SPEED = DEFAULT_SPEED_Z;
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


bool StepperClass::hitStopForResetPosition(stepperMotor move_this)
{
	if (digitalRead(move_this.STOP_PIN))
		return false;
	return true;
	
}

void StepperClass::moveStepper(stepperMotor& move_this)
{
	digitalWrite(move_this.DIRECTION_PIN, move_this.direction);
	if(move_this.DEFAULT_ROTATION)
	{
		for (long int i = 0; i < move_this.stepper && (!hitStopForResetPosition(move_this) || move_this.direction); i++)
		{
			digitalWrite(move_this.STEPPER_PIN, HIGH);
			delayMicroseconds(70);
			digitalWrite(move_this.STEPPER_PIN, LOW);
			delayMicroseconds(70);
		}
	}else
	{
		for (long int i = 0; i < move_this.stepper && (!hitStopForResetPosition(move_this) || !move_this.direction); i++)
		{
			digitalWrite(move_this.STEPPER_PIN, HIGH);
			delayMicroseconds(70);
			digitalWrite(move_this.STEPPER_PIN, LOW);
			delayMicroseconds(70);
		}
	}	
	move_this.stepper = 0;
}

void StepperClass::moveWithButton(stepperMotor move_this, float unit_of_space)
{
	float button_input = LCD.readButtonValue();
	float position = 0.0;
	LCD.setReset();
	LCD.printScreenAndClear(1, 1, "Posizione: ");
	LCD.printScreen(12, 1, position);
	while (button_input != LCD.LEFT_BUTTON && button_input != LCD.CENTER_BUTTON)
	{
		if(button_input == LCD.TOP_BUTTON)
		{
			cmToStep(move_this, unit_of_space);
			moveStepper(move_this);
			position += unit_of_space;
			LCD.printScreenAndClear(1, 1, "Posizione: ");
			LCD.printScreen(12, 1, position);
			//LCD.printScreen(1, 11, position);
		}else if(button_input == LCD.BOTTOM_BUTTON)
		{
			cmToStep(move_this, -(unit_of_space));
			moveStepper(move_this);
			position -= unit_of_space;
			LCD.printScreenAndClear(1, 1, "Posizione: ");
			LCD.printScreen(12, 1, position);
			//LCD.printScreen(1, 11, position);
		}			
		button_input = LCD.readButtonValue();
	}
	LCD.setReset();
	if (button_input == LCD.CENTER_BUTTON)
		Menu.setMenuToHome();
	if (button_input == LCD.LEFT_BUTTON)
		Menu.setMenuToParent();
}

void StepperClass::engineBrakeOff()
{
	digitalWrite(x_stepper_motor.ENABLE_PIN, HIGH);
	digitalWrite(z_stepper_motor.ENABLE_PIN, HIGH);
}

void StepperClass::engineBrakeOn()
{
	digitalWrite(x_stepper_motor.ENABLE_PIN, LOW);
	digitalWrite(z_stepper_motor.ENABLE_PIN, LOW);
}


StepperClass Stepper;

