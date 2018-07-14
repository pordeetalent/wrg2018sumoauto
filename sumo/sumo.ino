//Author Sirapol Nokyoongthong
//email pordeetalent@gmail.com
//2018-07-13

/*
#define uef 1 //Ultrasonic Echo Front
#define uel 3 //Ultrasonic Echo Left
#define uer 5 //Ultrasonic Echo Right
#define utf 0 //Ultrasonic Trig Front
#define utl 2 //Ultrasonic Trig Left
#define utr 4 //Ultrasonic Trig Right
#define led 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(utf, INPUT);
  pinMode(utl, INPUT);
  pinMode(utr, INPUT);
  pinMode(uef, OUTPUT);
  pinMode(uef, OUTPUT);
  pinMode(uef, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  int urfState = digitalRead(urf);
//  Serial.println(urfState);
//  delay(1);
  long duration, distance;
  digitalWrite(utr, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(utr, HIGH);
  delayMicroseconds(10); // Added this line
  duration = pulseIn(uer, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 4) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
    //digitalWrite(led2,LOW);
  }
  else {
    digitalWrite(led,LOW);
    //digitalWrite(led2,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(50);
}
*/


/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 Red POS to Arduino pin 11
 Green POS to Arduino pin 10
 560 ohm resistor to both LED NEG and GRD power rail
 More info at: http://goo.gl/kJ8Gl
 Original code improvements to the Ping sketch sourced from Trollmaker.com
 Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
 

#define trigPin 4
#define echoPin 5
#define led 11
#define led2 10

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 4) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
}
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(50);
}
*/


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
  /*
  distance = (duration/2) / 29.1;
  if (distance < 10) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
    digitalWrite(mlia,HIGH);
  }
  else {
    digitalWrite(led,LOW);
    digitalWrite(mlia,LOW);
  }
  if (distance >= 20000 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  */
  delay(100);
}

