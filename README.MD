# Keylogger
### CS460 Project
Beatriz Torreiro, Ignacio Díaz-Guardamino
## keylogger.ino
This file is the arduino code in charge of injecting the keylogger file into the victim's windows machine.\
It is emulating a keyboard and generating keypresses in a predefined sequence so that as soon as it is pluged to the victim's computer, opens a command line and create a python file in a specific directory so that windows runs it on boot.\
It also installs the required library in case it is not already installed. When finished, it runs the keylogger and closes all window to avoid the victim noticing.

This program has been designed for a Atmega32u4 microcontroller and other arduino compatible microprocessors with built in USB capable of emulating Human Interface Devices (HID).


## pythonKeylogger.pyw
This is the python code that the previous program injects.\
It records the letters typed and as soon as the victim hits enter it will make a get request to a server with the text typed.\
The server created through an online service (ifttt) will send a Telegram message with the text typed by the victim.