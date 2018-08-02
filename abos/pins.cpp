// 
// 
// 

#include "pins.h"


/* PUBLIC */
void PinsClass::statementPins()
{
	pinOutput();
	pinInput();
}


/* PRIVATE */
void PinsClass::pinOutput()
{
	int size_of_array = (sizeof(pin_out) / sizeof(*pin_out));
	Serial.println(size_of_array);
	for (auto i = 0; i < size_of_array; i++)
	{
		pinMode(pin_out[i], OUTPUT);
	}
}

void PinsClass::pinInput()
{
	
}


PinsClass Pins;

