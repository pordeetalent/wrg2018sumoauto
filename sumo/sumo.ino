const trigpinF 0 //trig ของ ultrasonic front
const echopinF 1 //echo ของ ultrasonic front
const trigpinL 2 //trig ของ ultrasonic left
const echopinL 3 //echo ของ ultrasonic left
const trigpinR 4 //trig ของ ultrasonic right
const echopinR 5 //echo ของ ultrasonic right

int aA1 = 9; //มอเตอร์ left ขา inA //หมุนมอเตอร์ซ้ายไปด้านหน้า (ค่ามี 0 กับ 1)
int bB1 = 10; //มอเตอร์ left ขา inB //หมุนมอเตอร์ซ้ายไปด้านหลัง (ค่ามี 0 กับ 1)
int aA2 = 12; //มอเตอร์ Right ขา inA //หมุนมอเตอร์ขวาไปด้านหน้า (ค่ามี 0 กับ 1)
int bB2 = 14; //มอเตอร์ Right ขา inB //หมุนมอเตอร์ขวาไปด้านหลัง (ค่ามี 0 กับ 1)
int en1 = 8; //มอเตอร์ Left ขา pwm //กำหนดความเร็วการหมุนของมอเตอร์ซ้าย (ค่ามี 0 ถึง 255)
int en2 = 11; //มอเตอร์ Right ขา pwm //กำหนดความเร็วการหมุนของมอเตอร์ขวา (ค่ามี 0 ถึง 255)

int distF ; //ระยะห่างของ ultrasonic front
int distL ; //ระยะห่างของ ultrasonic left
int distR ; //ระยะห่างของ ultrasonic right

void setup(){
  pinMode(aA1, OUTPUT);
  pinMode(bB1, OUTPUT);
  pinMode(aA2, OUTPUT);
  pinMode(bB2, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(trigpinF, OUTPUT);
  pinMode(echopinF, INPUT);
  pinMode(trigpinL, OUTPUT);
  pinMode(echopinL, INPUT);
  pinMode(trigpinR, OUTPUT);
  pinMode(echopinR, INPUT);
  delay (5000); //รอ 5 วินาทีก่อนที่จะทำงาน ตามที่กติกากำหนด
}

void loop(){
  

/* ----------- debugging ----------------
  Serial.print(ultrasonic.Ranging(CM));
  Serial.println("cm");
  Serial.println("IR front :");
  Serial.println(IR_front); 
  Serial.println("IR back :");
  Serial.println(IR_back);  
*/ --------------------------------------  
}

void forword(int speed){
  
}

void backward(int speed){
  
}

void rotate(int speed){
  
}

void wait(int speed){
  
}

