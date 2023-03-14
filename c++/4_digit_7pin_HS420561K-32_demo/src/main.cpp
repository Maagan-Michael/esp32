#include <Arduino.h>
#include <iostream>
#include <list>


const int segment_a = 12;  // the number of the pushbutton pin
const int segment_b = 13;  // the number of the pushbutton pin
const int segment_c = 14;  // the number of the pushbutton pin
const int segment_d = 15;  // the number of the pushbutton pin
const int segment_e = 16;  // the number of the pushbutton pin
const int segment_f = 17;  // the number of the pushbutton pin
const int segment_g = 18;  // the number of the pushbutton pin

const int d1 = 21;  // the number of the pushbutton pin

const int d2 = 22;  // the number of the pushbutton pin

const int d3 = 23;  // the number of the pushbutton pin

const int d4 = 25;  // the number of the pushbutton pin

const int decimal = 32;  // the number of the pushbutton pin



// std::list<std::int> lst = {l1, l2, l3, l4, l5, l6, l7, l8};
std::list<int> off = {};
std::list<int> lst = {segment_a,segment_b,segment_c,segment_d,segment_e,segment_f,segment_g};
std::list<int> n0 = { segment_a, segment_b, segment_c, segment_d, segment_e, segment_f };
std::list<int> n1 = { segment_b, segment_c };
std::list<int> n2 = { segment_a, segment_b, segment_g, segment_e, segment_d };
std::list<int> n3 = { segment_a, segment_b, segment_g, segment_c, segment_d };
std::list<int> n4 = { segment_f, segment_g, segment_b, segment_c };
std::list<int> n5 = { segment_a, segment_f, segment_g, segment_c, segment_d };
std::list<int> n6 = { segment_a, segment_f, segment_g, segment_e, segment_c, segment_d };
std::list<int> n7 = { segment_a, segment_b, segment_c };
std::list<int> n8 = { segment_a, segment_b, segment_c, segment_d, segment_e, segment_f, segment_g };
std::list<int> n9 = { segment_a, segment_b, segment_c, segment_d, segment_f, segment_g };

      std::list<int> dot = {decimal};



void set_pins(){
  pinMode(segment_a, OUTPUT);
  pinMode(segment_b, OUTPUT);
  pinMode(segment_c, OUTPUT);
  pinMode(segment_d, OUTPUT);
  pinMode(segment_e, OUTPUT);
  pinMode(segment_f, OUTPUT);
  pinMode(segment_g, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(decimal, OUTPUT);

}


void display_number(std::list<int> n_lst){

for (auto& var : n_lst) {
        digitalWrite(var,HIGH);
    }

 delay(1);

 for (auto& var : lst) {
        digitalWrite(var,LOW);
    }

}


void show_number(std::list<int> n_lst1,std::list<int> n_lst2, std::list<int> n_lst3, std::list<int> n_lst4){
  std::list<std::list<int>> all_digits = {n_lst1, n_lst2, n_lst3, n_lst4};
  int count = 0; 
      for (auto& var : all_digits) {
        count = count+1;

   if(count == 1){
    digitalWrite(d1,LOW);
    digitalWrite(d2,HIGH);
    digitalWrite(d3,HIGH);
    digitalWrite(d4,HIGH);
    } else if(count == 2){
      digitalWrite(d1, HIGH);
      digitalWrite(d2,LOW);
      digitalWrite(d3,HIGH);
      digitalWrite(d4,HIGH);         
    }else if(count == 3){
      digitalWrite(d1, HIGH);
      digitalWrite(d2,HIGH);
      digitalWrite(d3,LOW);
      digitalWrite(d4,HIGH);         
    }
    else if(count == 4){
      digitalWrite(d1, HIGH);
      digitalWrite(d2,HIGH);
      digitalWrite(d3,HIGH);
      digitalWrite(d4,LOW);         
    }

      
        display_number(var) ;
   }  


}

void show_numbers(int time_in_miliseconds){
    std::list<std::list<int>> all_lists = {n0,n1,n2,n3,n4,n5,n6,n7,n8,n9};

   for (auto& thousands : all_lists) {
         for (auto& hundreds : all_lists) {
         for (auto& tens: all_lists) {
         for (auto& singles : all_lists) {

//how long before replacing the next digit
for(int i = 0; i < time_in_miliseconds; i++){
  show_number(thousands,hundreds,tens,singles);
          delay(1);

          }

        
        
}
}
}
}
}

void setup() {
  // Start the Serial communication
  Serial.begin(115200);

 
  while (!Serial) {}

  set_pins();
}
void loop() {
// show_number(n1,n9,n7,n9);
show_numbers(50);


}



