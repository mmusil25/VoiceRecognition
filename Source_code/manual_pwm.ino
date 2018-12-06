void setup()
{
  pinMode(10, OUTPUT);
}

void loop()
{
  //    analogWrite(3, 230); //should be 90% duty cycle
  digitalWrite(10, HIGH);
  delayMicroseconds(250); // Approximately 10% duty cycle @ 1KHz
  digitalWrite(10, LOW);
  delayMicroseconds(1000);
}
