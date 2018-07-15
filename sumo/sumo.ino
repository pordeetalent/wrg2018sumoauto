#define trigpinF 0 //trig ของ ultrasonic front
#define echopinF 1 //echo ของ ultrasonic front
#define trigpinL 2 //trig ของ ultrasonic left
#define echopinL 3 //echo ของ ultrasonic left
#define trigpinR 4 //trig ของ ultrasonic right
#define echopinR 5 //echo ของ ultrasonic right

int aA1 = 9; //มอเตอร์ left ขา inA
int bB1 = 10; //มอเตอร์ left ขา inB
int aA2 = 12; //มอเตอร์ Right ขา inA
int bB2 = 14; //มอเตอร์ Right ขา inB
int en1 = 8; //มอเตอร์ Left ขา pwm
int en2 = 11; //มอเตอร์ Right ขา pwm

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
}

void loop(){
  
  //#####################################
  //##### การจัดการ Ultrasonic front #####
  //#####################################
  
  int durationF, distanceF;
  digitalWrite(trigpinF, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpinF, LOW);
  durationF = pulseIn(echopinF, HIGH);
  distanceF = (durationF / 2) / 29.1;

  
  if (distanceF >= 40){ // ถ้า ultrasonic front มีค่า 40 ขึ้นไป ให้มอเตอร์ไม่หมุน
    digitalWrite(aA1, LOW);
    digitalWrite(bB1, LOW);
    digitalWrite(aA2, LOW);
    digitalWrite(bB2, LOW);
    analogWrite(en1,0);
    analogWrite(en2,0);
    delay(500);

  } else { 
    if (distanceF >= 25){ //แต่ถ้า ultrasonic front มีค่า 25 ขึ้นไป ให้มอเตอร์ A หมุน
      digitalWrite(aA1, HIGH);
      digitalWrite(bB1, LOW);
      digitalWrite(aA2, HIGH);
      digitalWrite(bB2, LOW);
      analogWrite(en1,255);
      analogWrite(en2,255);
      delay(400); 
    } else { //แต่ถ้า ultrasonic front ไม่มากกว่า 40 และไม่มากกว่า 25 ให้มอเตอร์ B หมุน
      digitalWrite(aA1, LOW);
      digitalWrite(bB1, HIGH);
      digitalWrite(aA2, LOW);
      digitalWrite(bB2, HIGH);
      analogWrite(en1,255);
      analogWrite(en2,255);
      delay(400);

    }

  }

  //####################################
  //##### การจัดการ Ultrasonic left #####
  //####################################
  
  int durationL, distanceL;
  digitalWrite(trigpinL, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpinL, LOW);
  durationL = pulseIn(echopinL, HIGH);
  distanceL = (durationL / 2) / 29.1;

  
  if (distanceL >= 40){ // ถ้า ultrasonic left มีค่า 40 ขึ้นไป ให้มอเตอร์ไม่หมุน
    digitalWrite(aA1, LOW);
    digitalWrite(bB1, LOW);
    digitalWrite(aA2, LOW);
    digitalWrite(bB2, LOW);
    analogWrite(en1,0);
    analogWrite(en2,0);
    delay(500);

  } else { 
    if (distanceL >= 25){ //แต่ถ้า ultrasonic left มีค่า 25 ขึ้นไป ให้มอเตอร์ A หมุน
      digitalWrite(aA1, HIGH);
      digitalWrite(bB1, LOW);
      digitalWrite(aA2, HIGH);
      digitalWrite(bB2, LOW);
      analogWrite(en1,255);
      analogWrite(en2,255);
      delay(400); 
    } else { //แต่ถ้า ultrasonic left ไม่มากกว่า 40 และไม่มากกว่า 25 ให้มอเตอร์ B หมุน
      digitalWrite(aA1, LOW);
      digitalWrite(bB1, HIGH);
      digitalWrite(aA2, LOW);
      digitalWrite(bB2, HIGH);
      analogWrite(en1,255);
      analogWrite(en2,255);
      delay(400);

    }

  //#####################################
  //##### การจัดการ Ultrasonic right #####
  //#####################################
  
  int durationR, distanceR;
  digitalWrite(trigpinR, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpinR, LOW);
  durationR = pulseIn(echopinR, HIGH);
  distanceR = (durationR / 2) / 29.1;

  
  if (distanceR >= 40){ // ถ้า ultrasonic right มีค่า 40 ขึ้นไป ให้มอเตอร์ไม่หมุน
    digitalWrite(aA1, LOW);
    digitalWrite(bB1, LOW);
    digitalWrite(aA2, LOW);
    digitalWrite(bB2, LOW);
    analogWrite(en1,0);
    analogWrite(en2,0);
    delay(500);

  } else { 
    if (distanceR >= 25){ //แต่ถ้า ultrasonic right มีค่า 25 ขึ้นไป ให้มอเตอร์ A หมุน
      digitalWrite(aA1, HIGH);
      digitalWrite(bB1, LOW);
      digitalWrite(aA2, HIGH);
      digitalWrite(bB2, LOW);
      analogWrite(en1,255);
      analogWrite(en2,255);
      delay(400); 
    } else { //แต่ถ้า ultrasonic right ไม่มากกว่า 40 และไม่มากกว่า 25 ให้มอเตอร์ B หมุน
      digitalWrite(aA1, LOW);
      digitalWrite(bB1, HIGH);
      digitalWrite(aA2, LOW);
      digitalWrite(bB2, HIGH);
      analogWrite(en1,255);
      analogWrite(en2,255);
      delay(400);

    }

  }

}
