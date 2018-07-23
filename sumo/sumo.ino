//Sirapol Nokyoongthong
//pordeetalent@gmail.com

#include <HCSR04.h>
#define trigpinF 2 //trig ของ ultrasonic front
#define echopinF 3 //echo ของ ultrasonic front
#define trigpinR 6 //trig ของ ultrasonic left
#define echopinR 7 //echo ของ ultrasonic left
#define trigpinL 4 //trig ของ ultrasonic right
#define echopinL 5 //echo ของ ultrasonic right
#define irL 8 //infrared left
#define irR 9 //infrared left

int mla = 18; //มอเตอร์ left ขา inA //หมุนมอเตอร์ซ้ายไปด้านหน้า (ค่ามี 0 กับ 1)
int mlb = 17; //มอเตอร์ left ขา inB //หมุนมอเตอร์ซ้ายไปด้านหลัง (ค่ามี 0 กับ 1)
int mra = 15; //มอเตอร์ Right ขา inA //หมุนมอเตอร์ขวาไปด้านหน้า (ค่ามี 0 กับ 1)
int mrb = 14; //มอเตอร์ Right ขา inB //หมุนมอเตอร์ขวาไปด้านหลัง (ค่ามี 0 กับ 1)
int mlpwm = A1; //มอเตอร์ Left ขา pwm //กำหนดความเร็วการหมุนของมอเตอร์ซ้าย (ค่ามี 0 ถึง 255)
int mrpwm = A2; //มอเตอร์ Right ขา pwm //กำหนดความเร็วการหมุนของมอเตอร์ขวา (ค่ามี 0 ถึง 255)

//int distF ; //ระยะห่างของ ultrasonic front
//int distL ; //ระยะห่างของ ultrasonic left
//int distR ; //ระยะห่างของ ultrasonic right

UltraSonicDistanceSensor distF(3, 2); //ระยะห่างของ ultrasonic front
UltraSonicDistanceSensor distL(5, 4); //ระยะห่างของ ultrasonic left
UltraSonicDistanceSensor distR(7, 6); //ระยะห่างของ ultrasonic right

void setup(){
  Serial.begin(9600);
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
  //delay (5000); //รอ 5 วินาทีก่อนที่จะทำงาน ตามที่กติกากำหนด
}

void loop(){
  //delay (500);
  
  double distVF;
  double distVL;
  double distVR;
  distVF = distF.measureDistanceCm();
  distVL = distL.measureDistanceCm();
  distVR = distR.measureDistanceCm();

  
  //############################
  //##### debug ultrasonic #####
  //############################
  Serial.print("F = ");
  Serial.println(distVF);
  Serial.print("L = ");
  Serial.println(distVL);
  Serial.print("R = ");
  Serial.println(distVR);
  Serial.println("############");
  //##############################
  

  


  //##### ตรวจหาค่า infrared #####
  //int irLV = analogRead(irL); //อ่านค่าจาก infrared left ไปเก็บในตัวแปร irLV
  //int irRV = analogRead(irL); //อ่านค่าจาก infrared right ไปเก็บในตัวแปร irRV

  //##### ทำงานตามค่า ultrasonic front #####
  //ถ้า ultrasonic front เห็น ให้พุ่งตรง
  //ถ้า ultrasonic front ไม่เห็น ให้หมุนตัว
  if (distVF < 50) {
    FORWARD(120);    
  } else if (distVL < 50) {
    TURN_L(120);    
  } else if (distVR < 50) {
    TURN_R(120);    
  } else {
      WAIT(0);
  }

  //ถ้า ultrasonic left เห็น ให้เลี้ยวซ้าย
  //ถ้า ultrasonic left ไม่เห็น ให้ไม่ต้องทำอะไร

  //ถ้า ultrasonic right เห็น ให้เลี้ยวขวา
  //ถ้า ultrasonic right ไม่เห็น ให้ไม่ต้องทำอะไร

  //ถ้า infrared left เห็น ให้เลี้ยวขวา
  //ถ้า infrared left ไม่เห็น ให้ไม่ต้องทำอะไร

  //ถ้า infrared right เห็น ให้เลี้ยวซ้าย
  //ถ้า infrared right ไม่เห็น ให้ไม่ต้องทำอะไร

// ----------- debugging ----------------
//  Serial.print(ultrasonic.Ranging(CM));
  //Serial.println("cm");
  //Serial.println("IR front :");
//  Serial.println(IR_front); 
  //Serial.println("IR back :");
//  Serial.println(IR_back);  
// --------------------------------------  
}

void FORWARD (int Speed){
  digitalWrite(mla, HIGH);
  digitalWrite(mlb, LOW);
  digitalWrite(mra, HIGH);
  digitalWrite(mrb, LOW);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
}

void BACKWARD (int Speed){
  digitalWrite(mla, LOW);
  digitalWrite(mlb, HIGH);
  digitalWrite(mra, LOW);
  digitalWrite(mrb, HIGH);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
}

void TURN_L (int Speed){
  digitalWrite(mla, LOW);
  digitalWrite(mlb, HIGH);
  digitalWrite(mra, HIGH);
  digitalWrite(mrb, LOW);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
}

void TURN_R (int Speed){
  digitalWrite(mla, HIGH);
  digitalWrite(mlb, LOW);
  digitalWrite(mra, LOW);
  digitalWrite(mrb, HIGH);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
}

void WAIT (int Speed){
  digitalWrite(mla, LOW);
  digitalWrite(mlb, LOW);
  digitalWrite(mra, LOW);
  digitalWrite(mrb, LOW);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
}

