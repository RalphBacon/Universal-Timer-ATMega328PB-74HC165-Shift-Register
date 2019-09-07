/* Demo for the 74HC165 shift register chip that allows multiple INPUT pins (switches)
 * to be used on the standard SPI bus, thus saving pins on the Arduino ATMega328P.
 *
 * Connection details:
 *
 * See video #161 www.youtube.com/ralphbacon which has full details.
 *
 * 74HC165		Arduino Uno Pin
 * ---------	--------------------
 * 	1 Shift/Load see PULSE pin below
 * 	2 CLK		SPI CLK Pin D13
 * 	9 QH		SPI MOSI Pin D12
 * 	16			VCC (5V) Works with 2-5V Absolute MAX 6V
 * 	8			GND
 * 	15			GND or SS pin of your choice (default 10) goes LOW to enable
 *
 * Additionally (MUST be kept in this order)
 * 	11 - 14		DIP Switches A - D
 *  3 - 6		DIP Switches E - H
 *
 *  SPI data will return a single byte with each bit representing a single switch condition.
 *  	76543210 - bits
 *  eg 	00001001 means switches 1 (far right) and 4 (middle) are set (ON)
 *
 */

#include <SPI.h>
#include "sketch.h"

// We will pulse the 74HC165 on this pin to load the new config
// When LOW data is loaded from parallel inputs (see data sheet)
// You can use any pin, this is the next one after the SPI pins.
const byte PULSE = 9;

// Hold the values of the DIL switches in a single (8-bit) byte
byte dilSwitches;

// This is what they were last time we read them
byte prevDilSwitches = 255;

// Forward declarations
void printBitPattern(byte optionSwitch);
void playTune();

// SETUP    SETUP   SETUP
void setup()
{
	// Debugging messages
	Serial.begin(9600);

	// SPI but the target is always enabled in this demo
	SPI.begin();

	// This is the pin we're using to make the 74HC165 'load' the values
	pinMode(PULSE, OUTPUT);

	// It's active LOW so switch off for now
	digitalWrite(PULSE, HIGH);

	// We're not using the standard SS/CE pin for SPI so just testing it here
	pinMode(10, OUTPUT);
	digitalWrite(10, LOW);

	// All done
	Serial.println("\nSet up completed.");
}

// LOOP    LOOP    LOOP    LOOP
void loop()
{
	// Tell the 74HC165 to read the values on pins A-H by pulsing the
	digitalWrite(PULSE, LOW);
	delayMicroseconds(5);
	digitalWrite(PULSE, HIGH);

	// Now tell SPI to transfer the data from it to the µC
	dilSwitches = SPI.transfer(0);

	// Has there been ANY change in the DIP switches? Print out if so, in binary.
	if (dilSwitches != prevDilSwitches) {
		printBitPattern(dilSwitches);
	}

	//Has the individual bit changed? Display its state.
	byte maskValue = 1;
	for (auto i = 7; i > 3; i--) {
		if ((dilSwitches & maskValue) != (prevDilSwitches & maskValue))
			{
			Serial.print("DIP ");
			Serial.print(8-i);
			Serial.print(" state: ");
			Serial.println((dilSwitches & maskValue) ? "ON" : "OFF");
		}
		maskValue <<= 1;
	}

	prevDilSwitches = dilSwitches;
	delay(10);
}

// Print the pattern of the switches in binary for demo purposes
void printBitPattern(byte optionSwitch) {

	// We only have a 4-position switch for demo purposes and only the last
	// 3 are used so only start checking from that position
	byte maskValue = 0b00000100;

	// Decimal equivalent value of the switches on the SPI bus
	byte decValue = 0;

	// I'm using the first switch/bit for a special value
	// Binary value is 1000 so AND that with the value to see if it's set
	// Yes this is all binary arithmetic, very simple, watch the video!
	if (optionSwitch & 0b1000) {
		Serial.print("Special flag set + ");
	}

	// For all the other bits AND them one by one to see if they are set
	for (auto cnt = 5; cnt < 8; cnt++) {
		if (optionSwitch & maskValue) {
			Serial.print("1");
			decValue += maskValue;
		} else {
			Serial.print("0");
		}

		// Move the "1" in the mask one position to the RIGHT, so for example
		// 0000 0100 becomes 0000 0010
		maskValue >>= 1;
	}

	// Print out the equivalent decimal value on the SPI bus just for demo
	Serial.print(" (decimal ");
	Serial.print(decValue);
	Serial.println(")");

	// We are not using pin 10 (the default SPI SS/CE pin) so use it here for beeper to
	// show it still works as a normal GPIO pin
	digitalWrite(10, HIGH);
	delay(30);
	digitalWrite(10, LOW);
	delay(100);

	// Just for fun play a PWM tune on pin GPIO 6
	playTune();
}

// Unashamedly stolen from the Arduino playground site
// https://www.arduino.cc/en/Tutorial/ToneMelody?from=Tutorial.Tone
// I've just changed the notes a bit to make it more audible using a piezo
void playTune() {
	// notes in the melody:
	int melody[] = { NOTE_C7, NOTE_G6, NOTE_G6, NOTE_A6, NOTE_G6, 0, NOTE_B6, NOTE_C7 };

	// note durations: 4 = quarter note, 8 = eighth note, etc.:
	int noteDurations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };

	// iterate over the notes of the melody:
	for (int thisNote = 0; thisNote < 8; thisNote++) {

		// to calculate the note duration, take one second divided by the note type.
		//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
		int noteDuration = 1000 / noteDurations[thisNote];
		tone(6, melody[thisNote], noteDuration);

		// to distinguish the notes, set a minimum time between them.
		// the note's duration + 30% seems to work well:
		int pauseBetweenNotes = noteDuration * 1.30;
		delay(pauseBetweenNotes);

		// stop the tone playing:
		noTone(6);
	}
}
