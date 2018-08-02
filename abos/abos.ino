/* LIBRERIE */

#include "LCD.h"
#include "pins.h"
#include "menu.h"
#include "pins.h"

/* SETUP */
void setup()
{
	LCD.init();
	LCD.printScreen(8, 1, "ABOX");
	LCD.printScreen(0, 3, "Powered by ABOS o.s.");
	Serial.begin(115200);
	Serial.println("Abos is ready!!");
}

/* LOOP */
void loop()
{
	delay(500);
}
