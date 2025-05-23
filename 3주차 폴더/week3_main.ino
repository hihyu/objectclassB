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

// 미세먼지 센서 && 아두이노 연동

from influxdb_client import lnfluxDBClient
import time
import serial
# === InfluxDB 2.x 설정 ===
influxdb_url= "http://localhost:8086" # 기본 URL
influxdb_token = "mi-XRGmGfeQQNhuSJopfnRgDc-zOaqtcN8qlGSGrNT3WLFoUz3KEaIvUVTzwztxh5sIUxQwFAml_JRsKDGTE9g=="
influxdb_org = "test" # influxDB에서 설정한 조직 이름
influxdb_bucket = "dust" # 데이터가 지정된 버킷 이름

# === (1) Arduino 시리얼 포트 설정 ===
serial_port = "COM12" # 아두이노 포트 (windows 기준)
baudrate = 9600 # 시리얼 통신 속도
timeout = 2 # 타임아웃 (초)

# === (2) InfluxDB 클라이언트 생성 ===
client = InfluxDBClient(url=influxdb_url, token=influxdb_token, org=influxdb_org)
write_api = client.write_api()

# == (3) 시리얼 포트 열기 ===
try:
    ser = serial.Serial(serial_port, baudrate, timeout=timeout)
    print(f"Connected to {serial_port} at {baudrate} baud")
except serial.SerialException:
    print("Failed to connect to serial port.")
    exit()

# == (4) 시리얼 데이터 읽기 및 InfluxDB 저장 ===
try:
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip() # 시리얼 데이터 읽기
            print(f"Received: {line}")

            # 데이터가 "temperature = 25.3" 같은 형식이라고 가정
            if "=" in line:
                key, value = line.split("=")
                try:
                    value = float(value) # 숫자로 변환
                    # influxDB 2.x 데이터 포맷
                    data = f"sensor_data,device = arduino {key}={value}"
                    write_api.write(bucket=influxdb_bucket, record=data)
                    print(f"Data written to InfluxDB: {key} = {value}")

                except ValueError:
                    print("Invalid data format")

            time.sleep(1) # 1초 대기

except KeyboardInterrupt:
    print("Stopping data collection...")

finally:
    ser.close()
