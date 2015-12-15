// Pin of the blue LED
const int BLED = 9;

// Pin of the green LED
const int GLED = 10;

// Pin of the red LED
const int RLED = 11;

// Pin of button
const int BUTTON = 2;

// Total led modes
const int LED_MODE_COUNT = 7;

// Last button state
boolean lastButton = LOW;

// Current button state
bool currentButton = LOW;

// LED state - start at -1 since this is used as an index into the led arrays below
int ledMode = -1;

// Parallel arrays for the led colors.  Order is red, green, blue, teal, purple, white, black
int redLed[] = { 255, 0, 0, 0, 127, 127, 255, 0 };
int greenLed[] = { 0, 255, 0, 127, 0, 127, 255, 0 };
int blueLed[] = { 0, 0, 255, 127, 127, 0, 255, 0 };

// Button debouncing function
boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);

  if (last != current) {
    delay(5);
    current = digitalRead(BUTTON);
  }

  return current;
}


void setup() {
  // Set the led pin to output mode
  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);

  // Set the button to input
  pinMode(BUTTON, INPUT);
}

void setLedMode(int mode) {
  analogWrite(RLED, redLed[mode]);
  analogWrite(GLED, greenLed[mode]);
  analogWrite(BLED, blueLed[mode]);  
}

void loop() {

  // Read the current value of the button, making 
  // sure to debounce the switch
  currentButton = debounce(lastButton);

  // If the button state has changed, toggle the LED state
  if (lastButton == LOW && currentButton == HIGH) {
    ledMode++;
  }

  lastButton = currentButton;

  // If we have cycled through all the modes, reset
  if (ledMode > LED_MODE_COUNT) {
    ledMode = 0;
  }
  
  // Write the new led state
  setLedMode(ledMode);
  
}
