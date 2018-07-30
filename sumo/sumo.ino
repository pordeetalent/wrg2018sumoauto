//Sirapol Nokyoongthong
//pordeetalent@gmail.com

#include <NewPing.h>
const int trigpinF = 2; //trig ของ ultrasonic front
const int echopinF = 3; //echo ของ ultrasonic front
const int trigpinL = 6; //trig ของ ultrasonic left
const int echopinL = 7; //echo ของ ultrasonic left
const int trigpinR = 4; //trig ของ ultrasonic right
const int echopinR = 5; //echo ของ ultrasonic right
const int irL = 8; //infrared left (1=black, 0=white)
const int irR = 9; //infrared left (1=black, 0=white)
const int ledL = 12; //LED left
const int ledR = 13; //LED right
const int maxDist = 200;


const int mla = 15; //มอเตอร์ left ขา inA //หมุนมอเตอร์ซ้ายไปด้านหน้า (ค่ามี 0 กับ 1)
const int mlb = 14; //มอเตอร์ left ขา inB //หมุนมอเตอร์ซ้ายไปด้านหลัง (ค่ามี 0 กับ 1)
const int mra = 17; //มอเตอร์ Right ขา inA //หมุนมอเตอร์ขวาไปด้านหน้า (ค่ามี 0 กับ 1)
const int mrb = 18; //มอเตอร์ Right ขา inB //หมุนมอเตอร์ขวาไปด้านหลัง (ค่ามี 0 กับ 1)
const int mlpwm = 11; //มอเตอร์ Left ขา pwm //กำหนดความเร็วการหมุนของมอเตอร์ซ้าย (ค่ามี 0 ถึง 255)
const int mrpwm = 10; //มอเตอร์ Right ขา pwm //กำหนดความเร็วการหมุนของมอเตอร์ขวา (ค่ามี 0 ถึง 255)


NewPing usF(trigpinF, echopinF, maxDist); // Ultrasonic front
NewPing usL(trigpinL, echopinL, maxDist); // Ultrasonic left
NewPing usR(trigpinR, echopinR, maxDist); // Ultrasonic right



void setup(){
  Serial.begin(9600);
  pinMode(ledL, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(mla, OUTPUT);
  pinMode(mlb, OUTPUT);
  pinMode(mra, OUTPUT);
  pinMode(mrb, OUTPUT);
  pinMode(mlpwm, OUTPUT);
  pinMode(mrpwm, OUTPUT);
  pinMode(trigpinF, OUTPUT);
  pinMode(echopinF, INPUT);
  pinMode(trigpinL, OUTPUT);
  pinMode(echopinL, INPUT);
  pinMode(trigpinR, OUTPUT);
  pinMode(echopinR, INPUT);
  pinMode(irL, INPUT);
  pinMode(irR, INPUT);
}

void loop(){
  //delay(200);
  
  int usVF = usF.ping_cm();
  int usVL = usL.ping_cm();
  int usVR = usR.ping_cm();

  //##### ตรวจหาค่า infrared #####
  int irLV = digitalRead(irL); //อ่านค่าจาก infrared left ไปเก็บในตัวแปร irLV
  int irRV = digitalRead(irR); //อ่านค่าจาก infrared right ไปเก็บในตัวแปร irRV
  //#############################

  
  //############################
  //##### debug ultrasonic #####
  //############################
  //Serial.print("F = ");
  //Serial.println(usVF);
  //Serial.print("L = ");
  //Serial.println(usVL);
  //Serial.print("R = ");
  //Serial.println(usVR);
  //Serial.print("irL = ");
  Serial.print(irLV);
  //Serial.print("irR = ");
  Serial.println(irRV);
  Serial.println("############");  
  //##############################
  

  digitalWrite(ledL, LOW);
  digitalWrite(ledR, LOW);
  if (irLV==0 || irRV==0){
    digitalWrite(ledL, HIGH);
    digitalWrite(ledR, HIGH);
    BACKWARD(50);
    BACKFLIP();
  } else if (usVL >= 1 && usVL <= 15) {
    TURN_L(250);
    digitalWrite(ledL, HIGH);
    digitalWrite(ledR, LOW);
  } else if (usVL >= 16 && usVL <= 30) {
    TURN_L(150);
    digitalWrite(ledL, HIGH);
    digitalWrite(ledR, LOW);
  } else if (usVR >= 1 && usVR <= 15) {
    TURN_R(250);
    digitalWrite(ledL, LOW);
    digitalWrite(ledR, HIGH);
  } else if (usVR >= 16 && usVR <= 30) {
    TURN_R(150);
    digitalWrite(ledL, LOW);
    digitalWrite(ledR, HIGH);
  } else if (usVF >= 1 && usVF <= 30) {
    digitalWrite(ledL, LOW);
    digitalWrite(ledR, LOW);
    FORWARD(255);
  } else if (usVF >= 31 && usVF <= 70) {
    digitalWrite(ledL, LOW);
    digitalWrite(ledR, LOW);
    FORWARD(150);
  } else {
    FORWARD(70);
  }
  

}

void FORWARD (int Speed){
  digitalWrite(mla, HIGH);
  digitalWrite(mlb, LOW);
  digitalWrite(mra, HIGH);
  digitalWrite(mrb, LOW);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
  //delay(50);
}

void BACKWARD (int Speed){
  digitalWrite(mla, LOW);
  digitalWrite(mlb, HIGH);
  digitalWrite(mra, LOW);
  digitalWrite(mrb, HIGH);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
  delay(1000);
}

void TURN_L (int Speed){
  digitalWrite(mla, LOW);
  digitalWrite(mlb, HIGH);
  digitalWrite(mra, HIGH);
  digitalWrite(mrb, LOW);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
  //delay(50);
}

void TURN_R (int Speed){
  digitalWrite(mla, HIGH);
  digitalWrite(mlb, LOW);
  digitalWrite(mra, LOW);
  digitalWrite(mrb, HIGH);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
  //delay(50);
}

void WAIT (int Speed){
  digitalWrite(mla, LOW);
  digitalWrite(mlb, LOW);
  digitalWrite(mra, LOW);
  digitalWrite(mrb, LOW);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
}

void BACKFLIP (){
  digitalWrite(mla, HIGH);
  digitalWrite(mlb, LOW);
  digitalWrite(mra, LOW);
  digitalWrite(mrb, HIGH);
  analogWrite(mlpwm, 80);
  analogWrite(mrpwm, 80);
  delay(1000);
}

/*
void BLINK (){
  digitalWrite(led, HIGH);
  delay(50);
  digitalWrite(led, LOW);
  delay(50);
  digitalWrite(led, HIGH);
  delay(50);
}
*/
