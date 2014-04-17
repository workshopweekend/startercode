/*
  Adapted From: Analog Input by David Cuartielles and Tom Igoe
  Author: Malcolm Knapp
  Project: Light Sensor to Servo
  Date: 4/10/14
  Version: 0.1
  Description: This code shows how to use a light sensor to control
               the "blink" rate of a servo. In this case "blink" means
               moving between two positions.

 */
// ---------- included libraries ------------ 
#include <Servo.h>

// ---------- hardware pin defines  ----------- 
int sensorPin = A0;    // select the input pin for the potentiometer

// ---------- variable initialization  ----------- 
int sensorValue = 0;  // variable to store the value coming from the sensor
int delayTime = 0; //variable that holds the delay time in milliseconds
int scaling = 1;
int maxValue = 750;
int minValue = 300;


// ---------- library initialization  -----------  
Servo myservo;  // create servo object to control a servo a maximum of eight servo objects can be created 

void setup() {
  Serial.begin(9600);
  // declare hardware connections
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // Input
  sensorValue = analogRead(sensorPin); 
  // Debugging
  Serial.print("Sensor value: ");  Serial.println(sensorValue);
  
  
  // Processing
  //Scaling
  delayTime = map (sensorValue, minValue, maxValue, 200, 1023);
  Serial.print ("Delay in milliseconds: "); Serial.println (delayTime);
  // Modes
  // None - put new modes here 
  
  // Output 
  myservo.write(155); 
  delay(delayTime); 
  myservo.write(30);
  delay(delayTime);    
}
