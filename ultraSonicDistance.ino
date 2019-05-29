int ultraSonicDistance(int e,int f){
  digitalWrite(ultrasonic[e],HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonic[e],LOW);
  sonicRange= pulseIn(ultrasonic[f],HIGH)/29/2;  
  return sonicRange;
  }
