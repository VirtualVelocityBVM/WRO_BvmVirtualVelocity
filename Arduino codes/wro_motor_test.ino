const int motorPin1 = 32;  // Motor driver IN1 pin
const int motorPin2 = 33;  // Motor driver IN2 pin


const int motorSpeed = 255;  // Motor speed (0 to 255)
const int motorEnablePin = 13;

void setup() {
  pinMode(motorEnablePin, OUTPUT);
  digitalWrite(motorEnablePin, HIGH);  // Enable motors initially
  ledcSetup(0, 5000, 8);
  ledcSetup(1, 5000, 8);

  ledcAttachPin(motorPin1, 0);
  ledcAttachPin(motorPin2, 1);
  Serial.begin(115200);
}

// Function to move both motors forward
void moveForward() {
  // digitalWrite(motorEnablePin, HIGH);
  ledcWrite(0, 0);
  ledcWrite(1, motorSpeed);
}

// Function to stop both motors
void stopMotors() {
  // digitalWrite(motorEnablePin, LOW);  // Disable motors
  ledcWrite(0, 0);
  ledcWrite(1, 0);
}

void loop() {
  // Example usage:
  moveForward();  // Move forward
  delay(2000);    // Keep moving forward for 2 seconds

  stopMotors();  // Stop the motors
  delay(1000);   // Pause for 1 second

  // Perform other motor control actions as needed
}
