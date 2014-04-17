/*
  Adapted From: Analog Input by David Cuartielles and Tom Igoe
  Author: Malcolm Knapp
  Project: Potentiometer to LED
  Date: 4/10/14
  Version: 0.1
  Description: This code shows how to use a potentiometer to control
               the blink rate of a LED. 

 */
// ---------- included libraries ------------ 
// None - include new libraries here 

// ---------- hardware pin defines  ----------- 
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED

// ---------- variable initialization  ----------- 
int sensorValue = 0;  // variable to store the value coming from the sensor
int delayTime = 0; //
int scaling = 1;

// ---------- library initialization  ----------- 
// None -  initialize new libraries here 

void setup() {
  Serial.begin(9600);
  // declare hardware connections
  pinMode(ledPin, OUTPUT);  
}

void loop() {
  // Input
  sensorValue = analogRead(sensorPin); 
  // Debugging
  Serial.print("Sensor value: ");  Serial.println(sensorValue);
  
  // Processing
  // Scaling
  delayTime = scaling*sensorValue;
  Serial.print ("Delay in milliseconds: "); Serial.println (delayTime);
  // Modes
  // None - put new modes here 
  
  // Output   
  digitalWrite(ledPin, HIGH); // turn the ledPin on
  delay(delayTime);          
  digitalWrite(ledPin, LOW);   // turn the ledPin off:
  delay(delayTime);
}
