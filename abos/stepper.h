// stepper.h

#ifndef _STEPPER_h
#define _STEPPER_h

/* LIBRARIES */
#include "menu.h"
#include "LCD.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class StepperClass
{
	const short int ONE_ROTATION_STEPS = 3200;
	const double DEFAULT_SHIFT_Z = 0.12;
	const short int DEFAULT_SPEED_Z = 70;
	const double DEFAULT_SHIFT_XY = 4.13;
	const short int DEFAULT_SPEED_X = 2000;
	const short int DEFAULT_SPEED_Y = 150;

	struct stepperMotor
	{
		const byte STEPPER_PIN;
		const byte DIRECTION_PIN;
		const byte ENABLE_PIN;
		const byte STOP_PIN;

		/*
		* Direction of rotation:
		* TRUE --> clockwise.
		* FALSE --> counterclockwise.
		*/
		bool DEFAULT_ROTATION;

		//Number of steps to be taken at the next cycle.
		long int stepper;

		/*
		 * Direction of rotation:
		 * TRUE --> clockwise.
		 * FALSE --> counterclockwise.
		 */
		bool direction;

		/*
		 * If the engine brake is enabled:
		 * TRUE --> It is enabled.
		 * FALSE --> It is disabled.
		 */
		bool enable;

		/*
		 * Speed for one step:
		 * NOTE: For a complete step the value is x2 (SPEEP = value --> one step value*2).
		 */
		unsigned int SPEED;

		//Displacement in "cm" for a complete revolution.
		float SHIFT;
	};

	/*
	 * * //Engine:
	 * - X: 
	 * Step:	15			
	 * Dir:		21 
	 *  
	 * - Y:
	 * Step:	22
	 * Dir:		23
	 * 
	 * XY-Enable:	14
	 * 
	 * - Z:
	 * Step:	3			
	 * Dir:		2
	 * 
	 * Z-Enable:	26
	 * 
	 * - E:
	 * Step:	1
	 * Dir:		0
	 * 
	 * E-Enable: used Y enable.
	 * 
	 * * //Stop:
	 * - X:
	 * Stop:	18 
	 * 
	 * - Y:
	 * Stop:	19
	 * 
	 * - Z:
	 * Stop:	20
	 * 
	 */
	/* CREATION OF THE STEPPERS */
	stepperMotor x_stepper_motor = {22,23,14,19,false,0,true,true,DEFAULT_SPEED_Y,DEFAULT_SHIFT_XY};
	stepperMotor y_stepper_motor = {15,21,14,18,false,0,true,true,DEFAULT_SPEED_X,DEFAULT_SHIFT_XY};
	stepperMotor z_stepper_motor = {3,2,26,20,true,0,true,true,DEFAULT_SPEED_Z,DEFAULT_SHIFT_Z};
	//stepperMotor e_stepper_motor = { 1,0,14,-1,true,0,true,true,300,4.13 };

	//void defaultStepperSet(stepperMotor& my_stepper, int line);

	//Converts a distance in centimeters into engine revolutions.
	void cmToStep(stepperMotor& my_stepper, long int space);

	/*
	 * Returns if the engine hit the end stop.
	 * TRUE --> hit.
	 * FALSE --> not hit.
	 */
	bool hitStopForResetPosition(stepperMotor move_this);

	//Physically moves the stepper.
	void moveStepper(stepperMotor& move_this);

	//Takes input from the L.C.D. of how much a certain stepper must move.
	void moveWithButton(stepperMotor move_this, float unit_of_space);

	//Disable all the steppers.
	void engineBrakeOff();

	//Enable all the steppers.
	void engineBrakeOn();

public:

	//Init class.
	void init();

	//Interaction with class.
	bool useStepper();

	//Reset all steppers position to home.
	void autoHome();

	void tryThsi();

	//Take in input a space and move the stepper of that position.
	void moveX(int space);
	void moveY(int space);
	void moveZ(int space);

	//Enable all the steppers (public).
	void engineOn();
};

extern StepperClass Stepper;

#endif
