/*
  Adapted From: Analog Input by David Cuartielles and Tom Igoe
  Author: Malcolm Knapp
  Project: Poteniemter to Blink Rate
  Date: 4/10/14
  Version: 0.1
  Description: This code shows how to use a light sensor to control
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
int maxValue = 300;
int minValue = 750;

// ---------- library initialization  ----------- 
// None -  initialize new libraries here 

void setup() {
  Serial.begin(9600);
  // declareO hardware connections
  pinMode(ledPin, OUTPUT);  
}

void loop() {
  // Input
  sensorValue = analogRead(sensorPin); 
  // Debugging
  Serial.print("Sensor value: ");  Serial.println(sensorValue);
  
  
  // Processing
  //Scaling
  int delayTime = map (sensorValue, minValue-1, maxValue, 0, 1023);
  Serial.print ("Delay in milliseconds: "); Serial.println (delayTime);
  // Modes
  // None - put new modes here 
  
  // Output   
  digitalWrite(ledPin, HIGH); // turn the ledPin on
  delay(delayTime);          
  digitalWrite(ledPin, LOW);   // turn the ledPin off:
  delay(delayTime);  

  
}
