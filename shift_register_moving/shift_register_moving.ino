// Shift register latch pin
const int LATCH_PIN = 9;

// Shift register data pin
const int DATA_PIN = 10;

// Shift register clock pin
const int CLOCK_PIN = 8;

// Assumes LEDs are in a 4x2 grid, numbered as follows:
// 1 2 3 4
// 5 6 7 8
// The different byte patterns that will be sent to the leds.  We will cycle through the patterns
byte patterns[] = { B10000000, B01000000, B00100000, B00010000, B00001000, B00000100, B00000010, B00000001 };
const int NUM_PATTERNS = 8;

// Used in our implementation of the arduino shiftOut function.  The bitmasks are used to 
// pull out a particular bit position from an input byte
byte byteMasks[] = { B10000000, B01000000, B00100000, B00010000, B00001000, B00000100, B00000010, B00000001 };
const int NUM_MASKS = 8;

const int DELAY = 1000;

void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);

  digitalWrite(LATCH_PIN, LOW);

  // Zero out the register
  writeToShiftRegister(DATA_PIN, CLOCK_PIN, B00000000);
  
  // Turn on the pattern (make sure everthing is off)
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);
}

// Custom implementation of the shiftOut function.. just for fun
void writeToShiftRegister(int dataPin, int clockPin, byte data) {

  // Iterate over each bit mask, pulling out a single bit from the input
  // data.  
  for (int i = 0; i < NUM_MASKS; i++) {
    byte result = data & byteMasks[i];
    boolean dataVal = LOW;
    
    // If the result is positive, the particular bit position was set, so send a 
    // HIGH value out the data pin
    if (result != 0) {
      dataVal = HIGH;
    }

    // Write the data pin, then turn the clock pin on and off to load the data value
    // into the shift register
    digitalWrite(dataPin, dataVal);
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
  }
  
}

void loop() {
  for (int i = 0; i < NUM_PATTERNS; i++) {
    writeToShiftRegister(DATA_PIN, CLOCK_PIN, patterns[i]);
    digitalWrite(LATCH_PIN, HIGH);
    digitalWrite(LATCH_PIN, LOW);
    delay(DELAY);
  }

   for (int i = NUM_PATTERNS -1; i >= 0; i--) {
    writeToShiftRegister(DATA_PIN, CLOCK_PIN, patterns[i]);
    digitalWrite(LATCH_PIN, HIGH);
    digitalWrite(LATCH_PIN, LOW);
    delay(DELAY);
  }
}
