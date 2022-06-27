#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String cmd;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
      delay(100);
      

      cmd = Serial.readStringUntil('\r');
      
      lcd.clear();
      lcd.print(cmd);
      
    }
}
