void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
}

bool flag = false;
uint32_t btnTimer = 0;
void loop() {
  bool btnState = !digitalRead(3);
  if (btnState && !flag && millis() - btnTimer > 100 && btnTimer < 500) {
    flag = true;
    btnTimer = millis();
    Serial.println("Click");
  }
  if (btnState && flag && millis() - btnTimer > 500) {
    btnTimer = millis();
    Serial.println("Hold");
  }
  if (!btnState && flag && millis() - btnTimer > 10) {
    flag = false;
    btnTimer = millis();
    Serial.println("IDLE");
  }
}