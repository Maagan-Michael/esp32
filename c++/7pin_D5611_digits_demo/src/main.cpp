#include <Arduino.h>
#include <iostream>
#include <list>


//you will need to figure out which pins to connect
//here is my setup


//  pin5 pin6 ground-pin pin7 pin8
//   26   19   --------   18   25



//   ===================
//  ||                 ||
//  ||                 ||
//  ||                 ||
//  ||                 ||
//  ||                 ||
//  ||                 ||
//   ===================
//  ||                 ||
//  ||                 ||
//  ||                 ||
//  ||                 ||
//  ||                 ||    oooooo
//  ||                 ||    oooooo
//   ===================     oooooo

//  pin1 pin2 ground-pin pin3 pin4
//   33   32   --------   5    27


const int l1 = 18;  
const int l2 = 19;
const int l3 = 25;
const int l4 = 26;
const int l5 = 32;
const int l6 = 33;
const int l7 = 5;
const int l8 = 27;


    // std::list<std::int> lst = {l1, l2, l3, l4, l5, l6, l7, l8};
      std::list<int> lst = {l1, l2, l3, l4, l5, l6, l7, l8 };
      
      std::list<int> n9 = {l1, l2, l3, l4, l5,  l7};
      std::list<int> n8 = {l1, l2, l3, l4, l5, l6, l7 };
      std::list<int> n7 = {l1, l3, l7};
      std::list<int> n6 = {l1, l2, l4, l5,l6,  l7};
      std::list<int> n5 = {l1, l2,  l4, l5,  l7};
      std::list<int> n4 = { l2, l3, l4,  l7};
      std::list<int> n3 = {l1,  l3 ,l4 ,l5,  l7};
      std::list<int> n2 = {l1,  l3 ,l4 ,l5,  l6};
      std::list<int> n1 = { l3, l7};
      std::list<int> n0 = {l1, l2, l3, l5, l6, l7 };

      std::list<int> dot = {l8};









void display_number(std::list<int> n_lst){

for (auto& var : n_lst) {
        digitalWrite(var,HIGH);
    }

 delay(1000);

 for (auto& var : lst) {
        digitalWrite(var,LOW);
    }

}

void setup() {

  Serial.begin(115200);
  while (!Serial) { }
  
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
  pinMode(l7, OUTPUT);
  pinMode(l8, OUTPUT);



  }

void loop() {

  display_number(n9);
  display_number(n8);
  display_number(n7);
  display_number(n6);
  display_number(n5);
  display_number(n4);
  display_number(n3);
  display_number(n2);
  display_number(n1);
  display_number(n0);
  display_number(dot);



}