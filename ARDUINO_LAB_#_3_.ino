
// defines pins numbers
const int trigPin = 11;
const int echoPin = 12;

// defines variables
long duration;
int distance;

// state tracking
bool objectPresent = false;  // keeps track if object is currently detected
int lim = 10; // cm, 

void setup() {
  // Ultrasonic Pins
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input

  // LED
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);


  distance = duration * 0.034 / 2;


  if (distance > 0 && distance < lim) {
    if (objectPresent==false) {
      objectPresent = true;
      Serial.println("Object there");
      digitalWrite(LED_BUILTIN, HIGH); 
    }
  } else {

    if (objectPresent==true) {
      objectPresent = false;
      Serial.println("Object is gone");
      digitalWrite(LED_BUILTIN, LOW); 
    } else {
      Serial.println("Waiting To Detect An Object");
    }
  }

  delay(200); 
}
