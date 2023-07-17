#include <Servo.h>
#include <SoftwareSerial.h>


Servo servo1,servo2,servo3,servo4;


int pos1=130; // CLAMP
int pos2=30;  //FORWARD-BACK
int pos3=179; //UP-DOWN
int pos4=60;  //RİGHT-LEFT
int motor1Pin1 = A2; //ENGINE PINS
int motor1Pin2 = A3;
int motor2Pin1 = A4;
int motor2Pin2 = A5;

void setup() {
 servo1.attach(3);
 servo2.attach(5);
 servo3.attach(6);
 servo4.attach(9);
 pinMode(motor1Pin1, OUTPUT);
 pinMode(motor1Pin2, OUTPUT);
 pinMode(motor2Pin1, OUTPUT);
 pinMode(motor2Pin2, OUTPUT);
 servo1.write(130);
 delay(15);
 servo2.write(30);
 delay(15);
 servo3.write(179);
 delay(15);
 servo4.write(60);
 delay(15);
 Serial.begin(9600);

}

void loop() {


 if ( Serial.available()>0){
  char veri = Serial.read();
  if ( veri=='Z' && (pos1<180)){ //CLOSE CLAMP
  pos1 = pos1+1;
  servo1.write(pos1);
  delay(15);
 }
 if ( veri=='A' && (pos1>0)){ //OPEN CLAMP
  pos1 = pos1-1;
  servo1.write(pos1);
  delay(15);
 }

 if ( veri=='C' && (pos2<180)){ //FORWARD
  pos2 = pos2+1;
  servo2.write(pos2);
  delay(15);
 }
 if ( veri=='D' && (pos2>0)){ //BACK
  pos2 = pos2-1;
  servo2.write(pos2);
  delay(15);
 }

 if ( veri=='U' && (pos3<180)){ //DOWN
  pos3 = pos3+1;
  servo3.write(pos3);
  delay(15);
 }
 if ( veri=='E' && (pos3>0)){ //UP
  pos3 = pos3-1;
  servo3.write(pos3);
  delay(15);
 }

  if ( veri=='G' && (pos4<180)){ //RIGHT
  pos4 = pos4+1;
  servo4.write(pos4);
  delay(15);
 }
 if ( veri == 'H' &&(pos4>0)) //LEFT
  {
    pos4 = pos4-1;
    servo4.write(pos4); 
    delay(15);   
  }
 if (veri == 'F')
    {
      // Move forward
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
    }
    else if (veri == 'B')
    {
      // Move backward
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
    }
    else if (veri == 'L')
    {
      // Turn left
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
    }
    else if (veri == 'R')
    {
      // Turn right
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
    }
    else if (veri == 'S')
    {
      // Stop
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
    }
  }
}