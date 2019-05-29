 void pumpFunc(int d,int echo){
    digitalWrite(pumpRelay,HIGH);
    if(d==0){//front sensor
     if(echo==0){
       for(int z=0;z<=45;z++){
      servo1.write(z);
      delay(30);
      motorDistance+=2;
    }
      }
    if(echo==2){
        for(int z=0;z<=45;z++){
      servo1.write(z);
      delay(30);}
      while(motorDistance>0){
        motorDistance-=3;
        delay(20);
        }
        motorDistance=0;
        for(motorDistance=0;motorDistance<255;motorDistance++){
          for(int j=0;j<8;j++){
            analogWrite(motors[j],motorDistance);
            delay(50);
            }
          }
      }
      }
    if(d==1){//left sensor
      for(int z=46;z<=90;z++){
      servo1.write(z);
      delay(30);
        }
      }
    if(d==2){//back sensor
 if(echo==0){
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
  }
  if(echo==2){
       for(int z=136;z<=180;z++){
      servo1.write(z);
      delay(30);
      motorDistance+=2;    
    }
      }  
    if(d==3){//right sensor
      for(int z=136;z<=180;z++){
      servo1.write(z);
      delay(30);
        }
      }
    }
