#include <rgb_lcd.h>

rgb_lcd lcd;
const int buzz = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzz, OUTPUT);
  lcd.begin(16,2);
  //red,green,blue
  lcd.setRGB(255,0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int moisture = analogRead(A0);
  if (moisture <= 50)
  {
    lcd.setCursor(0,0);
    lcd.println("Ready!!");
  }
  if (moisture > 50 && moisture <= 300)
  {
    lcd.setCursor(0,0);
    lcd.println("Moisture low");
  }
  else if (moisture > 300 && moisture < 600)
  {
    lcd.setCursor(0,0);
    lcd.println("Moisture optimal");
    digitalWrite(buzz, LOW);
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.println("Moisture high");
    digitalWrite(buzz, HIGH);
  }
}
