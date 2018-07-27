//Sirapol Nokyoongthong
//pordeetalent@gmail.com

/* Identify pin
trigpinF 2 //trig ของ ultrasonic front
echopinF 3 //echo ของ ultrasonic front
trigpinL 6 //trig ของ ultrasonic left
echopinL 7 //echo ของ ultrasonic left
trigpinR 4 //trig ของ ultrasonic right
echopinR 5 //echo ของ ultrasonic right
irL 8 //infrared left (1=black, 0=white)
irR 9 //infrared left (1=black, 0=white)
led 13 //infrared left (1=black, 0=white)


mla = 15; //มอเตอร์ left ขา inA //หมุนมอเตอร์ซ้ายไปด้านหน้า (ค่ามี 0 กับ 1)
mlb = 14; //มอเตอร์ left ขา inB //หมุนมอเตอร์ซ้ายไปด้านหลัง (ค่ามี 0 กับ 1)
mra = 18; //มอเตอร์ Right ขา inA //หมุนมอเตอร์ขวาไปด้านหน้า (ค่ามี 0 กับ 1)
mrb = 17; //มอเตอร์ Right ขา inB //หมุนมอเตอร์ขวาไปด้านหลัง (ค่ามี 0 กับ 1)
mlpwm = 11; //มอเตอร์ Left ขา pwm //กำหนดความเร็วการหมุนของมอเตอร์ซ้าย (ค่ามี 0 ถึง 255)
mrpwm = 10; //มอเตอร์ Right ขา pwm //กำหนดความเร็วการหมุนของมอเตอร์ขวา (ค่ามี 0 ถึง 255)
*/

 
void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
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
  
  //##### ตรวจหาค่า infrared #####
  int irLV = digitalRead(irL); //อ่านค่าจาก infrared left ไปเก็บในตัวแปร irLV
  int irRV = digitalRead(irR); //อ่านค่าจาก infrared right ไปเก็บในตัวแปร irRV
  //#############################

  
  //############################
  //##### debug ultrasonic #####
  //############################
  Serial.print("F = ");
  Serial.println(distVF);
  Serial.print("L = ");
  Serial.println(distVL);
  Serial.print("R = ");
  Serial.println(distVR);
  Serial.print("irL = ");
  Serial.println(irLV);
  Serial.print("irR = ");
  Serial.println(irRV);
  Serial.println("############");
  //##############################
  

  /*
  if (irLV==0 || irRV==0){
    BACKWARD(80);
    BACKFLIP();
  } else if (distVL < 15) {
    TURN_L(80);
  } else if (distVR < 15) {
    TURN_R(80);
  } else {
    FORWARD(80);
  }
  */

}

void FORWARD (int Speed){
  digitalWrite(mla, HIGH);
  digitalWrite(mlb, LOW);
  digitalWrite(mra, HIGH);
  digitalWrite(mrb, LOW);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
  delay(500);
}

void BACKWARD (int Speed){
  digitalWrite(mla, LOW);
  digitalWrite(mlb, HIGH);
  digitalWrite(mra, LOW);
  digitalWrite(mrb, HIGH);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
  delay(500);
}

void TURN_L (int Speed){
  digitalWrite(mla, LOW);
  digitalWrite(mlb, HIGH);
  digitalWrite(mra, HIGH);
  digitalWrite(mrb, LOW);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
  delay(500);
}

void TURN_R (int Speed){
  digitalWrite(mla, HIGH);
  digitalWrite(mlb, LOW);
  digitalWrite(mra, LOW);
  digitalWrite(mrb, HIGH);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
  delay(500);
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

void BLINK (){
  digitalWrite(led, HIGH);
  delay(50);
  digitalWrite(led, LOW);
  delay(50);
  digitalWrite(led, HIGH);
  delay(50);
}

