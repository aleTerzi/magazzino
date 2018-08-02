// LCD.h



#ifndef _LCD_h
#define _LCD_h
#include <LiquidCrystal.h>
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


class LCDClass
{
private:
	LiquidCrystal Display20x4 { 28, 29, 10, 11, 16, 17 };
	/*(28, 29, 10, 11, 16, 17)*/
 public:
	 
	//Create LCD
	void init();

	//Set position at beginning.
	void set();

	//Clear LCD.
	void reset();

	//Clear LCD and set position at beginning. 
	void setReset();

	//Set the position of cursor on LCD.
	void setCursor(int x, int y);

	//Print text with a given position, does not delete the previous text.
	void printScreen(int x, int y, const String text);

	//Print text with a given position, but before delete the previous text.
	void printScreenAndClear(int x, int y, const String text);

};

extern LCDClass LCD;

#endif

