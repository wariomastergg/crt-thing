#include <Stepper.h>

const int stepsPerRevolution = 2048; // Number of steps per output rotation

// Create Instance of Stepper library
Stepper stepper1(stepsPerRevolution, 11, 10, 9, 8);
Stepper stepper2(stepsPerRevolution, 4, 5, 6, 7);
float pi = 3.141592;
int pos[2] = {0,0};
void gopos(int x, int y){
  stepper1.step(x - pos[0]);
  stepper2.step(y - pos[1]);
  pos[0] = x;
  pos[1] = y;
}

void setup(){
  stepper1.setSpeed(8); // set the speed at 8 rpm
  stepper2.setSpeed(8);
  Serial.begin(9600); // initialize the serial port
  //stepper1.step(-(int)(stepsPerRevolution*3.25));
  //stepper2.step(-(int)(stepsPerRevolution*2.25));
  //gopos(3000,3000);
  for (int i = 0; i < 1000; i++){
    float period = ((i/1000.)*2.*pi);
    gopos( round(cos( period*5 ) * 2000) , round(sin( period*4 ) * 2000) );
  }
  gopos(0,0);
}

void loop(){
  
  // step one revolution in one direction:
  //Serial.println("clockwise");
  //stepper1.step(-stepsPerRevolution);
  delay(100);

}


//void setup() {
//  // put your setup code here, to run once:
//
//}
//int a = 9;
//int b = 8;
//int c = 7;
//int d = 6;
//int del = 100;
//void loop() {
//  digitalWrite(a,HIGH);
//  digitalWrite(a,LOW);
//  digitalWrite(a,LOW);
//  digitalWrite(a,LOW);
//  delay(del);
//  digitalWrite(a,LOW);
//  digitalWrite(a,HIGH);
//  digitalWrite(a,LOW);
//  digitalWrite(a,LOW);
//  delay(del);
//  digitalWrite(a,LOW);
//  digitalWrite(a,LOW);
//  digitalWrite(a,HIGH);
//  digitalWrite(a,LOW);
//  delay(del);
//  digitalWrite(a,LOW);
//  digitalWrite(a,LOW);
//  digitalWrite(a,LOW);
//  digitalWrite(a,HIGH);
//  delay(del);
//
//}
//