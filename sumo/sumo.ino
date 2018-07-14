//Author Sirapol Nokyoongthong
//email pordeetalent@gmail.com
//2018-07-13

#define utf 0 //Ultrasonic trig front
#define uef 1 //Ultrasonic echo front
#define utl 2 //Ultrasonic trig left
#define uel 3 //Ultrasonic echo leftt
#define utr 4 //Ultrasonic trig right
#define uer 5 //Ultrasonic echo right
#define mlia 9 //Motor left in A
#define mlib 10 //Motor left in B
#define mlpw 8 //Motor left PWM
#define mria 12 //Motor right in A
#define mrib 14 //Motor right in B
#define mrpw 11 //Motor right PWM
#define led 13


void setup() {
  Serial.begin (9600);
  pinMode(utf, OUTPUT);
  pinMode(uef, INPUT);
  pinMode(utl, OUTPUT);
  pinMode(uel, INPUT);
  pinMode(utr, OUTPUT);
  pinMode(uer, INPUT);
  pinMode(led, OUTPUT);
  pinMode(mlia, OUTPUT);
  pinMode(mlib, OUTPUT);
  pinMode(mlpw, OUTPUT);
  pinMode(mria, OUTPUT);
  pinMode(mrib, OUTPUT);
  pinMode(mrpw, OUTPUT);
}

void loop() {
  long duration, distance;
  long range_f;
  long range_l;
  long range_r;

  //Front USonic
  digitalWrite(utf, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(utf, HIGH);
  delayMicroseconds(2); // Added this line
  range_f = pulseIn(uef, HIGH);

  //Left USonic
  digitalWrite(utl, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(utl, HIGH);
  delayMicroseconds(2); // Added this line
  range_l = pulseIn(uel, HIGH);

  //Right USonic
  digitalWrite(utr, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(utr, HIGH);
  delayMicroseconds(2); // Added this line
  range_r = pulseIn(uer, HIGH);

  //Print
  Serial.print("rangeF = ");
  Serial.println(range_f);
  Serial.print("rangeL = ");
  Serial.println(range_l);
  Serial.print("rangeR = ");
  Serial.println(range_r);
  Serial.println();
  Serial.println();
  


  if (range_f < 300){
    digitalWrite(mlia,HIGH);
    digitalWrite(mlib,HIGH);
  } else {
      
  }

  if (range_l < 1000){
    digitalWrite(mlia,LOW);
    digitalWrite(mlib,HIGH);
  } else {
      
  }

  if (range_r < 1000){
    digitalWrite(mlia,HIGH);
    digitalWrite(mlib,LOW);
  } else {
      
  }

  delay(100);


}
/*
void fight(){
  digitalWrite(mlia,HIGH);
  digitalWrite(mlib,HIGH);
}

void search(){
  
}
*/
