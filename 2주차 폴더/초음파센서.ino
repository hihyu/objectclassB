// 초음파 센서를 활용해서 led가 반복시 시리얼 모니터에 출력

#define TRIG 12
#define ECHO 11

int red1 = 7;
int grd1 = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(red1, OUTPUT);
  pinMode(grd1, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop()
{
  long duration,distance;
    
  digitalWrite(TRIG, 0);
  delayMicroseconds(2);
  digitalWrite(TRIG, 1);
  delayMicroseconds(10);
  digitalWrite(TRIG, 0);
  
  duration = pulseIn(ECHO, 1);
  
  distance = duration * 17 / 1000;
  Serial.println(duration );
  Serial.print("\nDIstance : ");
  Serial.print(distance);
  Serial.println(" Cm");
  
  digitalWrite(red1, HIGH);
  delay(1000);
  digitalWrite(red1, 0);
  delay(1000);
  digitalWrite(grd1, HIGH);
  delay(1000);
  digitalWrite(grd1, 0);
  delay(1000);
}
