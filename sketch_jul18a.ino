int value1, value2, value3, value4, value5;

int a = 300;
int b = 300;
int c = 300;
int d = 300;
int e = 100;

int ENA = 10;
int ENB = 11;
int IN1 = 7;
int IN2 = 8;
int IN3 = 9;
int IN4 = 12;

int aa = 200;
int bb = 200;
int cc = 200;
int dd = 200;
int ee = 100;

void setup(){
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  Serial.begin(9600); 
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void onoff(){
  if(value1<a){
    digitalWrite(2, HIGH);
  }
  else{
    digitalWrite(2, LOW);
  }
   if(value2<b){
    digitalWrite(3, HIGH);
  }
  else{
    digitalWrite(3, LOW);
  }
   if(value3<c){
    digitalWrite(4, HIGH);
  }
  else{
    digitalWrite(4, LOW);
  }
   if(value4<d){
    digitalWrite(5, HIGH);
  }
  else{
    digitalWrite(5, LOW);
  }
   if(value5<e){
    digitalWrite(6, HIGH);
  }
  else{
    digitalWrite(6, LOW);
  }
}

void light(){
  value1 = analogRead(A0);
  value2 = analogRead(A1);
  value3 = analogRead(A2);
  value4 = analogRead(A3);
  value5 = analogRead(A4); 

  
  Serial.print(value1); Serial.print("  "); 
  Serial.print(value2); Serial.print("  "); 
  Serial.print(value3); Serial.print("  "); 
  Serial.print(value4); Serial.print("  "); 
  Serial.println(value5); 
}

void go(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 90);
  analogWrite(ENB, 90);
}

void left(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 90);
  analogWrite(ENB, 0);
}

void right(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 90);
}

void brake(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay(1000);
}

void slow(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 90);
  analogWrite(ENB, 90);
}

void moving(){
 if(value3<c && value1<a && value2<b && value4<d && value5){
  slow();
 }
 if(value3<c && value5<e){
  go();
 }
 if(value3<c){
  go();
 }
 if(value3<c & value2<b && value4<d){
  go();
 }
 if(value1<a && value3<c && value2<d){
  left();
 }
 if(value5<a && value3<b && value4<d){
  right();
 }
 if(value2<b && value1<a){
  left();
 }
 if(value5<e && value4<d){
  right();
 }
 if(value4<d){
  right();
 }
 if(value2<b){
  left();
 }
 if(value3<cc && value1<aa && value2<bb && value4<dd && value5<ee){
  brake();
 }
 if(value3<cc && value1<aa && value2<bb && value4<dd){
  brake();
  slow();
 }
}

void loop(){
  light();
  onoff();
  moving();
}
/*
 if(value3<c){
  go();
 }
 if(value5<e){
  right();
 }
 if(value1<a){
  left();
 }
 if(value3<cc && value1<aa && value2<bb && value4<dd && value5<ee){
  brake();
 } 
 */
