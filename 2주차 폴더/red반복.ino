int red1 = 7;
int grd1 = 8;
void setup()
{
  pinMode(red1, OUTPUT);
  pinMode(grd1, OUTPUT);
  pinMode(blue1, OUTPUT);
}

void loop()
{
  digitalWrite(red1, HIGH);
  digitalWrite(grd1, 0);
  delay(1000);
  digitalWrite(red1, 0);
  digitalWrite(grd1, 1);
  delay(1000);
}
