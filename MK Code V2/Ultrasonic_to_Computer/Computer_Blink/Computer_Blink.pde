/*
  Author: Malcolm Knapp
  Project: Computer Blink
  Date: 4/10/14
  Version: 0.1
  Description: This code shows how to "blink" a computer window in response to 
               input coming from the serial port. 
*/
// Serial port
import processing.serial.*;
Serial myPort;  // The serial port
String message = "";
String data = "";
int msgFlag = 0;
int index = 0;

void setup() {
  size (400, 400);
  if (frame != null) {
    frame.setResizable(true);
  }
  colorMode(RGB, 100);
  background (0,0,0);
  // List all the available serial ports
  println(Serial.list());
  // I know that the first port in the serial list on my mac

  myPort = new Serial(this, Serial.list()[0], 9600);

void draw() {
  while (myPort.available() > 0) {
    int inByte = myPort.read();
    if (inByte == '\n') {  // end of message check
      println(message);
      break;
    } 
    message = message + char(inByte);
  }
  if (message.equals("ON") == true) {
    background (100,100,100);
    //print("Screen "); println(message);
  } else if (message.equals("OFF")== true) {
    background (0,0,0);
    //print("Screen "); println(message);
  } else {
    if (message.equals("") == false) {
      //println(message);
    }
  }
  delay(100); 
  message = "";  
}

void keyPressed() {
  exit(); // Stops the program
}
