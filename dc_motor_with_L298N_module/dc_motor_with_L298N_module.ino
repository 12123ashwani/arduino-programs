int forward = 16;
int backward = 17;
void setup() {
  // put your setup code here, to run once:
  pinMode(forward,OUTPUT);
  pinMode(backward,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(forward, HIGH);
  delay(2000);
  digitalWrite(forward , LOW);
  delay(2000);
  digitalWrite(backward, HIGH);
  delay(2000);
  digitalWrite(backward, LOW);
  delay(2000);
}
