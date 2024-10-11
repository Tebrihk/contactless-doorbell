
// Define pins numbers for your arduino,make sure you check carefully
const int trigPin = 13;  //Connect Trig pin from Ultrasonic Sensor to Arduino Pin 13
const int echoPin = 12;  //Connect Echo pin from Ultrasonic Sensor to Arduino Pin 12
 
const int relay= 10;   //Connect Positive pin of LED to Arduino Pin 10

// creating 3 variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Setting the trigPin as an Output
pinMode(echoPin, INPUT); // Setting the echoPin as an Input
 
pinMode(relay, OUTPUT);
Serial.begin(9600); // Starts the serial communication between the board and the sensor
}


void loop() {
// Clears the trigPin from any previous command
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 15 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculate the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 10){ 
  digitalWrite(relay, HIGH);
}
else{ 
  digitalWrite(relay, LOW);
}

}