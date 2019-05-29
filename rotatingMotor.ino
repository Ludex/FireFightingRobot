void rotatingMotor(){
   //make robot rotates in clockwise
   for(int x=motorDistance;x>0;x--){
    for(int j=0;j<8;j+2){
      analogWrite(motors[j],MotorDistance);
      }
      delay(100);
    }
     while(ultraSonicDistance[0,1]<50){
      analogWrite(motors[0],120);
      analogWrite(motors[2],120);
      }
  }
