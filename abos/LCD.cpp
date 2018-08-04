// 
// 
// 

#include "LCD.h"
/* PUBLIC */
void LCDClass::init()
{	
	Display20x4.begin(LCD_WIDTH, LCD_HEIGHT);
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

int LCDClass::readButtonValue()
{
	int result;;
	int myValue = analogRead(PIN_BUTTON);
	int min_value = myValue - myValue * DEFAULT_ERROR_RANGE / 100;
	if(myValue < NULL_BUTTON)
	{
		if ( min_value <= LEFT_BUTTON)
		{
			result = LEFT_BUTTON;
		}else if (min_value <= BOTTOM_BUTTON)
		{
			result = BOTTOM_BUTTON;
		}else if (min_value <= CENTER_BUTTON)
		{
			result = CENTER_BUTTON;
		}else if (min_value <= RIGHT_BUTTON)
		{
			result = RIGHT_BUTTON;
		}else if(min_value <= TOP_BUTTON)
		{
			result = TOP_BUTTON;
		}else
		{
			result = readButtonValue();
		}

		while (analogRead(PIN_BUTTON) < NULL_BUTTON) {}
		return result;
	}
	return NULL_BUTTON;
}

/* PRIVATE */
void LCDClass::findClosest(int arr[], int n, int target, int &result)
{
	int difference = abs(target - arr[0]);
	result = arr[0];
	for(auto i = 0; i < n; i++)
	{
		if(abs(arr[n] - target) < difference)
		{
			difference = abs(arr[n] - target);
			result = arr[n];
		}
	}
}

void LCDClass::printScreenCut(int x, int y, int offset, String text)
{
	LCD.printScreen(x, y, text.substring(0, LCD_WIDTH - offset));
}


void LCDClass::autoScroolLeft(int x, int y, int offset, String text)
{
	int combo = text.length() - LCD.LCD_WIDTH + offset;
	for(auto i = 0; i <= combo && combo > 0; i++)
	{
		delay(300);
		LCD.printScreen(x, y, text.substring(i, LCD_WIDTH + i - offset));
	}
	printScreenCut(x, y, offset, text);
}



LCDClass LCD;

