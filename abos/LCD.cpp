// 
// 
// 

#include "LCD.h"
/* PUBLIC */
void LCDClass::init()
{	
	Display20x4.begin(20, 4);
	Display20x4.clear();
	Display20x4.cursor();
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
	int *result = nullptr;
	//int myList[] = { TOP_BUTTON,CENTER_BUTTON,BOTTOM_BUTTON ,LEFT_BUTTON ,RIGHT_BUTTON };
	int myValue = analogRead(PIN_BUTTON);
	int min_value = myValue - myValue * DEFAULT_ERROR_RANGE / 100;
	int max_value = myValue * (100 + DEFAULT_ERROR_RANGE) / 100;
	//Serial.println(min_value);
	//Serial.println(max_value);
	//Serial.println(myValue);
	if(myValue < NULL_BUTTON)
	{
		if(min_value>=TOP_BUTTON && max_value>=TOP_BUTTON)
			*result = TOP_BUTTON;

		if(min_value >= CENTER_BUTTON && max_value >= CENTER_BUTTON)
			*result = CENTER_BUTTON;

		if(min_value >= BOTTOM_BUTTON && max_value >= BOTTOM_BUTTON)
			*result = BOTTOM_BUTTON;

		if (min_value >= LEFT_BUTTON && max_value >= LEFT_BUTTON)
			*result = LEFT_BUTTON;

		if (min_value >= RIGHT_BUTTON && max_value >= RIGHT_BUTTON)
			*result = RIGHT_BUTTON;

		while (analogRead(PIN_BUTTON) < NULL_BUTTON) {}
		return *result;
	}
	return NULL_BUTTON;
}
/*
int LCDClass::readButtonValue()
{
	return analogRead(PIN_BUTTON);
}
*/
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


LCDClass LCD;

