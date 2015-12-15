// Pin of the blue LED
const int BLED = 9;

// Pin of the green LED
const int GLED = 10;

// Pin of the red LED
const int RLED = 11;

// Pin of button
const int BUTTON = 2;

// Last button state
boolean lastButton = LOW;

// Current button state
bool currentButton = LOW;

// LED state
int ledMode = 0;

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

  if (mode == 1) {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
  else if (mode == 2) {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  else if (mode == 3) {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
  else {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);    
  }
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
  if (ledMode == 4) {
    ledMode = 0;
  }
  
  // Write the new led state
  setLedMode(ledMode);
  
}
