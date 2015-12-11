const int LED = 9;

// Initial setup code
void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

// Main loop
void loop() {
  for (int i = 100; i < 1000; i = i + 100) {
     digitalWrite(LED, HIGH);
     delay(i);
     digitalWrite(LED, LOW);
     delay(i);
  }
}
