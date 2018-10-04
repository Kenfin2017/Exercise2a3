
#include <Arduino.h>



int pinA = 2;
int pinF = 3;
int pinE = 4;
int pinD = 5;
int pinC = 6;
int pinG = 7;
int pinB = 8;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);


}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pinA, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(pinB, LOW); 
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
  delay(1000);          
  digitalWrite(pinA, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  delay(1000);

}


  
