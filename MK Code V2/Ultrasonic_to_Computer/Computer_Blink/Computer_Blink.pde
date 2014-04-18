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
  colorMode(RGB, 100);
  background (0,0,0);
  // List all the available serial ports
  println(Serial.list());
  // I know that the first port in the serial list on my mac

  myPort = new Serial(this, Serial.list()[0], 9600); // This looks at the first port in the Serial List
}

void draw() {
  while (myPort.available() > 0) {
    int inByte = myPort.read();
    if (inByte == 13) {  // end of message check
    //  println(message);
      break;
    } 
    message = message + char(inByte);
  }
    if (data.equals("ON")) {
      background (0,0,0);
    }
    if (data.equals("OFF")) {
      background (100,100,100);
    }
  delay(100);                                
}

void keyPressed() {
  output.flush(); // Writes the remaining data to the file
  output.close(); // Finishes the file
  exit(); // Stops the program
}
