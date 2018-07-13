/* UN GIRO DEL MOTORE SONO: 3200 step */
/* Microsecondo 1 --> 0,001 Millisecondo */
/* Pin Anet: https://github.com/MarlinFirmware/Marlin/blob/1.1.x/Marlin/pins_ANET_10.h */

struct engine{
  int stepPin;
  int dirPin;
  int enable;
};

const engine Xmotor{15, 21, 14};
const engine Ymotor{22, 23, Xmotor.enable};
int passi;

void setup() {
  pinMode(15, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  Serial.begin(115200);
  Serial.println("\n<Arduino is ready>\n");
}

void loop() {
  digitalWrite(Xmotor.enable, HIGH);
  passi = numeroStep();
  Serial.println(passi);
  moveEngine(Xmotor);
  passi *= -1;
  moveEngine(Ymotor);
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

void moveEngine(engine MoveThis) {
  if (passi >= 0) {
    digitalWrite(MoveThis.dirPin, LOW);
  } else {
    digitalWrite(MoveThis.dirPin, HIGH);
    passi = passi * -1;
  }
  digitalWrite(MoveThis.enable, LOW);
  for (int x = 0; x < passi; x++) {
    digitalWrite(MoveThis.stepPin, HIGH);
    delayMicroseconds(300);
    digitalWrite(MoveThis.stepPin, LOW);
    delayMicroseconds(300);
  }
}


