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
	LiquidCrystal Display20x4 { 28, 29, 10, 11, 16, 17 };
	const int PIN_BUTTON = 17;
	const int DEFAULT_ERROR_RANGE = 10; // 10%

	// Returns element closest to target in arr[]
	void findClosest(int arr[], int n, int target, int &result);

	/*END CREDIT*/

 public:
	 const int LCD_WIDTH = 20;
	 const int LCD_HEIGHT = 4;
	 const int NULL_BUTTON = 1018;
	 const int TOP_BUTTON = 693;
	 const int CENTER_BUTTON = 324;
	 const int BOTTOM_BUTTON = 177;
	 const int LEFT_BUTTON = 92;
	 const int RIGHT_BUTTON = 508;

	//Create LCD
	void init();

	//Boot screen ABOS.
	void const bootScreen();

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

	/*
	 * Print text with a given position,
	 * but before delete the extra text.
	 * Set a offset with "offset".
	 */
	void printScreenCut(int x, int y, int offset, String text);

	/*
	 * Autoscrool a given string to left, 
	 * with a given offset on x axis.
	 * Need of x and y point start.
	 */
	void autoScroolLeft(int x, int y, int offset, String text);

	//Red button value.
	int readButtonValue();

};

extern LCDClass LCD;

#endif

