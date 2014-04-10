

/*
 Analog Input
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe
 Modified 2 April 2014 
 By Malcolm Knapp
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 */

// included libraries
#include <Servo.h>
#include <NewPing.h>

// initialize variables
int triggerPin = 13;      // select the pin ultrasonic trigger
int echoPin = 12;      // select pint 
int delayTime = 0;     //variable that holds the delay time in milliseconds
int scaling_factor = 1;
int maxValue = 0;
int minValue = 1023; 
int maxDistance = 200;   // 

// Library objects  
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
  Serial.println(uS);
  
  // determine input value range
  if (uS > maxValue) {
    maxValue = uS;
  }
  if (uS < minValue) {
    minValue = uS;
  }
  Serial.print("Max Value");Serial.println(maxValue);
  Serial.print("Min Value");Serial.println(minValue);
  
  // Processing 
  delayTime = map (uS, minValue, maxValue, 0, 1023);
  
  // Output   
  myservo.write(0); 
  delay(delayTime);            
  myservo.write(180);   
  delay(delayTime);                  
}
