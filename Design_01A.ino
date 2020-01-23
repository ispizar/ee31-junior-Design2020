int red_led = 22;
int blue_led = 9;
int green_led = 8;

int potentiometer1 = A0;
int potentiometer2 = A1;

int switch1 = 24;
int switch2 = 26; 

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

int counter = 0;
int delay_time = 5;

int prev_state = 0;
int curr_state = 0;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(red_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  
  pinMode(potentiometer1, INPUT);
  pinMode(potentiometer2, INPUT);
  
}

void loop() 
{

  Serial.println(analogRead(A0));

  if (Serial.available() > 0)
  {
    int temp_state = Serial.read() - '0'; 
    //Serial.println(temp_state, DEC);

    if (curr_state !=  temp_state)
    {
      if (temp_state == 0 || temp_state == 1)
      {
         prev_state = curr_state;
         curr_state = temp_state;
      }
      
      if (curr_state == 1 and temp_state == 2)
      {
         prev_state = curr_state;
         curr_state = temp_state;
      }
    
      if (curr_state == 1 and temp_state == 3)
      {
         prev_state = curr_state;
         curr_state = temp_state;
      }
    
      if (curr_state == 1 and temp_state == 4)
      {
         prev_state = curr_state;
         curr_state = temp_state;
      }   
    }
  }
  
  counter ++;
  if (counter > 1000)
    counter == 0;

  //Serial.println(curr_state, DEC);
  
  switch (curr_state) 
  {
    case 0:     
      off();
      break;
    case 1:
      on();
      break;
    case 2:
      run();
      break;
    case 3:
      sleep();
      break;
    case 4:
      diagnostics();
      break;
    default:
      off();
      break;
  }

  delay(delay_time);
  
}


void blink(int pin, int period)
{
    if (counter % (period / delay_time) == 0)
     digitalWrite(pin, HIGH);

    if (counter % (2 * (period / delay_time)) == 0)
      digitalWrite(pin, LOW); 
}


void analog_blink(int pin, int period, int bright)
{
    if (counter % (period / delay_time) == 0)
     analogWrite(pin, bright);

    if (counter % (2 * (period / delay_time)) == 0)
      digitalWrite(pin, LOW); 
}


void fade(int pin, int period)
{
  if (counter % (period / delay_time) == 0)
  {
    analogWrite(pin, brightness);
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255) 
    {
      fadeAmount = -fadeAmount;
    }
  }  
}


void on() 
{
    digitalWrite(green_led, HIGH);    
    blink (blue_led, 1000);
    digitalWrite(red_led, LOW);
}


void off () 
{
   digitalWrite(red_led, LOW);
   digitalWrite(blue_led, LOW);
   digitalWrite(green_led, LOW);  
}


void run () 
{  
  fade(green_led, 30);

  int pot_speed = (analogRead(potentiometer1) + 1) / 1.5;
  if (pot_speed == 0)
    pot_speed = 1000;
  int pot_bright = (analogRead(potentiometer2) + 1) / 3;
  
  if(digitalRead(switch1) == LOW)
  {
    blink(blue_led, 100);
    if (digitalRead(switch2) == LOW)
    {
      digitalWrite(red_led, HIGH);
    }
    else
    {
      digitalWrite(red_led, LOW);
    }
  }

  else
  {
    analog_blink(blue_led,pot_speed,pot_bright);
    digitalWrite(red_led, LOW);
  }
}

void sleep ()
{  
  blink (green_led, 100);
  digitalWrite(blue_led, LOW);
}


void diagnostics ()
{
  blink (green_led, 1000);    
  digitalWrite(blue_led, LOW);
}
