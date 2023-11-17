#include <SoftwareSerial.h>

int piezo = 6;
SoftwareSerial bluetooth (2,3);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(A1, INPUT);
  pinMode(piezo, OUTPUT);
}
void loop() {
  int alc = analogRead(A1);

  if (alc < 350) {
    Serial.print(alc);
    Serial.println(".0"); //OK.
    noTone(piezo);
    bluetooth.println("0");
  }
  else {
    Serial.print(alc);
    Serial.println("1"); //Warning
    tone(piezo, 1567);
    bluetooth.println("1");
  }
  
  delay(1000);
}
