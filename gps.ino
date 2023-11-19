#include <SoftwareSerial.h>
#include <TinyGPS++.h>

SoftwareSerial gpsSerial(13, 12); 
SoftwareSerial bluetooth(7, 6); 

TinyGPSPlus gps; // TinyGPS++ 객체 생성

void setup() {
  Serial.begin(9600); // 시리얼 모니터를 통해 디버깅 정보 출력
  gpsSerial.begin(9600); // GPS 모듈의 시리얼 통신 시작
  bluetooth.begin(9600); // 블루투스 통신 시작
}

void loop() {
  float latitude = 0.0; // 초기값 설정
  float longitude = 0.0;

  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      // GPS 데이터를 파싱하고 위도 및 경도를 가져옵니다
      if (gps.location.isValid()) {
        latitude = gps.location.lat();
        longitude = gps.location.lng();
        
        // 블루투스 모듈을 통해 안드로이드 스튜디오로 데이터 전송
        bluetooth.print("Latitude: ");
        bluetooth.println(latitude, 6); // 소수점 이하 6자리까지 표시
        bluetooth.print("Longitude: ");
        bluetooth.println(longitude, 6);
      }
    }
  }
}
