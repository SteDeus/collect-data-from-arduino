# Collect data from arduino

Collect data from arduino sensors

## Instructions

At the moment the script just logs the outputted values from arduino.
In order to do so, use Arduino IDE to load detected temerature & humidity.
Then close Arduino IDE so no othe sw is listening to it.

Adjust values on server.js to connect it to the arduino and define the method to push data to the desired db/server.
