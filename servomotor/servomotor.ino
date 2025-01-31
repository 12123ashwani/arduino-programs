 #include <ESP32Servo.h>

Servo myservo;
void setup()
{
  myservo.attach(13);
}
void loop() { 
  myservo.write(0);
  delay(2000);
  myservo.write(30);
  delay(2000);
  myservo.write(60);
  delay(1000);

}
