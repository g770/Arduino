const int LATCH_PIN = 9;
const int DATA_PIN = 10;
const int CLOCK_PIN = 8;


void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);

  digitalWrite(LATCH_PIN, LOW);

  sendPatternToRegister();
  
  // Turn on the pattern
  digitalWrite(LATCH_PIN, HIGH);
}

void sendPatternToRegister() {
  // Shift in the pattern to show
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, B10101010);
}

void loop() {
  // Do nothing  
}
