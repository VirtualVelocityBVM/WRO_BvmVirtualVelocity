include <NewPing.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include <FastLED.h>
/////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////// Define the ultrasonic sensor pins/////////////////////////
#define FRONT_TRIGGER 12
#define FRONT_ECHO 4

#define RIGHT_TRIGGER 5
#define RIGHT_ECHO 18

#define LEFT_TRIGGER 2
#define LEFT_ECHO 23

#define BACK_TRIGGER 17
#define BACK_ECHO 19

// Initialize the interrupt count
int count = 0;
NewPing frontSensor(FRONT_TRIGGER, FRONT_ECHO, 300);
NewPing rightSensor(RIGHT_TRIGGER, RIGHT_ECHO, 300);
NewPing leftSensor(LEFT_TRIGGER, LEFT_ECHO, 300);
NewPing backSensor(BACK_TRIGGER, BACK_ECHO, 300);

Servo myServo;
const int motorPin1 = 33;
const int motorPin2 = 32;
const int ledPin = 15;
int nslp = 13;
const int frequency = 1000;

bool ledState = LOW;
bool attachInterruptFlag = true;
///////////////////color sensor///////////////////

#define PCA9548A_ADDRESS 0x70  //mux
#define TCS3414CS_ADDRESS 0x29

Adafruit_TCS34725 tcs1 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_154MS, TCS34725_GAIN_1X);
Adafruit_TCS34725 tcs2 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_154MS, TCS34725_GAIN_1X);
//////////////////////////////////////////////////
int countflag = 0;

#define LED_PIN 15
#define NUM_LEDS 1

CRGB leds[NUM_LEDS];
///////////////////////////////////////////////////////

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);  // to turn off pow on reset
  Serial.begin(115200);
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();
  delay(10);
  delay(1000);
  ledcSetup(5, frequency, 8);
  ledcSetup(6, frequency, 8);
  ledcAttachPin(motorPin1, 5);
  ledcAttachPin(motorPin2, 6);
  pinMode(nslp, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(nslp, HIGH);
  myServo.write(95);
  myServo.attach(27);
  //attachInterrupt(14, counter, CHANGE);
  // Set up the interrupt on the specified pin (pin 14)
}

