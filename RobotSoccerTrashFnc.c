int updateSpeed(char command, int pwmDutyCycle){
  
  if (command == '0') {
    pwmDutyCycle = 0;
    Serial.println("Stop");
  }
  else if (command == '1') {
    speed = 10;
    Serial.print("Speed = ");
    Serial.print(speed);
    Serial.println("%");
    pwmDutyCycle = 26;
  }
  else if (command == '2') {
    pwmDutyCycle = 51;
    speed = 20;
    Serial.print("Speed = ");
    Serial.print(speed);
    Serial.println("%");
  }
  else if (command == '3') {
    pwmDutyCycle = 77;
    speed = 30;
    Serial.print("Speed = ");
    Serial.print(speed);
    Serial.println("%");
  }
  else if (command == '4') {
    pwmDutyCycle = 102;
    speed = 40;
    Serial.print("Speed = ");
    Serial.print(speed);
    Serial.println("%");
  }
  else if (command == '5') {
    pwmDutyCycle = 128;
    speed = 50;
    Serial.print("Speed = ");
    Serial.print(speed);
    Serial.println("%");
  }
  else if (command == '8') {
    pwmDutyCycle = 205;
    speed = 80;
    Serial.print("Speed = ");
    Serial.print(speed);
    Serial.println("%");
  }

}

void interruptPinChange(){
  
  // Log the time of the interrupt
  interruptTime[dataLength] = micros();
  
  // Record the pin state
  interruptState[dataLength] = (digitalRead(interruptPin) == HIGH);
  
  // Increment the length of the data log
  if (dataLength < 19) dataLength++;
  
}
