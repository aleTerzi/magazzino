#define X_STOP 18

void setup() {
  pinMode(X_STOP, INPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.println(digitalRead(X_STOP));
  delay(100);
}
