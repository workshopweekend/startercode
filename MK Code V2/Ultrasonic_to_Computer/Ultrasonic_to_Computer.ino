

/*
  Adapted From: Analog Input by David Cuartielles and Tom Igoe
  Author: Malcolm Knapp
  Project: Ultrasonic Sensor to Computer
  Date: 4/10/14
  Version: 0.1
  Description: This code shows how to use a Ultrasonic Distance Sensor to control 
               the blink rate of a computer screen.

 */
// ---------- included libraries ------------ 
#include <Servo.h>
#include <NewPing.h>

// ---------- hardware pin defines  ----------- 
int triggerPin = 12;      // select the pin ultrasonic trigger
int echoPin = 11;      // select pint 

// ---------- variable initialization  -----------
int delayTime = 0;     //variable that holds the delay time in milliseconds
int scaling = 1;
int maxValue = 3000;    // in microseconds
int minValue = 50;      // in microseconds
int maxDistance = 200;   
char Terminator = 13;  // in centimeters

// ---------- library initialization  -----------  
NewPing sonar(triggerPin, echoPin, maxDistance);

void setup() {
  Serial.begin(9600);
  // declare hardware connections
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
  Serial.print("ON"); Serial.println(Terminator, DEC);
  delay(delayTime);        
  Serial.print("OFF"); Serial.println(Terminator, DEC);
  delay(delayTime);                  
}
