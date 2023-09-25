#include <ESP32Servo.h>
Servo myservo;
const int nslp=13;
const int enablePin=5;
const int in1Pin = 32; //  PWM output pin 10
const int in2Pin = 33;   //PWM output pin 11
const int servo = 27;
const int front_echo=12;
const int front_trigger=4;
const int right_echo=18;
const int right_trigger=5;
const int left_echo=23;
const int left_trigger=2;
long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;


void setup() {
  myservo.attach(servo, 500, 2500);
  
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(nslp, OUTPUT);
  pinMode(front_trigger, OUTPUT);
  pinMode(front_echo, INPUT);
  pinMode(right_trigger, OUTPUT);
  pinMode(right_echo, INPUT);
  pinMode(left_trigger, OUTPUT);
  pinMode(left_echo, INPUT);
  digitalWrite(nslp, HIGH);
  Serial.begin(9600);  
}
void front()
{
 digitalWrite(32, HIGH);  // Set motor direction
 digitalWrite(33, LOW);
// analogWrite(nslp, 255);
 Serial.println("hi");
}
void loop()
{
  myservo.write(100);  
  delay(100);
  front();
   //digitalWrite(in1Pin, HIGH);  // Set motor direction
   //digitalWrite(in2Pin, LOW);
   //digitalWrite(nslp, HIGH);
}