/* LIBRARIES */

//Header for Arduino S.T.L.
#include <utility.h>
#include <unwind-cxx.h>
#include <system_configuration.h>
#include <StandardCplusplus.h>

//Header for project class.
#include "stepper.h"
#include "LCD.h"
#include "pins.h"
#include "menu.h"
#include "pins.h"
#include "matrix.h"

/* SETUP */
void setup()
{
  //Class initialization.
  Pins.init();
  LCD.init();
  LCD.bootScreen(); //<-- Print loading screen.
  Stepper.init();
  Menu.init();
  Matrix.init();
  Stepper.init();
  //Start serial communication.
  Serial.begin(115200);
  Serial.println("Abos is ready!!");
  delay(2000);
}

/* LOOP */
void loop()
{
  //Navigation menu
  Menu.menu();
  //Stepper.tryThsi();
  //delay(5000);
  /*
     ALL ACTIONS HAPPEN HERE!
     Here the code selected in Menu.menu () is executed.
  */
  if (Stepper.useStepper()) //<-- If any code is found it is executed.
    Menu.clearOutputSelection(); //<-- Code cancellation if performed.
  else if (Matrix.useMatrix())
    Menu.clearOutputSelection();
  Serial.println("LOOP");
}
