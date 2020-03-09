int digital_interrupt = 3;
bool collision = 0;



int bumper1_pin = 7;
int bumper2_pin = 6;


bool bumper1 = 0;
bool bumper2 = 0;
bool bumper3 = 0;
bool bumper4 = 0;




void setup() {
  // put your setup code here, to run once:
  pinMode(digital_interrupt, INPUT_PULLUP);
  pinMode(bumper1_pin, INPUT_PULLUP);
  pinMode(bumper2_pin, INPUT_PULLUP);
  attachInterrupt(1, collision_interrupt, FALLING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(digital_interrupt));
  //Serial.println(state);
  delay (100);
  

}

void collision_interrupt(){
  collision = 1;
  delay(5);
  if(digitalRead(bumper1_pin) == 0){
    bumper1 = 1;
  }
  if(digitalRead(bumper2_pin) == 0){
    bumper2 = 1;
  }

  collision_routine();
  
}

void collision_routine(){

  Serial.println("Collision occurred");
  if(bumper1 == 1){
    Serial.println("Bumper1 Hit");
  }
  if(bumper2 ==1){
    Serial.println("Bumpber2 Hit");
  }

  bumper1 = 0;
  bumper2 = 0;
  bumper3 = 0;
  bumper4 = 0;  
}


void reset_collision(){
  bumper1 = 0;
  bumper2 = 0;
  bumper3 = 0;
  bumper4 = 0;
}
