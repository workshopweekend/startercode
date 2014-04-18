Tutorial 2: Light Sensor to LED by Malcolm Knapp
===========

# Introduction
This tutorial shows you how to switch out the potentiometer for a light sensor. We will go through how to chnage the electronics and code to make it give you the same behavior. The trick about this code is that the Light Sensor does not have the same input range as the potoentiometer.As you saw before the potentiometer input is the whole range of the ADC i.e from 0 to 1023. The light sensor resistance does not change as much as the potentiometer and so it will have a smaller range in the ADC. We will show you how to find this new range and update the code so it will have the same behavior as before 

#Block Diagram


	Light Sensor -- Analog Siganl --> Arduino -- Digital Signal --> LED
 									    |
									    |- ascii Text Signal --> Computer

# Circuit
* To set up the circuit see the fritzing diagram for this tutorial

# Code
* Save the Potentiometer to LED code as Light Sensor to LED
*The first set of changes is just updating the description to match the hardware. This may seem trivial but it is becomes really useful as your project get more complex. Think of it as explaining what you are doing to your self six month or a year from now. 
* Now we need to add some variables to store the min and max sensor values. You can see where to add them in the Code Difference pdf


	int maxValue = 1023;
	int minValue = 0;

* Upload the code, open the serial monitor, and see what the sensor value is. Now cover up the light sensor with you finger and see what the sensor value is. The sensor value should range from about 300 to about 750. 
* Update the minValue variable to the minimum sensor value you saw and update the maxValue to the maximum sensor value you saw. 
* Now we need a way of mapping the min and max values from the light sensor back to the range from 0 to 1023. We can do this with the <a href = http://arduino.cc/en/reference/map >map</a> command. 
* Click on the link and read the reference about how the map command works. 
Then update this line 

	delayTime = scaling*sensorValue;

to 

	delayTime = map (sensorValue, minValue, maxValue, 0, 1023);

The map function takes in the sensor values and scales it from its range (In this case from ~300 to ~750) to the orginal range we had (0 to 1023)
* Upload the code again and see how the min and max delay values are now in the orginal range and the blink rate behaves like it did before. 

* You are done with this tutorial! You can now go on to tutorial 3.