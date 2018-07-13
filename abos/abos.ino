/*
void setup(){}
void loop() {}
*/
#include <LiquidCrystal.h>
LiquidCrystal Display20x4(28, 29, 10, 11, 16, 17);
const int menu = 17;
void setup() {
  pinMode(menu, INPUT);
  Display20x4.begin(20, 4);
  Display20x4.clear();
  Serial.begin(115200);
}

void loop() {
  bootScreen();
  int file = analogRead(menu);
  Serial.println(file);
}

void bootScreen(){
  Display20x4.setCursor(8,1);
  
  Display20x4.print("ABOX");
  Display20x4.setCursor(0,3);
  Display20x4.print("Powered by ABOS o.s.");
  delay(500);
}

