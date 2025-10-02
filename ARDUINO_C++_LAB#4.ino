// defines pins numbers
const int trigPin = 11;
const int echoPin = 12;

// defines variables
long duration;
int distance;


bool objectPresent = false;  
int lim = 10; 
int count = 0;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance > 0 && distance < lim) {
    if (objectPresent==false) {
      objectPresent = true;
      Serial.println("Object Detected & Present");
      digitalWrite(LED_BUILTIN, HIGH); 
    }
  } else {
    if (objectPresent==true) {
      objectPresent = false;
      Serial.println("Detected Object Is Gone");
      count++;
      Serial.print(count);
      Serial.println(" Objects Detected");
      digitalWrite(LED_BUILTIN, LOW); 
    } else {
      Serial.println("Waiting To Detect An Object");
    }
  }
  delay(200); 
}
