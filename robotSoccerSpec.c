//robot soccer project spec


//global variables
   int leftSense = 2;
   int rightSense = 3;
   int interruptNo1 = 0;
   int interruptNo2 = 1;

   int baseT = 0; 
   int Ltime = 0;
   int Rtime = 0;

   int Lbreak = 0;
   int Rbreak = 0;

   int LTickBase = 0;
   int RTickBase = 0;
   //pin distance values 
   int leftTicks = 0;
   int rightTicks = 0;

   char Direction = 'r';
   char changeCheck = 'a';

   int pwmDutyCycle = 128;
    
void setup(){  
  
  // Set up the pins
  pinMode(rightSense, INPUT); 
  pinMode(leftSense, INPUT);

  initializeMotorPins();
  // initialize the serial communications
  Serial.begin(9600); 
  Serial.println("Initialised");
  
}



void loop(){
  //record left signal
  baseT = micros();

  while (Ltime < 3000 && Lbreak == 0) {
    Ltime = micros() - baseT;
    if (digitalRead(leftSense) == HIGH) LTickBase = micros();
    while (digitalRead(leftSense) == HIGH) {
      Lbreak++;
    }
    if (Lbreak != 0) leftTicks = micros() - LTickBase;
  }

  //record right signal
  baseT = micros();

  while (Rtime < 3000 && Rbreak == 0) {
    Rtime = micros() - baseT;
    if (digitalRead(rightSense) == HIGH) RTickBase = micros();
    while (digitalRead(rightSense) == HIGH) {
      Rbreak++;
    }
    if (Rbreak != 0) rightTicks = micros() - RTickBase;
  }

  char order = directionCheck(rightTicks, leftTicks);
  direction = updateDirection(order);

  if (direction != changeCheck) {
    setMotorPins(direction);
  }
  

  
}



//---------------
//   Functions
//---------------



char directionCheck(int right, int left){
   char command = 'u';
   
   if (right != 0 && left == 0) {
      command = 'r'
   }
   else if (right == 0 && left != 0) {
      command = 'l';
   }
   else if (left > 0 && right > 0) {
      command = 'f';
   }

   return command;
}



void initializeMotorPins(){
  
  // Configuration the motor pins

  pinMode(rightMotorLogicPin1, OUTPUT);
  pinMode(rightMotorLogicPin2, OUTPUT);
  pinMode(leftMotorLogicPin1, OUTPUT);
  pinMode(leftMotorLogicPin2, OUTPUT); 

  // Print the motor pin configuration for wiring

  Serial.print("Right Motor Pin 1 = ");
  Serial.println(rightMotorLogicPin1);

  Serial.print("Right Motor Pin 2 = ");
  Serial.println(rightMotorLogicPin2); 

  Serial.print("Left Motor Pin 1 = ");
  Serial.println(leftMotorLogicPin1);

  Serial.print("Left Motor Pin 2 = ");
  Serial.println(leftMotorLogicPin2); 


}

char updateDirection(char command){
  char currentDirection = 'r';
  // Is this a direction; 'f' 'b' 'l' 'r'
  if (command == 'f') {
    currentDirection = 'f';
    Serial.println("Forwards");
  }
  else if (command == 'b') {
    currentDirection = 'b';
    Serial.println("Backwards");
  }
  else if (command == 'l') {
    currentDirection = 'l';
    Serial.println("Left");
  }
  else if (command == 'r') {
    currentDirection = 'r';
    Serial.println("Right");
  }
  else if (command == 'u') {
    currentDirection = 'r';
    Serial.println("Search");
  }
  else{
    Serial.println("error: no valid command given");
    Serial.println("in function char updateDirection"); 
  }
  return currentDirection;
    
}

void setMotorPins(int currentDirection){
  
  // Reset all of the pins
  //resetPins();

  //backwards
  if ((currentDirection == 'b') /*|| (currentDirection == 'r')*/) { 
    analogWrite(rightMotorLogicPin1, pwmDutyCycle);
  }
  if ((currentDirection == 'b') || (currentDirection == 'l')) { 
    analogWrite(leftMotorLogicPin1, pwmDutyCycle);
  }

  //forwards
  if ((currentDirection == 'f') || (currentDirection == 'r')) { 
    analogWrite(rightMotorLogicPin2, pwmDutyCycle);
  }
  if ((currentDirection == 'f') || (currentDirection == 'l')) { 
    analogWrite(leftMotorLogicPin2, pwmDutyCycle);
  }
}

void resetPins(){
  analogWrite(rightMotorLogicPin1, 0);
  analogWrite(rightMotorLogicPin2, 0);
  analogWrite(leftMotorLogicPin1, 0);
  analogWrite(leftMotorLogicPin2, 0);
}

void stop () {
   resetPins();
}


//functions to be completed
/*
bool hitSense () {
   //senses if ball has been 'kicked' to activate stop function if 
   //necessary
}

int compassRead () {
   //reads from compass module on x axis and returns angle from 'NORTH'
   //to determine angle to the goal
}

void adjust () {
   //function to adjust robot in case of ball being behind robot
   //so that shots will go towards the goal
   //will not be implemented until other functions are fully functioning
} 
*/
