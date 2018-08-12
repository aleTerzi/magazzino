// 
// 
// 

#include "pins.h"

/* PUBLIC */
void PinsClass::init()
{
	pinOutput();
	pinInput();
}


/* PRIVATE */
void PinsClass::pinOutput()
{
	const int size_of_array = (sizeof(pin_out) / sizeof(*pin_out));
	Serial.println(size_of_array);
	for (auto i = 0; i < size_of_array; i++)
	{
		pinMode(pin_out[i], OUTPUT);
	}
}

void PinsClass::pinInput()
{
	const int size_of_array = (sizeof(pin_in) / sizeof(*pin_in));
	Serial.println(size_of_array);
	for (auto i = 0; i < size_of_array; i++)
	{
		pinMode(pin_in[i], INPUT);
	}
}


PinsClass Pins;
