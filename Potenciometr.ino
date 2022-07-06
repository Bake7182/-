void setup() {
  pinMode(13, OUTPUT);
}
int speed = 5;  
void loop() {
  softPWM(13, analogRead(A0) / 4);
}
void softPWM(byte pin, byte val) {
  static byte count;
  count++;
  if (count == 0 && val != 0) digitalWrite(pin, 1);
  if (count == val) digitalWrite(pin, 0);
}