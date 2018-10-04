/************************************************************************/
/*  
Name:         Exercise2a3
Author:       Minh Nguyen, Ajit Bahadur Thapa
Description:  Display 7-segment with different sequence
*/
/************************************************************************/
#include <Arduino.h>

void SevenSegWrite(byte i, byte* seq7);

#define PIN_A 2
#define PIN_F 3
#define PIN_E 4
#define PIN_D 5
#define PIN_C 6
#define PIN_G 7
#define PIN_B 8

byte seven_seg_3_and_E[2][7] = { 
  { 1,0,0,1,1,1,1 }, // = 3
  { 1,1,1,1,0,1,0 } // = E
};

byte seven_seg_counter_clockwise[6][7] = {
  { 1,0,0,0,0,0,0 }, // = A
  { 0,1,0,0,0,0,0 }, // = F
  { 0,0,1,0,0,0,0 }, // = E
  { 0,0,0,1,0,0,0 }, // = D
  { 0,0,0,0,1,0,0 }, // = C
  { 0,0,0,0,0,0,1 } // = B
};

byte seven_seg_clockwise[6][7] = {
  { 1,0,0,0,0,0,0 }, // = A
  { 0,0,0,0,0,0,1 }, // = B
  { 0,0,0,0,1,0,0 }, // = C
  { 0,0,0,1,0,0,0 }, // = D
  { 0,0,1,0,0,0,0 }, // = E
  { 0,1,0,0,0,0,0 } // = F
};

byte seven_seg_on_off[8][7] = {
  { 1,1,1,1,1,1,1 }, // All ON
  { 0,1,1,1,1,1,1 }, // A OFF
  { 0,1,1,1,1,1,0 }, // A, B OFF
  { 0,1,1,1,0,1,0 }, // A, B, C OFF
  { 0,1,1,0,0,1,0 }, // A, B, C, D OFF
  { 0,1,1,0,0,0,0 }, // A, B, C, D, G OFF
  { 0,1,0,0,0,0,0 }, // A, B, C, D, G, E OFF
  { 0,0,0,0,0,0,0 }, // All OFF
};

void setup() {
  pinMode(PIN_A,OUTPUT); // A
  pinMode(PIN_F,OUTPUT); // F
  pinMode(PIN_E,OUTPUT); // E
  pinMode(PIN_D,OUTPUT); // D
  pinMode(PIN_C,OUTPUT); // C
  pinMode(PIN_G,OUTPUT); // G
  pinMode(PIN_B,OUTPUT); // B
  
}
// write to each pins on 7-segment
void SevenSegWrite(byte i, byte seq [][7]) {
  byte pin = 2;
  // loop through all pins
  for (byte segCount = 0; segCount < 7; ++segCount) { 
    digitalWrite(pin, !seq[i][segCount]);
    ++pin;
  }
}
void loop() {
  /* number 3 and E */
  int delayTime = 700;
  for (byte j = 0; j < 3; j++){
    for (byte i = 0; i < 2; i++){
      SevenSegWrite(i, seven_seg_3_and_E);
      delay(delayTime);
    }
    delayTime -= 200;// delay time reduce each loop
  }
  delay(2000);

  delayTime = 700;
  /* counter clockwise blink */ 
  for (byte j = 0; j < 3; j++){
    for (byte i = 0; i < 6; i++){
      SevenSegWrite(i, seven_seg_counter_clockwise);
      delay(delayTime);
    }
    delayTime -= 200;
  }
  delay(2000);
  
  delayTime = 700;
  /* turning off one by one */
  for (byte j = 0; j < 3; j++){
    for (byte i = 0; i < 8; i++){
      SevenSegWrite(i, seven_seg_on_off);
      delay(delayTime);
    }
    delayTime -= 200;
  }
  delay(2000);
  
  delayTime = 700;
  /* clockwise blink */
  for (byte j = 0; j < 3; j++){
    for (byte i = 0; i < 6; i++){
      SevenSegWrite(i, seven_seg_clockwise);
      delay(delayTime);
    }
    delayTime -= 200;
  }
}
