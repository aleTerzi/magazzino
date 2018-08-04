#define X_STOP 18
#define Y_STOP 19
#define Z_STOP 20

void setup() {
  pinMode(X_STOP, INPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.print(testStop(X_STOP));
  Serial.print("\t");
  Serial.print(testStop(Y_STOP));
  Serial.print("\t");
  Serial.println(testStop(Z_STOP));
  
  delay(100);
}

bool testStop(int port){
  return digitalRead(port);
}
