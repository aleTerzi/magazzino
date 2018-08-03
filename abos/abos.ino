/* LIBRERIE */


#include <utility.h>
#include <unwind-cxx.h>
#include <system_configuration.h>
#include <StandardCplusplus.h>
#include "stepper.h"
#include "LCD.h"
#include "pins.h"
#include "menu.h"
#include "pins.h"

/* SETUP */
void setup()
{
	Pins.init();
	LCD.init();
	LCD.bootScreen();
	Stepper.init();
	Serial.begin(115200);
	Serial.println("Abos is ready!!");
}

/* LOOP */
void loop()
{	
	
	delay(10);
}
