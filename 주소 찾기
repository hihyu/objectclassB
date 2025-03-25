// i2c 주소 찾기

# include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Serial.println("I2C Scanner Running...");
}

void loop() {
  Serial.println("Scanning...");

  for (byte address=1; address<127; address++) {
    Wire.beginTransnission(address);
    if (Wire.beginTransnission() == 0) {
      Serial.print("I2c 장치 발견 : 0x");
      Serial.println(address, HEX);
      delay(500);
    }
  }

  Serial.println("Scan Complete! Retrying in 5 sconcs...\n");
  delay(5000);
}
