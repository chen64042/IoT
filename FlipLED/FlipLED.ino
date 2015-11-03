const unsigned int LED_PIN = 13, FAST = 500, SLOW = 2000;
unsigned int fast = 1, pause = FAST;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  for (int i=0; i<5; i++) {    
    pause = fast ? FAST : SLOW;
    digitalWrite(LED_PIN, HIGH);
    delay(pause);              // wait for some time
    digitalWrite(LED_PIN, LOW);
    delay(pause);              // wait for some time
  }    
  fast = !fast;
}
