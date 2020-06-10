#include <LiquidCrystal.h>
LiquidCrystal lcd01(13, 12, 11, 10, 9, 8);
void setup() {
  // put your setup code here, to run once:
  int humi01 = A0; int flame01 = A1; int agas01 = A2; 
  pinMode (5, OUTPUT);
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (A2, INPUT);
  analogWrite(2, 50);
  lcd01.begin(16, 2);
  
}

  void loop() {
  // put your main code here, to run repeatedly:
  int humi01; int Rhumi; int Thumi;
  int sensorValue0; 
  sensorValue0 = analogRead(A0);
  Rhumi = sensorValue0 / 10;
  Thumi = sensorValue0 / 24;
  if (humi01 > 75){ //change value later
  lcd01.setCursor(0, 1);
  lcd01.print("Wet Warning!");
  }
  else if  (humi01 < 0) {
  lcd01.setCursor(0, 1);
  lcd01.print("Dry Warning!");
  }
  else {
    lcd01.setCursor(0, 0);
    lcd01.print(Rhumi);
    delay(1000);
     lcd01.setCursor(4, 0);
    lcd01.print(Thumi);
    delay(1000);
    }
    
 int flame01; int sensorValue1; int led01; int C;
  sensorValue1 = analogRead(A1);
  if(sensorValue1>760) { //change value later
  lcd01.setCursor(0, 1);
  lcd01.print("Fire Warning!");
  
  digitalWrite(5, LOW);
  delay(100);
  }
  else {
    lcd01.setCursor(8, 0);
    lcd01.print(sensorValue1);
    delay(1000);
    digitalWrite(5, LOW);
    delay(100);
  }
 
  int agas01; int sensorValue3; int RH; 
  sensorValue3 = analogRead(A3);
  if (agas01>0) { //change value later
  lcd01.setCursor(0, 1);
  lcd01.print("Gas Warning!");
  }
  else {
  lcd01.setCursor(13, 0);
  lcd01.print(sensorValue3);
  delay(1000);
  }
      lcd01.setCursor(0, 1);
    lcd01.print("Test Warning!");
    }


