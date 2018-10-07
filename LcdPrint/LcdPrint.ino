#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

SoftwareSerial mySerial(2, 3); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정
LiquidCrystal_I2C lcd(0x3F, 16, 2
);

void setup() {
  // 시리얼 통신의 속도를 9600으로 설정
  Serial.begin(9600);
  while (!Serial) {
    ; //시리얼통신이 연결되지 않았다면 코드 실행을 멈추고 무한 반복
  }

  // I2C LCD를 초기화 합니다..
  lcd.init();
  // I2C LCD의 백라이트를 켜줍니다.
  lcd.backlight();

  lcd.setCursor(0,0);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
  lcd.print("  Hello, World!  ");       // 문구를 출력합니다.
  lcd.setCursor(0,1);            // 0번째 줄 0번째 셀부터 입력하게 합니다.
  lcd.print("  ~Ready~  ");       // 문구를 출력합니다.
  Serial.println("Hello, World!");

  //블루투스와 아두이노의 통신속도를 9600으로 설정
  mySerial.begin(9600);

  delay(5000);
  lcd.init();
}

void loop() { //코드를 무한반복합니다.
  
  
  if (mySerial.available()) { //블루투스에서 넘어온 데이터가 있다면
    Serial.write(mySerial.read()); //시리얼모니터에 데이터를 출력
  }
  if (Serial.available()) {    //시리얼모니터에 입력된 데이터가 있다면
    mySerial.write(Serial.read());  //블루투스를 통해 입력된 데이터 전달
  }

  
}
