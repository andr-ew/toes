#include <Bounce2.h>
#include <MIDI.h>
#include "config.h"

// MIDI 
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

int cc_mapped = 0;              // reading mapped to 0-127              

// debouncing
Bounce sw1 = Bounce(2, 5); // debounce pin 2, 5ms debounce time
Bounce sw2 = Bounce(3, 5); // debounce pin 3, 5ms debounce time
Bounce sw3 = Bounce(4, 5); // debounce pin 4, 5ms debounce time
Bounce sw4 = Bounce(5, 5); // debounce pin 5, 5ms debounce time

void setup() {
  MIDI.begin();
  // switches
  pinMode(2, INPUT_PULLUP);  // SW1
  pinMode(3, INPUT_PULLUP);  // SW2
  pinMode(4, INPUT_PULLUP);  // SW3
  pinMode(5, INPUT_PULLUP);  // SW4
}

void loop() {
  // switch reading
  sw1.update();
  sw2.update();
  sw3.update();
  sw4.update();

  // switch MIDI messages
  if (sw1.fallingEdge()) {
    usbMIDI.sendNoteOn(note1, 99, midi_out_channel);  
    MIDI.sendNoteOn(note1, 99, midi_out_channel);
  }
  if (sw1.risingEdge()) {
    usbMIDI.sendNoteOff(note1, 0, midi_out_channel);
    MIDI.sendNoteOff(note1, 0, midi_out_channel); 
  }
  if (sw2.fallingEdge()) {
    usbMIDI.sendNoteOn(note2, 99, midi_out_channel);  
    MIDI.sendNoteOn(note2, 99, midi_out_channel);
  }
  if (sw2.risingEdge()) {
    usbMIDI.sendNoteOff(note2, 0, midi_out_channel);
    MIDI.sendNoteOff(note2, 0, midi_out_channel); 
  }
  if (sw3.fallingEdge()) {
    usbMIDI.sendNoteOn(note3, 99, midi_out_channel);  
    MIDI.sendNoteOn(note3, 99, midi_out_channel);
  }
  if (sw3.risingEdge()) {
    usbMIDI.sendNoteOff(note3, 0, midi_out_channel);
    MIDI.sendNoteOff(note3, 0, midi_out_channel); 
  }
  if (sw4.fallingEdge()) {
    usbMIDI.sendNoteOn(note4, 99, midi_out_channel);  
    MIDI.sendNoteOn(note4, 99, midi_out_channel);
  }
  if (sw4.risingEdge()) {
    usbMIDI.sendNoteOff(note4, 0, midi_out_channel);
    MIDI.sendNoteOff(note4, 0, midi_out_channel); 
  }

  while (usbMIDI.read()) {
  // ignore incoming messages
  }
}
