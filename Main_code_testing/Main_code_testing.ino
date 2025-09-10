#include <HX711



// pin assignments
const int dirPin = 2 ;
const int stepPin = 3 ;
const int ms1 = 8;
const int ms2 = 9;
const int ms3 = 10; 
const int LCdat = 5;
const int LCclk = 6;

const int rotation = 3200; 

void setup() {
 pinMode(dirPin, OUTPUT);
 pinMode(stepPin, OUTPUT);
 pinMode(ms1, OUTPUT);
 pinMode(ms2, OUTPUT);
 pinMode(ms3, OUTPUT);
 //set microstepping values 
 //       ms1   ms2   ms3 
 // full: low   low   low 
 // 1/2:  high  low   low 
 // 1/4:  low   high  low 
 // 1/8:  high  high  low 
 // 1/16: high  high  high 
 digitalWrite(ms1, HIGH);
 digitalWrite(ms2, HIGH);
 digitalWrite(ms3, HIGH); 

 delay(2000);
}

void stepMotor(int steps, int delayUs) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delayUs);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delayUs);
  }
}

digitalWrite(dirPin, HIGH);
stepMotor(rotation, 150);


