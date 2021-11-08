# Arduino-Bluetooth-Communication
This is a project involving Arduino to Arduino Communication using two HC-05 Bleutooth modules

It has one Arduino sending info from a temperature sensor to another Arduino that displays it on an LCD screen

This code assumes that all the AT-Command has been done already, if it hasn't, this website will teach you how to configure the modules
https://howtomechatronics.com/tutorials/arduino/how-to-configure-pair-two-hc-05-bluetooth-module-master-slave-commands/

NOTE: The AT+UART? Command must return: +UART:38400,0,0. If it doesn't, use the command: AT+UART=38400
NOTE 2: 
