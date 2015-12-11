// Pin of the LED to control
const int LED = 9;
const int MAX_PWM = 256;

// Delay in msec between led changes
const int DELAY = 10;

void setup() {
  // Set the led pin to output mode
  pinMode(LED, OUTPUT);
}

void loop() {
  // Loop increasing the PWM duty cycle
  for (int i = 0; i < MAX_PWM; i++) {
    analogWrite(LED, i);
    delay(DELAY);
  }

  // Loop decreasing the PWM duty cycle
  for (int i = (MAX_PWM - 1); i >= 0; i--) {
    analogWrite(LED, i);
    delay(DELAY);
  }
  
}
