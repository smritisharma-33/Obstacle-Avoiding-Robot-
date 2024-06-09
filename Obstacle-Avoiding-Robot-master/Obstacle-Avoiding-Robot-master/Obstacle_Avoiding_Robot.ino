int trigger_pin = 11;        // trig pin of HC-SR04
int echo_pin = 10;       // Echo pin of HC-SR04
int EA = 9;              //ENA connected to digital pin 9
int EB = 3;             //ENB connected to digital pin 3
int reverse_A = 7;       
int foreward_A = 6;       
int reverse_B =5;        
int foreward_B = 4;      

long dur, dist;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(reverse_A, OUTPUT);      // set Motor pins as output
  pinMode(foreward_A, OUTPUT);
  pinMode(reverse_B, OUTPUT);
  pinMode(foreward_B, OUTPUT);
  pinMode(EA, OUTPUT);      // initialize ENA pin as an output
  pinMode(EB, OUTPUT);      // initialize ENB pin as an output
  pinMode(trigger_pin, OUTPUT);         // set trig pin as output
  pinMode(echo_pin, INPUT);          //set echo pin as input to capture reflected waves
}

void loop() {

  analogWrite(trigger_pin, LOW);
  delayMicroseconds(2);   
  analogWrite(trigger_pin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  dur = pulseIn(echo_pin, HIGH); // receive reflected waves
  dist = dur / 58.2;   // convert to distance
  Serial.println(dist);
  delay(10);
  if (dist > 19)            
  {
    analogWrite(EA, 150); // set right motors speed
    analogWrite(EB, 150); // set left motors speed
    digitalWrite(foreward_B, HIGH);                    // move forward
    digitalWrite(reverse_B, LOW);
    digitalWrite(foreward_A, HIGH);                                
    digitalWrite(reverse_A, LOW);                                                       
  }

  if (dist < 18)
  {
    analogWrite(EA, 0); // set right motors speed
    analogWrite(EB, 0); // set left motors speed
    digitalWrite(foreward_B, LOW);  //Stop                
    digitalWrite(reverse_B, LOW);
    digitalWrite(foreward_A, LOW);                                
    digitalWrite(reverse_A, LOW);
    delay(500);

    analogWrite(EA, 255); // set right motors speed
    analogWrite(EB, 255); // set left motors speed
    digitalWrite(foreward_B, LOW);      //movebackword         
    digitalWrite(reverse_B, HIGH);
    digitalWrite(foreward_A, LOW);                                
    digitalWrite(reverse_A, HIGH);
    delay(500);

    analogWrite(EA, 0); // set right motors speed
    analogWrite(EB, 0); // set left motors speed
    digitalWrite(foreward_B, LOW);  //Stop                
    digitalWrite(reverse_B, LOW);
    digitalWrite(foreward_A, LOW);                                
    digitalWrite(reverse_A, LOW);  
    delay(100);  

    analogWrite(EA, 0); // set right motors speed
    analogWrite(EB, 150); // set left motors speed
    digitalWrite(foreward_B, HIGH);       //turnleft
    digitalWrite(reverse_B, LOW);   
    digitalWrite(reverse_A, LOW);                                 
    digitalWrite(foreward_A, LOW);  
    delay(500);
  }
