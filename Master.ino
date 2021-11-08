# include <LiquidCrystal.h>  // Imports the library for the LCD screen

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 10, d7 = 9;  // Sets up all the ports for the LCD screen
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Sets up the Object for the LCD screen, called lcd
const int Contrast = 50;  // Defines the contrast of the LCD screen (Since I didn't set up the Potentiometer, I define the contrast as a constant)
int temp = 0;  // The Variable for Temperature

void setup() {
  // put your setup code here, to run once:
  analogWrite(6,Contrast);
  Serial.begin(38400);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (Serial.available() > 0) {
    temp = Serial.read();
   }
   else {
    temp = "None";
   }

   Serial.println(temp);
   
   lcd.clear();
   lcd.setCursor(0, 0);
   if (temp != "None") {
     lcd.print(((float(temp) - 32) * 5 / 9));
   }
   lcd.print(" C");
   lcd.setCursor(0, 1);
   if (temp != "None") {
     lcd.print(float(temp));
   }
   lcd.print(" F");

   delay(100);
}
