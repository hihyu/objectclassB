int red1 = 7;

void setup()
{
  pinMode(red1, OUTPUT);
}

void loop()
{
  digitalWrite(red1, 1);
  delay(500);
  digitalWrite(red1, 0);
  delay(500);
}
