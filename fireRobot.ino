#include<Servo.h>
void rotatingMotor();
void pumpFunc(int d,int echo);
int ultraSonicDistance(int e,int f);
int ultrasonic[4]={22,23,24,25};
int motors[8]={2,3,4,5,6,7,8,9};
int floatsensor;
int constFlame[4]={A0,A1,A2,A3};//analog inputs
int count;
int pumpRelay=26;
int servoPin=27;
int flameDistance[4]={};
int motorDistance;
int sonicRange;
Servo servo1;

void setup(){
  pinMode(ultrasonic[0],OUTPUT); //trig port for the front ultrasonic sensor
  pinMode(ultrasonic[1],INPUT); //echo port for the front ultrasonic sensor
  pinMode(ultrasonic[2],OUTPUT); //trig port for the back ultrasonic sensor
  pinMode(ultrasonic[3],INPUT); //echo port for the back ultrasonic sensor
 for(count=0;count<8;count++){
  pinMode(motors[count],OUTPUT);//though 4 motors but 8 pins since there is a forward and backward control
  //even indices are the forward movement while odd are backward
  }
  for(count=0;count<4;count++){
    pinMode(flame[count],INPUT);//loop throught the flame sensor input pins
    }
  for(motorDistance=0;motorDistance<=127;motorDistance++){
    for(int x=0;x<8;x+2){
      analogWrite(motors[x],count);
      delay(50);
      }
    }
 servo1.attach(servoPin);
  }
  
void loop(){
  for(int x=0;x<4;x++){
    flameDistance[x]=analogRead(flame[x]);
    constFlame[x]=constrain(flameDistance[x],0,255);
    delay(500);
    }
 if(ultraSonicDistance(0,1)>50 && ultraSonicDistance(2,3)>50){
   if(constFlame[0]>=15 ||constFlame[1]>=15||constFlame[2]>=15||constFlame[3]>=15){
   if(constFlame[0]>=15)pumpFunc(0,0);//front flame sensor
   if(constFlame[1]>=15)pumpFunc(1,0);//left flame sensor
   if(constFlame[2]>=15)pumpFunc(2,0);//back flame sensor
   if(constFlame[3]>=15)pumpFunc(3,0);//right flame sensor
    }
  }
  if((ultraSonicDistance[0,1]>50||ultrasonicDistance[0,1]<50) && constFlame[2]>=15 && ultraSonicDistance(2,3)>50){
     for(int z=91;z<=135;z++){
      servo1.write(z);
      delay(30);
      while(motorDistance>0){
        motorDistance-=3;
        delay(20);
        }
        motorDistance=0;
        for(motorDistance=0;motorDistance<255;motorDistance++){
          for(int j=0;j<8;j++){
            analogWrite(motors[j+1],motorDistance);
            delay(50);
            }
          }
    }
     if(constFlame[0]>=15 ||constFlame[1]>=15||constFlame[2]>=15||constFlame[3]>=15){
   if(constFlame[0]>=15)pumpFunc(0,2);//front flame sensor
   if(constFlame[1]>=15)pumpFunc(1,2);//left flame sensor
   if(constFlame[2]>=15)pumpFunc(2,2);//back flame sensor
   if(constFlame[3]>=15)pumpFunc(3,2);//right flame sensor
    }
  }
  if(ultraSonicDistance[0,1]<=50){
    rotatingMotor();
    }
  }
  
 

