#include <Servo.h>
#include <SoftwareSerial.h>
const int trigPin=13;
const int echoPin=12;
int ch;
int L=1500,R=1500;
Servo Lservo;
Servo Rservo;
SoftwareSerial BTSerial(2,3);
void setup() {
  // put your setup code here, to run once:
  BTSerial.begin(9600);
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  while(!Serial){
  Serial.write("Not conneted\n");
  }
  Serial.write("I'm ready for start\n");
  Lservo.attach(9); 
  Rservo.attach(8);
  Lservo.write(1500);
  Rservo.write(1500);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  
  
  if(BTSerial.available()){
    ch=BTSerial.read();
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration/58;

  Serial.print(distance);
  Serial.print("cm");
    if(ch-48==1)
    {
      R=1700;
      L=1300;
   
    }
    else if(ch-48==2)
    {
      if(R>1300)
        R-=50;
      if(L>1300)
        L-=50;
        if(L<1300)
        L=1300;
        if(R<1300)
        R=1300;
    }
    else if(ch-48==3)
    {
       if(R<1700)
         R+=50;
       if(L<1700)
          L+=50;
        if(L>1700)
        L=1700;
        if(R>1700)
        R=1700;
    }
    else if(ch-48==4)
    {
      R=1300;
      L=1700;
    }
    else if(ch-48==5)
    {
      R=1500;
      L=1500;
    }
    Serial.println();
    Serial.print(L);
    Serial.print(" ");
    Serial.print(R);
    Serial.println();
    Rservo.write(R);
    Lservo.write(L);    
}
}
