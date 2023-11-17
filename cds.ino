int ldrPin[] = {A0, A1, A2, A3};
int piezo = 5;
int threshold = 350; //이거 숫자 바꿔서 조정해야함.

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(ldrPin[i], INPUT);
  }
}

void loop() {
  int coveredSensors = 0;
  for (int i = 0; i < 4; i++) {
    int ldrValue = analogRead(ldrPin[i]);
    Serial.print("LDR ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(ldrValue);
    if (ldrValue < threshold) {
      coveredSensors++;
    }
  }


  if (coveredSensors >= 3) {
    tone(piezo, 1567);
  } else {
    noTone(piezo);
  }

  delay(1000); // 출력을 명확하게 보기 위해 딜레이를 1초로 변경
}
