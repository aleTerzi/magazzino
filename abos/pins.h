// pins.h

#ifndef _PINS_h
#define _PINS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class PinsClass
{
 protected:
	/*
	 * //Engine:
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
	 * ----------------------
	 * 
	 * //L.C.D.:
	 * rs:		28 
	 * enable:	29
	 * d4:		10
	 * d5:		11
	 * d6:		16
	 * d7:		17
	 * 
	 * ----------------------
	 * 
	 * //Sd Card:
	 * 
	 *
	 */
	 const unsigned short int pin_out[11] = {15, 21, 22, 23, 14, 3, 2, 26, 18, 19, 20};

	//Declaration pin output:
	 void pinOutput();

	/*
	 * //L.C.D. buttons:
	 * new input pin: 17
	 * ^ 
	 * | old pin: 30
	 * 
	 * ----------------------
	 * 
	 * //Stop:
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
	 const unsigned short int pin_in[5] = { 17, 30, 18, 19, 20 };

	//Declaration pin input:
	 void pinInput();

 public:
	 void init();
};

extern PinsClass Pins;

#endif

