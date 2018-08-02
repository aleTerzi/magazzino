// stepper.h

#ifndef _STEPPER_h
#define _STEPPER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class StepperClass
{
	const short int ONE_ROTATION_STEPS = 3200;
	const float DEFAULT_SHIFT = 0;
	const short int DEFAULT_SPEED = 300;	

	struct stepperMotor
	{
		const byte STEPPER_PIN;
		const byte DIRECTION_PIN;
		const byte ENABLE_PIN;

		//Number of steps to be taken at the next cycle.
		byte stepper;

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
	 */
	stepperMotor x_stepper_motor_ = { 15, 21, 14 };
	stepperMotor y_stepper_motor_ = { 21, 23, x_stepper_motor_.enable };
	stepperMotor z_stepper_motor_ = { 3,2,26 };

	//Set default statistics for stepper.
	void defaultStepperSet(stepperMotor &myStepper);
 public:
	void init();
};

extern StepperClass Stepper;

#endif