void loop() {

  // Read the ultrasonic distances
  unsigned int frontDistance = frontSensor.ping_cm();
  unsigned int rightDistance = rightSensor.ping_cm();
  unsigned int leftDistance = leftSensor.ping_cm();
  unsigned int backDistance = backSensor.ping_cm();
  //frontcoloursensor();

  // Print the ultrasonic distances
  Serial.print("Front Distance: ");
  Serial.print(frontDistance);
  Serial.print(" cm\tRight Distance: ");
  Serial.print(rightDistance);
  Serial.print(" cm\tLeft Distance: ");
  Serial.print(leftDistance);
  Serial.print(" cm\tBack Distance: ");
  Serial.print("count");
  Serial.println(countflag);


  //delay(100);  // Wait for 500 milliseconds before reading again
  frontcoloursensor();
  //  if((frontDistance > 100) && (frontDistance!= 0)){

  // if ((rightDistance < 35 ) && (leftDistance > 35 ) && (rightDistance != 0) && (leftDistance != 0))  {
  //   myServo.write(90);
  //   ledcWrite(5, 0);
  //   ledcWrite(6, 240);
  //   frontcoloursensor();


  while (frontDistance > 100 && frontDistance!= 0) {

    // if ((rightDistance < 25 && rightDistance > 20) && (rightDistance != 0)) {  //|| (leftDistance > 35 && leftDistance < 65)  && (leftDistance != 0))  {
    //   myServo.write(95);
    //   ledcWrite(5, 0);
    //   ledcWrite(6, 210);
    //   frontcoloursensor();
    // }
    if ((frontDistance > 100) && (rightDistance > 40) && (rightDistance != 0)) {
      myServo.write(102);
      ledcWrite(5, 0);
      ledcWrite(6, 250);
      frontcoloursensor();
    }
    if ((frontDistance > 100) && (rightDistance < 35) && (rightDistance != 0)) {
      myServo.write(88);
      ledcWrite(5, 0);
      ledcWrite(6, 250);
      frontcoloursensor();
    }
    break;
  }
  
  while ((frontDistance < 100) && (frontDistance!= 0)) {
    //if (countflag = countflag++){
    myServo.write(70);
    ledcWrite(5, 0);
    ledcWrite(6, 240);
    frontcoloursensor();
    
  //}
  break;
  }
  


  // if ((leftDistance < 30 ) && (leftDistance != 0))  {
  //   myServo.write(105);
  //   ledcWrite(5, 0);
  //   ledcWrite(6, 240);
  //   frontcoloursensor();
  //   else if ((leftDistance > 30 ) && (leftDistance != 0))  {
  //   myServo.write(85);
  //   ledcWrite(5, 0);
  //   ledcWrite(6, 240);
  //   frontcoloursensor();
  //    }

  // }
  //}
  // if (frontDistance < 15 && frontDistance != 0) {
  //   ledcWrite(5, 0);
  //   ledcWrite(6, 120);
  //   if (leftDistance > rightDistance){
  //     myServo.write(110);
  //     ledcWrite(5, 0);
  //     ledcWrite(6, 120);
  //   }
  //   if (rightDistance > leftDistance){
  //     myServo.write(70);
  //     ledcWrite(5, 0);
  //     ledcWrite(6, 120);
  //   }
  // }

  // if ((frontDistance < 120) && (frontDistance != 0)) {  // && (countflag = countflag++)  imphgyukgggggggggggggggg
  //   {
  //     myServo.write(75);
  //     ledcWrite(5, 0);
  //     ledcWrite(6, 150);
  //   }
  // if(frontDistance > 30)
  // {
  //  myServo.write(70);
  //   ledcWrite(5, 0);
  //   ledcWrite(6, 180);
  // }


  // if (countflag = countflag++);
  //   myServo.write(75);
  // frontcoloursensor();
  //}
  Serial.println(countflag);
  if(countflag>4){
  //  if(frontDistance < 100 && frontDistance != 0) {
    
    myServo.write(75);
    ledcWrite(5, 0);
    ledcWrite(6, 240);
    delay(3000);
    myServo.write(90);
    digitalWrite(nslp, LOW);
    delay(10000);

    
    //frontcoloursensor();
  }
  //}
  // // if(frontDistance > 100)
  // // {
    // myServo.write(75);
    // delay(3000);
    // myServo.write(90);
    // digitalWrite(nslp, LOW);
    // delay(10000);

  // }
//   delay(100);
// }
}

void TCA9548A(uint8_t bus) {
  Wire.beginTransmission(PCA9548A_ADDRESS);
  Wire.write(1 << bus);
  Wire.endTransmission();
  // delay(100);
}



void frontcoloursensor() {
  TCA9548A(0);
  // Add a delay between readings (adjust as needed)
  //delay(100);  // 100 milliseconds delay between readings (adjust as needed)
  uint16_t r, g, b, c;

  // Read the color data from the TCS34725 sensor
  tcs1.getRawData(&r, &g, &b, &c);

  // Calculate color temperature and lux
  uint16_t colorTemp = tcs1.calculateColorTemperature(r, g, b);
  uint16_t lux = tcs1.calculateLux(r, g, b);

  //Print the color data
  Serial.print("Red: ");
  Serial.print(r);
  Serial.print(" ");
  Serial.print("Green: ");
  Serial.print(g);
  Serial.print(" ");
  Serial.print("Blue: ");
  Serial.print(b);
  Serial.print(" ");
  Serial.print("Clear: ");
  Serial.print(c);
  Serial.print(" ");
  Serial.print("Color Temperature: ");
  Serial.print(colorTemp, DEC);
  Serial.print(" K ");
  Serial.print("Lux: ");
  Serial.println(lux, DEC);
  if (colorTemp > 10000) { 
    countflag++;
    // Toggle the RGB LED state rapidly

    // //turn on rgb for 1000ms
    // digitalWrite(ledPin, HIGH);
    // delay(1000);
    // //    //turn off rgb
    // digitalWrite(ledPin,LOW);
    // // delay(1000);
  }
  delay(1);
}
