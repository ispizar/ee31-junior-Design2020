
int top_left = 2;
int top_right = 3;
int bot_left = 4;
int bot_right = 5;

int commandNum = 0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(top_left, OUTPUT);
  pinMode(top_right, OUTPUT);
  pinMode(bot_left, OUTPUT);
  pinMode(bot_right, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  if(Serial.available() > 0){
    commandNum = Serial.read();
  }
  Serial.println(commandNum, DEC);
  if(commandNum == 1){
    moveForward();
  }
  if(commandNum == 2){
    moveBackward();
  }
  else{
    brake();
  }
  */

  moveForward();
  brake();
  moveBackward();
  brake();\
}

void brake(){
  digitalWrite(top_left, LOW);
  digitalWrite(top_right, LOW);
  digitalWrite(bot_right, HIGH);
  digitalWrite(bot_left, HIGH);
  delay(2000);
}

void moveForward(){
  
  delay(500);
  for(int i = 150; i < 255; i += 5){
    analogWrite(top_left, i);
    analogWrite(bot_right, i);  

    
    digitalWrite(top_right, LOW);
    digitalWrite(bot_left, LOW);
    delay(10);
  }
  delay(2000);
}


void moveBackward(){
  /*
  digitalWrite(top_left, LOW); 
  digitalWrite(top_right, HIGH);
  digitalWrite(bot_right, LOW);
  digitalWrite(bot_left, HIGH);
  delay(2000);
  */
  delay(500);
  for(int i = 150; i < 250; i += 5){
    analogWrite(top_right, i);
    analogWrite(bot_left, i);  

    
    digitalWrite(top_left, LOW);
    digitalWrite(bot_right, LOW);
    delay(10);
  }
  delay(2000);
}
