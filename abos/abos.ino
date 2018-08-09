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
#include "matrix.h"

/* SETUP */
void setup()
{
	Serial.begin(115200);
	Serial.println("Abos is ready!!");
	Pins.init();
	LCD.init();
	LCD.bootScreen();
	Stepper.init();
	Menu.init();
	Matrix.init();
	Stepper.init();	
	delay(2000);
}

/* LOOP */
void loop()
{
	Menu.menu();
	//Stepper.tryThsi();
	//delay(5000);
	if (Stepper.useStepper())
		Menu.clearOutputSelection();
	else if (Matrix.useMatrix())
		Menu.clearOutputSelection();
	Serial.println("LOOP");
}
