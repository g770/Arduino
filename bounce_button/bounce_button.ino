// Pin of the LED to control
const int LED = 9;

// Pin of button
const int BUTTON = 2;

// Last button state
boolean lastButton = LOW;

// Current button state
bool currentButton = LOW;

// LED state
boolean ledOn = false;

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
  pinMode(LED, OUTPUT);

  // Set the button to input
  pinMode(BUTTON, INPUT);
}

void loop() {

  // Read the current value of the button, making 
  // sure to debounce the switch
  currentButton = debounce(lastButton);

  // If the button state has changed, toggle the LED state
  if (lastButton == LOW && currentButton == HIGH) {
    ledOn = !ledOn;
  }

  lastButton = currentButton;

  // Write the new led state
  digitalWrite(LED, ledOn);
  
}
