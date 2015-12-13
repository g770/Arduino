// Pin of the LED to control
const int LED = 9;

// Pin of button
const int BUTTON = 2;


void setup() {
  // Set the led pin to output mode
  pinMode(LED, OUTPUT);

  // Set the button to input
  pinMode(BUTTON, INPUT);
}

void loop() {

  // Read the state of the button and set the 
  // state of the LED accordingly.  The LED will 
  // only be on if the button is held down.
  if (digitalRead(BUTTON) == LOW) {
    digitalWrite(LED, LOW);
  }
  else {
    digitalWrite(LED, HIGH);
  }
}
