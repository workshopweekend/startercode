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

// initialize variables
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable that holds the the value coming from the sensor
int delayTime = 0;     //variable that holds the delay time in milliseconds
int scaling factor = 1;
int maxValue = 0;
int minValue = 1023; 

// Library objects  
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
  Serial.println(sensorValue);
  
  // determine input value range
  if (sensorValue > maxValue) {
    maxValue = sensorValue;
  }
  if (sensorValue < minValue) {
    minValue = sensorValue;
  }
  Serial.print("Max Value");Serial.println(maxValue);
  Serial.print("Min Value");Serial.println(minValue);
  
  // Processing 
  delayTime = map (sensorValue, minValue, maxValue, 0, 1023);
  
  // Output   
  myservo.write(0); 
  delay(delayTime);            
  myservo.write(180);   
  delay(delayTime);                  
}
