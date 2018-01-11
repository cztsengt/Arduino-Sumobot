/* 
  Version:    3
  Ultrasonice Sensor + Motor
*/
//   Ultrasonic Sensor
#define echoPin A2
#define trigPin A5
#define MAX_DIST 30// max. distance in cm
 
//  Motor
int enablePin1 = 10;
int in1Pin1 = 7;
int in2Pin1 = 9;
 
int enablePin2 = 3;
int in1Pin2 = 4;
int in2Pin2 = 5;
const int MAX_SPEED = 150;    // can be 0-255
 
void setup()
{
  Serial.begin(9600);  //  for debuging if needed
 
  //  Ultrasonic Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  //  Motor
  pinMode(in1Pin1, OUTPUT);
  pinMode(in2Pin1, OUTPUT);
  pinMode(enablePin1, OUTPUT);
 
  pinMode(in1Pin2, OUTPUT);
  pinMode(in2Pin2, OUTPUT);
  pinMode(enablePin2, OUTPUT);
}
 
void loop()
{
  boolean foundObject;
 
  foundObject = detect();
 
  if (foundObject)
  {
    moveForward(3000);   // move forward for 3000 milliseconds
     Serial.print("Forward");
  }
  else
  {
    turnRight(1000);    //  move forward for 1000 milliseconds
    Serial.print("Right");
  }

    
    
}
 
boolean detect()
{
  long duration, distance;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 
  // debug
  Serial.print(distance);
  Serial.println(" cm");
 
  if (0 < distance && distance < MAX_DIST)
    return true;
  else 
    return false;
}
 
void moveForward(int durationInMilliSec)
{
  analogWrite(enablePin1, MAX_SPEED);
  digitalWrite(in1Pin1, HIGH);   //   HIGH/LOW values have to be adjusted
  digitalWrite(in2Pin1, LOW);
 
  analogWrite(enablePin2, MAX_SPEED);
  digitalWrite(in1Pin2, LOW);    //   HIGH/LOW values have to be adjusted
  digitalWrite(in2Pin2, HIGH);
  delay(durationInMilliSec);
}
 
void turnRight(int durationInMilliSec)
{
  analogWrite(enablePin1, MAX_SPEED);
  digitalWrite(in1Pin1, LOW);    //   HIGH/LOW values have to be adjusted
  digitalWrite(in2Pin1, HIGH);
 
  analogWrite(enablePin2, MAX_SPEED);
  digitalWrite(in1Pin2, HIGH);    //   HIGH/LOW values have to be adjusted
  digitalWrite(in2Pin2, LOW);
  delay(durationInMilliSec);
}
