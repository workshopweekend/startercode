Tutorial 1: Potentiometer to LED
===========

# Introduction
This series of tutorials focuses on demonstrating the power of system thinking. We will start with the Potentiometer --> Arduino --> LED system you have seen in the beginning class. We will then switch out the inputs and the outputs and then change the code to adapt the input to the output. Throughout this whole series the system will have the same behavior. This is the input will control the blink rate of the output. To begin with we will go through the code you have seen before. This tutorial will focus on how the code is organized and how to see what the code is doing while it is running. 

#Block Diagram
![Pot to LED System](Pot_to_LED_System.png)

# Circuit
* Use the Fritzing diagram from the morning class to put this circuit together.

# Code
* This tutorial starts with code that has identical functionality as the AnalogIn example. The main thing that is different this code and the AnalogIn code is that the comments are different and it uses <a href="http://arduino.cc/en/reference/serial">Serial</a>  commands. This makes it easy for us to see what the code is doing and make the code much easier to debug. This also changes the system because it adds a block. The original system was 


![ANALOG_IN System](ANALOGIN_System.png)

and the new system is 

![Pot to LED System](Pot_to_LED_System.png)	

* How Serial library works that we first have to say that we are going to use the Serial Port. This is done in the line 

	Serial.begin(9600);

The "9600" declares what speed we will communication at. 

* To send test you use "Serial.print" and "Serial.println". "Serial.print" sends the message leaves the cursor on on the same line. The next thing that is send will be appended to what is already there. "Serial.println" does the same except that it moves to the beginning of the next line. 
* We use both to send debugging information. Looke at the line 

	Serial.print("Sensor value: ");  Serial.println(sensorValue);

First we send the name of the variable we want to display. But for clarity we want to then display that varible on same line so we use "Serial.print". Then we send the varaible but this time we want to go to the next line so we use "Serial.println". Also even though these are two separate commands they are shown on the same line to make it easier for a human to read the code. 

* Turn the potentiometer clockwise and counterclockwise and figure out what the maximum and minium values that Sensor Value can have
* Open up the <a href="http://arduino.cc/en/guide/Environment#serialmonitor">Serial Monitor</a> and in the upper left hand corner of the Arduino IDE and see how the information is displayed
* Remove the "ln" from the line


	Serial.print("Sensor value: ");  Serial.println(sensorValue);

* Upload the code again and see how the output changes. You see now that "Sensor Value" and "Delay in millseconds" are now printed on the same line. This is the difference betweeen "Serial.print" and "Serial.println". 
* Put the "ln" back in and upload the code again and confirm you get back to the original behavior. The thing to take away is that you can use "Serial.print" and "Serial.println" to construct easy understood messages. 
* You are done with this tutorial! You can now go on to tutorial 2.
