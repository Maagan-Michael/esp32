#include <Arduino.h>


/*
pin1 => column 4
pin2 => column 2
pin3 => row 2
pin4 => row 3
pin5 => column 1
pin6 => column 3
pin7 => row 5
pin8 => column 6

other side:

pin9 => column 8
pin10 => row 4
pin11 => row 6
pin12 => column 5
pin13 => row 1
pin14 => column 7
pin15 => row 7
pin16 => row 8



*/
// Mario's Ideas
// Testing all 64 leds in 8x8 LED matrix by lighting   them up one by one

// Raws 
#define R1 25
#define R2 0
#define R3 4
#define R4 35
#define R5 5
#define R6 32
#define R7 27
#define R8 14
//Columns
#define C1 16
#define C2 2
#define C3 17
#define C4 15
#define C5 33
#define C6 18
#define C7 26
#define C8 34



void   setup() {
   pinMode(R1, OUTPUT);
   pinMode(R2, OUTPUT);
   pinMode(R3,  OUTPUT);
   pinMode(R4, OUTPUT);
   pinMode(R5, OUTPUT);
   pinMode(R6,   OUTPUT);
   pinMode(R7, OUTPUT);
   pinMode(R8, OUTPUT);
   pinMode(C1,   OUTPUT);
   pinMode(C2, OUTPUT);
   pinMode(C3, OUTPUT);
   pinMode(C4,   OUTPUT);
   pinMode(C5, OUTPUT);
   pinMode(C6, OUTPUT);
   pinMode(C7,   OUTPUT);
   pinMode(C8, OUTPUT);
// Turning all the LEDs off at the start   of the sketch
  digitalWrite(R1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(R3,LOW);
   digitalWrite(R4,LOW);
  digitalWrite(R5,LOW);
  digitalWrite(R6,LOW);
   digitalWrite(R7,LOW);
  digitalWrite(R8,LOW);
  digitalWrite(C1,HIGH);
   digitalWrite(C2,HIGH);
  digitalWrite(C3,HIGH);
  digitalWrite(C4,HIGH);
   digitalWrite(C5,HIGH);
  digitalWrite(C6,HIGH);
  digitalWrite(C7,HIGH);
   digitalWrite(C8,HIGH);
}



void SelectRow(int row){
  if (row==1)   digitalWrite(R1,HIGH); else digitalWrite(R1,LOW);
  if (row==2) digitalWrite(R2,HIGH);   else digitalWrite(R2,LOW);
  if (row==3) digitalWrite(R3,HIGH); else digitalWrite(R3,LOW);
   if (row==4) digitalWrite(R4,HIGH); else digitalWrite(R4,LOW);
  if (row==5)   digitalWrite(R5,HIGH); else digitalWrite(R5,LOW);
  if (row==6) digitalWrite(R6,HIGH);   else digitalWrite(R6,LOW);
  if (row==7) digitalWrite(R7,HIGH); else digitalWrite(R7,LOW);
   if (row==8) digitalWrite(R8,HIGH); else digitalWrite(R8,LOW);
}

void   SelectColumn(int column){
  if (column==1) digitalWrite(C1,LOW); else digitalWrite(C1,HIGH);
   if (column==2) digitalWrite(C2,LOW); else digitalWrite(C2,HIGH);
  if (column==3)   digitalWrite(C3,LOW); else digitalWrite(C3,HIGH);
  if (column==4) digitalWrite(C4,LOW);   else digitalWrite(C4,HIGH);
  if (column==5) digitalWrite(C5,LOW); else digitalWrite(C5,HIGH);
   if (column==6) digitalWrite(C6,LOW); else digitalWrite(C6,HIGH);
  if (column==7)   digitalWrite(C7,LOW); else digitalWrite(C7,HIGH);
  if (column==8) digitalWrite(C8,LOW);   else digitalWrite(C8,HIGH);

}


void loop() {
  for (int i=1;i<9;i++)   {
    for (int j=1;j<9;j++){
      SelectRow(i);
      SelectColumn(j);   
      delay(200);
    }
  }
}
