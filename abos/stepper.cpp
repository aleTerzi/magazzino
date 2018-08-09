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
	cmToStep(z_stepper_motor, 1);
	moveStepper(z_stepper_motor);
	delay(500);
	cmToStep(z_stepper_motor, -1);
	moveStepper(z_stepper_motor);
	delay(2000);	
	cmToStep(x_stepper_motor, 1);
	moveStepper(x_stepper_motor);
	delay(500);
	cmToStep(x_stepper_motor, -1);
	moveStepper(x_stepper_motor);	
	//cmToStep(y_stepper_motor, -1);
	//moveStepper(y_stepper_motor);
}

bool StepperClass::useStepper()
{
	if(Menu.statusMenu())
	{
		if (Menu.outputMenu() == 30)
		{
			Serial.println("Sono qui");
			Menu.outputMenuWithText();
			delay(5000);
			return true;
		}
		if (Menu.outputMenu() == 310)
		{
			moveWithButton(x_stepper_motor, 10);
			return true;
		}
		if (Menu.outputMenu() == 311)
		{
			moveWithButton(x_stepper_motor, 1);
			return true;
		}
		if (Menu.outputMenu() == 312)
		{
			moveWithButton(x_stepper_motor, 0.1);
			return true;
		}
		if (Menu.outputMenu() == 320)
		{
			moveWithButton(y_stepper_motor, 10);
			return true;
		}
		if (Menu.outputMenu() == 321)
		{
			moveWithButton(y_stepper_motor, 1);
			return true;
		}
		if (Menu.outputMenu() == 322)
		{
			moveWithButton(y_stepper_motor, 0.1);
			return true;
		}
		if (Menu.outputMenu() == 330)
		{
			moveWithButton(z_stepper_motor, 10);
			return true;
		}
		if (Menu.outputMenu() == 331)
		{
			moveWithButton(z_stepper_motor, 1);
			return true;
		}
		if (Menu.outputMenu() == 332)
		{
			moveWithButton(z_stepper_motor, 0.1);
			return true;
		}
	}	
	return false;
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


StepperClass Stepper;

