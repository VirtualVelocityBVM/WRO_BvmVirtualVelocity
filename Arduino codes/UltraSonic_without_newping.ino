float serial1=0;
long readUltrasonicDistance(int triggerPin, int echoPin , int maxDistance)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}
void setup()
{
  Serial.begin(115200);
}
void loop()
{
  
  serial1=0.01723 * readUltrasonicDistance(2, 4, 200);
  Serial.println(serial1);  //serial3 value
  delay(100);
}