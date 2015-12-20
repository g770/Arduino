// Pin of the blue LED
const int BLED = 9;

// Pin of the green LED
const int GLED = 10;

// Pin of the red LED
const int RLED = 11;

// Pin of temp sensor
const int TEMP = 0;

// Temp upper bound
const int TEMP_UPPER_BOUND = 161;
const int TEMP_LOWER_BOUND = 154;


void setup() {
  // Set the led pin to output mode
  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);

  Serial.begin(9600);
  
}


void loop() {

  int val = analogRead(TEMP);

  Serial.println(val);
  if (val < TEMP_LOWER_BOUND) {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  } 
  else if (val > TEMP_UPPER_BOUND) {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);    
  }
  else {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);    
  }
}
