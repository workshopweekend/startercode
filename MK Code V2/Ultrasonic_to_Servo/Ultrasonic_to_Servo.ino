/*
  Adapted From: Analog Input by David Cuartielles and Tom Igoe
  Author: Malcolm Knapp
  Project: Ultrasonic Sensor to Servo 
  Date: 4/10/14
  Version: 0.1
  Description: This code shows how to use a ultrasonic distance sensor to 
               control the "blink" rate of a servo. In this case "blink" means
               moving between two positions.

 */
// ---------- included libraries ------------ 
#include <Servo.h>
#include <NewPing.h>

// ---------- hardware pin defines  ----------- 
int triggerPin = 12;      // select the pin for ultrasonic trigger
int echoPin = 11;      // select the pin for echo

// ---------- variable initialization  ----------- 
int delayTime = 0; 
//variable that holds the delay time in milliseconds
int scaling = 1;
int maxValue = 3000;
int minValue = 50;
int maxDistance = 200;   // in centimeters

// ---------- library initialization  -----------  
Servo myservo;  // create servo object to control a servo a maximum of eight servo objects can be created 
NewPing sonar(triggerPin, echoPin, maxDistance);

void setup() {
  Serial.begin(9600);
  // declare hardware connections
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // Input
  delay(50);  // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  // Debugging
  Serial.print("Sensor value: "); Serial.println(uS);
  
  
  // Processing 
  //Scaling
  delayTime = map (uS, minValue, maxValue, 0, 1023);
  Serial.print ("Delay in milliseconds: "); Serial.println (delayTime);
  // Modes
  // None - put new modes here
  
  // Output 
  myservo.write(155); 
  delay(delayTime); 
  myservo.write(30);
  delay(delayTime);    
}
