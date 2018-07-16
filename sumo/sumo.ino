const trigpinF 0 //trig ของ ultrasonic front
const echopinF 1 //echo ของ ultrasonic front
const trigpinL 2 //trig ของ ultrasonic left
const echopinL 3 //echo ของ ultrasonic left
const trigpinR 4 //trig ของ ultrasonic right
const echopinR 5 //echo ของ ultrasonic right

int mla = 9; //มอเตอร์ left ขา inA //หมุนมอเตอร์ซ้ายไปด้านหน้า (ค่ามี 0 กับ 1)
int mlb = 10; //มอเตอร์ left ขา inB //หมุนมอเตอร์ซ้ายไปด้านหลัง (ค่ามี 0 กับ 1)
int mra = 12; //มอเตอร์ Right ขา inA //หมุนมอเตอร์ขวาไปด้านหน้า (ค่ามี 0 กับ 1)
int mrb = 14; //มอเตอร์ Right ขา inB //หมุนมอเตอร์ขวาไปด้านหลัง (ค่ามี 0 กับ 1)
int mlpwm = 8; //มอเตอร์ Left ขา pwm //กำหนดความเร็วการหมุนของมอเตอร์ซ้าย (ค่ามี 0 ถึง 255)
int mrpwm = 11; //มอเตอร์ Right ขา pwm //กำหนดความเร็วการหมุนของมอเตอร์ขวา (ค่ามี 0 ถึง 255)

int distF ; //ระยะห่างของ ultrasonic front
int distL ; //ระยะห่างของ ultrasonic left
int distR ; //ระยะห่างของ ultrasonic right

void setup(){
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

void forword(int Speed){
  digitalWrite(mla, HIGH);
  digitalWrite(mlb, HIGH);
  digitalWrite(mra, LOW);
  digitalWrite(mrb, LOW);
  analogWrite(mlpwm, Speed);
  analogWrite(mrpwm, Speed);
}

void backward(int Speed){
  
}

void rotate(int Speed){
  
}

void wait(int Speed){
  
}

