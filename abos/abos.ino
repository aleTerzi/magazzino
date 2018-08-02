/* UN GIRO DEL MOTORE SONO: 3200 step */
/* Microsecondo 1 --> 0,001 Millisecondo */
/* Pin Anet: https://github.com/MarlinFirmware/Marlin/blob/1.1.x/Marlin/pins_ANET_10.h */
//#include "stepper.h"

struct engine {
  int stepPin;
  int dirPin;
  int enable;
  int endStop;
};

const engine Xmotor{15, 21, 14, 18};
const engine Ymotor{22, 23, Xmotor.enable, 19};
const engine Zmotor{3, 2, 26, 20};

int passi;
void setup() {
  pinMode(15, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  pinMode(20, INPUT);
  Serial.begin(115200);
  Serial.println("\n<Arduino is ready>\n");
}

void loop() {
  /* MANUAL CONTROL */
    //passi = numeroStep();
    //Serial.println(passi);
    //engine.moveZStep(passi);
    moveEngine(Zmotor, 1);
    //moveEngine(Xmotor);
    //passi *= -1;
    //moveEngine(Ymotor);
  /* GO HOME */
  //Serial.print("entrato ");
  //goHome(Xmotor);
  //goHome(Ymotor);
  //goHome(Zmotor);
  //while (readEndStop(Ymotor)) {}
}

int numeroStep() {
  String name = "";
  char c;
  if ((Serial.available() > 0)) {
    Serial.print("Inserire il numero di step: ");
    while (Serial.available() > 0) {
      c = Serial.read();
      if (c == '\n') {
        //Serial.println(name);
        name = "";
      } else if (isDigit(c) || c == '-') {
        name += c;
        //Serial.println(c);
      }
    }
    Serial.println(name);
    return name.toInt();
  } else {
    delay(100);
  }
  return 0;
}

void moveEngine(engine MoveThis, int moveStep) {
  if (moveStep >= 0) {
    digitalWrite(MoveThis.dirPin, LOW);
  } else {
    digitalWrite(MoveThis.dirPin, HIGH);
    moveStep = moveStep * -1;
  }
  //digitalWrite(MoveThis.enable, LOW); //Freno Motore <---
  for (int x = 0; x < moveStep; x++) {
    digitalWrite(MoveThis.stepPin, HIGH);
    delayMicroseconds(70);
    digitalWrite(MoveThis.stepPin, LOW);
    delayMicroseconds(70);
  }
  //digitalWrite(MoveThis.enable, HIGH);
}

bool readEndStop(engine MoveThis) {
  //Serial.print(digitalRead(MoveThis.endStop));
  return digitalRead(MoveThis.endStop);
}

void goHome(engine MoveThis) {
  moveEngine(MoveThis, -1600);
  delay(300);
  while (readEndStop(MoveThis)) {
    //Serial.println("qui");
    moveEngine(MoveThis, 1);
  }
}

