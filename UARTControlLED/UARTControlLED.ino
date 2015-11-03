const unsigned char LED_PIN = 13, BAD_STATE = 2;
unsigned int status = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED_PIN, status);
  Serial.println("This is Arduino Uno Rev 3. I am ready to execute your command.");
}

void loop() {
  delay(500); // Human can't type that fast. Give some break.
  int aByte = Serial.read();

  if (aByte != -1) {
    if ((aByte - '0' == 1) || (aByte - '0' == 0)) {
      status = aByte - '0';
    } else {
      status = BAD_STATE;
    }

    Serial.print("Receive ");
    Serial.write(aByte);

    if (status != BAD_STATE) {
      digitalWrite(LED_PIN, status ? HIGH : LOW);

      Serial.print(". Set LED to ");
      Serial.print(status ? "ON" : "OFF");
      Serial.println(".");
    } else {
      Serial.println(". I don't get it. No change on LED.");
    }
  }
}
