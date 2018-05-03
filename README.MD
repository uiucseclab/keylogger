# Keylogger
### CS460 project
Beatriz Torreiro, Ignacio Díaz-Guardamino
## keylogger.ino
This file is the arduino code in charge of injecting the keylogger file into the victim's windows machine.\
It is emulating a keyboard and generating keypresses in a predefined sequence so that as soon as it is pluged to the victim's computer, opens a command line and create a python file in a specific directory so that windows runs it on boot.\

This file requires a Atmega32u4 microcontroler or a different arduino compatible microprocessor with built in USB capable of emulaing Human Interface Devices (HID).


## pythonKeyloger.pyw
This is the python code that the previous program injects.\
It recods the letters typed and as soon as the victim hits enter it will make a get request to a server with the text typed.\
The server created through an online service (ifttt) will send a Telegram message with the text typed by the victim.