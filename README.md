# Universal Timer ATMega328PB 74HC165 Shift-Register
A Universal Timer (or whatever you want) using an ATMega328PB and a simple chip on the SPI bus - easy!

This project started life as a simple replacement timer for my toothbrush, now it's a universal timer with various options.

[Sponsor]

A simple 2 minute timer project has turned into a universal timer with DIP switches, a 74HC165 chip that allows you to read 8 switches and put the value on the SPI bus, a beeper, an LED... and we can use **EITHER** an ATMega328P (as found in all Arduino UNO and Nanos) **OR** the newer ATMEGA328PB which has an additonal SPI and I2C bus, plus an extra USART. Just for starters. For a full list of all the differences see the detailed spec sheet in the GitHub!

### I need your help!
Let me know how you would change this PCB (which has already changed since the video was made).

It now breaks out the additional SPI bus, as well as the original I2C bus. It already has the ICSP header (for programming using something like an USBAP v2.0) and Serial header (for the USB-to-Serial adapter).

I've uploaded a zipped copy of the EasyEDA project that you can use to look at the project so far.

