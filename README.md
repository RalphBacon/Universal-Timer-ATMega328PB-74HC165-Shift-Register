# Universal Timer ATMega328PB 74HC165 Shift-Register

$2 for PCB Prototype (*Any Colour*): https://jlcbcb.com

# See https:///www.youtube.com/ralphbacon video #161
### (Direct link to video: https://youtu.be/k0UQa5S1DzU)

A Universal Timer (or whatever you want) using an ATMega328PB (yes, PB not P) and a simple chip on the SPI bus - easy!
This project started life as a simple replacement timer for my toothbrush, now it's a universal timer with various options.

<img src="images/PCB Front - 3D Draft.JPG" align="right" width="50%">  

A simple 2 minute timer project has turned into a universal timer with DIP switches, a 74HC165 chip that allows you to read 8 switches and put the value on the SPI bus, a beeper, an LED... and we can use **EITHER** an **ATMega328P** (as found in all Arduino UNO and Nanos) **OR** the newer **ATMEGA328PB** which has an additonal SPI and I2C bus, plus an extra USART. Just for starters. For a full list of all the differences see the detailed spec sheet in the GitHub!

### I need your help!
Let me know how you would change this PCB (which has already changed since the video was made).

It now breaks out the additional SPI bus, as well as the original I2C bus. It already has the ICSP header (for programming using something like an USBAP v2.0) and Serial header (for the USB-to-Serial adapter).

I've uploaded a zipped copy of the EasyEDA project that you can use to look at the project so far.
<table>
  <tr>
    <td width="50%"><img src="images/Circuit Diagram - Draft.JPG" align="left" ></td>
    <td><img src="images/PCB Front - Draft.JPG" align="right"></td>
  </tr>
</table>

### Some useful links   

**DIP switches** (8 position shown, they do **all** sizes)  
http://s.click.aliexpress.com/e/N3nDl3BK  

**ATMega328PB** the improved version of the one found in your Arduino UNO board  
https://lcsc.com/product-detail/MICROCHIP_MICROCHIP_ATMEGA328PB-AU_ATMEGA328PB-AU_C132230.html  

Super loud 5v active **Beepers** (just connect to GPIO pin)   
https://www.banggood.com/5-PCS-Super-Loud-5V-Active-Alarm-Buzzer-Beeper-Tracker-95_5mm-for-Racing-Drone-p-1117207.html?p=FQ040729393382015118&utm_campaign=25129675&utm_content=3897

More **Beepers** but these are PASSIVE - send them a PWM signal or just use Arduino **tone** statement  
https://www.banggood.com/10pcs-3V-12V-Buzzer-16R-Resistance-AC-Passive-Buzzer-12085-p-1435460.html??p=FQ040729393382015118&utm_campaign=25129675&utm_content=3897

### List of all my videos
(Special thanks to Michael Kurt Vogel for compiling this)
http://bit.ly/VideoList-RalphBacon

If you like this video please give it a thumbs up, share it and if you're not already subscribed please consider doing so and joining me on my Arduinite journey

My channel and blog are here:  
------------------------------------------------------------------  
https://www.youtube.com/RalphBacon  
https://ralphbacon.blog  
------------------------------------------------------------------
