/* UN GIRO DEL MOTORE SONO: 3200 step */
/* Microsecondo 1 --> 0,001 Millisecondo */

const int stepPin = 15;
const int dirPin = 21;
const int enable = 14;
int passi;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enable, OUTPUT);
  Serial.begin(115200);
  Serial.println("\n<Arduino is ready>\n");
}

void loop() {
  digitalWrite(enable, HIGH);
  passi = numeroStep();
  Serial.println(passi);
  moveEngine();
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

void moveEngine() {
  if (passi >= 0) {
    digitalWrite(dirPin, LOW);
  } else {
    digitalWrite(dirPin, HIGH);
    passi = passi * -1;
  }
  digitalWrite(enable, LOW);
  for (int x = 0; x < passi; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(300);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(300);
  }
}


