// 
// 
// 

#include "LCD.h"
/* PUBLIC */
void LCDClass::init()
{	
	Display20x4.begin(20, 4);
	Display20x4.clear();
}

void const LCDClass::bootScreen()
{
	setReset();
	LCD.printScreen(8, 1, "ABOX");
	LCD.printScreen(0, 3, "Powered by ABOS o.s.");
}


void LCDClass::set()
{
	Display20x4.setCursor(0, 0);
}

void LCDClass::reset()
{
	Display20x4.clear();
}

void LCDClass::setReset()
{
	reset();
	set();
}

void LCDClass::setCursor(int x, int y)
{
	Display20x4.setCursor(x, y);
}


void LCDClass::printScreen(int x, int y, const String text)
{
	setCursor(x, y);
	Display20x4.print(text);
}

LCDClass LCD;

