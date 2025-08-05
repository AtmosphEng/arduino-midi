/**
 * @file serial-receive.ino
 * @author Phil Schatzmann
 * @brief Receive MIDI messages from Serial port - see https://www.pschatzmann.ch/home/2021/12/22/esp32-audiokit-and-midi-using-serial/
 * @date 2021-12-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Midi.h"
//#include "../../src/Midi.h"

#include <BLEClient.h>

//#define RXD2 21
//#define TXD2 22
#define RXD2 2 // t-display-s3 Serial2
#define TXD2 3 // t-display-s3 Serial2

#define MYSERIAL Serial2

MidiCallbackAction action;
MidiStreamIn in(Serial, action); // uses default Serial port.

void onNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  MYSERIAL.print("onNoteOn: ");
  MYSERIAL.println(note);
}

void onNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  MYSERIAL.print("onNoteOff: ");
  MYSERIAL.println(note);
}

void setup() {
#if 0
	Serial.begin(119200);
  Serial2.begin(119200, SERIAL_8N1, RXD2, TXD2);
#else
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
#endif
	delay(500);
	pinMode(15, OUTPUT); // aaa Added for battery operation to turn on the display backlight for t-display-s3
  digitalWrite(15, HIGH); // aaa Added for battery operation to turn on the display backlight for t-display-s3

	Serial.println("Hello 1 from serial-receive.ino setup()"); // aaa
	Serial.println("Hello 2 from serial-receive.ino setup()"); // aaa
	Serial.println(); // aaa

	Serial2.println("Hello 21 from serial-receive.ino setup()"); // aaa
	Serial2.println("Hello 22 from serial-receive.ino setup()"); // aaa
	Serial2.println(); // aaa

  action.setCallbacks(onNoteOn, onNoteOff);
}

void loop() {
  if (!in.loop()){
    delay(10);
  }
}
