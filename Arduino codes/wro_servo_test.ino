const int servoPin = 17;


// centre = 40 -> 3000
// left = 0 -> 2500
// right = 80 -> 4000


void setup() {
  // put your setup code here, to run once:
  ledcSetup(1, 50, 16);
  ledcAttachPin(servoPin, 1);
  Serial.begin(115200);
}


void loop() {

  ledcWrite(1, 4000);
  delay(2000);

  ledcWrite(1, 3000);
  delay(2000);

  ledcWrite(1, 2500);
  delay(2000);





  // myservo.write(40);
  // delay(2000);

  // myservo.write(75);
  // delay(2000);
}
