# Arduino-Bluetooth-Communication
This is a project involving Arduino to Arduino Communication using two HC-05 Bleutooth modules

It has one Arduino sending info from a temperature sensor (Thermistor) to another Arduino that displays it on an LCD screen

This code assumes that all the AT-Command has been done already, if it hasn't, this website will teach you how to configure the modules
https://howtomechatronics.com/tutorials/arduino/how-to-configure-pair-two-hc-05-bluetooth-module-master-slave-commands/

The AT+UART? Command must return: +UART:38400,0,0. If it doesn't, use the command: AT+UART=38400
The Master Module must have the LCD Screen, and the Slave must have the temperature sensor

You also must Wire the LCD Screen and Temperature Sensor Yourself, here are some links for those:
LCD: https://www.arduino.cc/en/Tutorial/LibraryExamples/HelloWorld
Thermistor: https://thecustomizewindows.com/2020/10/temperature-sensor-using-ntc-thermistor-arduino-ntc/

Note the ports used in the code for the LCD screen. Since ports 0 and 1 are used by the bluetooth module, 
