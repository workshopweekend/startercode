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

// initialize variables
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int delayTime = 0; //
int scaling factor = 1;
int maxValue = 0;
int minValue = 1023;

void setup() {
  Serial.begin(9600);
  // decalr
  pinMode(ledPin, OUTPUT);  
}

void loop() {
  // Input
  sensorValue = analogRead(sensorPin); 
  // Debugging
  Serial.println(sensorValue);
  
  // Processing 
  // determine input value range
  if (sensorValue > maxValue) {
    maxValue = sensorValue;
  }
  if (sensorValue < minValue) {
    minValue = sensorValue;
  }
  Serial.print("Max Value");Serial.println(maxValue);
  Serial.print("Min Value");Serial.println(minValue);
  delayTime = map (sensorValue, minValue, maxValue, 0, 1023);
  
  // Output   
  digitalWrite(ledPin, HIGH);  
  delay(delayTime);            
  digitalWrite(ledPin, LOW);   
  delay(delayTime);                  
}
