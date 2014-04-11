

/*
  Adapted From: Analog Input by David Cuartielles and Tom Igoe
  Author: Malcolm Knapp
  Project: Poteniemter to Blink Rate
  Date: 4/10/14
  Version: 0.1
  Description: This code shows how to use a light sensor to control
               the "blink" rate of a servo. In this case "blink" means
               moving between two positions.

 */
// ---------- included libraries ------------ 
#include <Servo.h>
#include <NewPing.h>

// initialize variables
int triggerPin = 13;      // select the pin ultrasonic trigger
int echoPin = 12;      // select pint 

// ---------- variable initialization  -----------
int delayTime = 0;     //variable that holds the delay time in milliseconds
int scaling = 1;
int maxValue = 0;
int minValue = 1023; 
int maxDistance = 200;   
char Terminator = 0x0D;

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
  Serial.print("On");
  Serial.println(Terminator);
  delay(delayTime);        
  Serial.print("Off");
  Serial.println(Terminator);
  delay(delayTime);                  
}
