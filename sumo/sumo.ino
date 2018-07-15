#define trigpinF 0
#define echopinF 1
#define trigpinL 2
#define echopinL 3
#define trigpinR 4
#define echopinR 5

int aA1 = 9;
int bB1 = 10;
int aA2 = 12;
int bB2 = 14;
int en1 = 8;
int en2 = 11;

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
  
  int durationF, distanceF;
  digitalWrite(trigpinF, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpinF, LOW);
  durationF = pulseIn(echopinF, HIGH);
  distanceF = (durationF / 2) / 29.1;

  if (distanceF >= 40){
    digitalWrite(aA1, LOW);
    digitalWrite(bB1, LOW);
    digitalWrite(aA2, LOW);
    digitalWrite(bB2, LOW);
    analogWrite(en1,0);
    analogWrite(en2,0);
    delay(500);

  } else {
    if (distanceF >= 25){
      digitalWrite(aA1, HIGH);
      digitalWrite(bB1, LOW);
      digitalWrite(aA2, HIGH);
      digitalWrite(bB2, LOW);
      analogWrite(en1,255);
      analogWrite(en2,255);
      delay(400); 
    } else {
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
