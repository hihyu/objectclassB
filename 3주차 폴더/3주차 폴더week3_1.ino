// 미세먼지 센서

int Vo = A0;
int V_led = 2;

float Vo_value = 0;
float VoLtage = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(V_led, OUTPUT); 
  pinMode(Vo, INPUT); 
}

void loop() {
  digitalWrite(V_led, 0);
  delayMicroseconds(280);
  Vo_value = analogRead(Vo);
  delayMicroseconds(40);
  digitalWrite(V_led,1);

  VoLtage = Vo_value*5.0 / 1023.0;
  dustDensity = (VoLtage - 0.3)/0.005;

  Serial.print("dust = ");
  Serial.println(VoLtage);
  Serial.print("dustDensity = ");
  Serial.println(dustDensity);

  delay(1000);
}
