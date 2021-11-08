# include <LiquidCrystal.h>  // Imports the library for the LCD screen

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 10, d7 = 9;  // Sets up all the ports for the LCD screen
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Sets up the Object for the LCD screen, called lcd
const int Contrast = 50;  // Defines the contrast of the LCD screen (Since I didn't set up the Potentiometer, I define the contrast as a constant)
int temp = 0;  // The Variable for Temperature

void setup() {
  // put your setup code here, to run once:
  analogWrite(6,Contrast); // Sets up the Contrast of the screen 
  Serial.begin(38400); // Starts the Serial Communcation
  lcd.begin(16, 2); // Starts the LCD Screen
}

void loop() {
  // put your main code here, to run repeatedly:
  // Checks to see if any info from the other Arduino 
  if (Serial.available() > 0) {
    temp = Serial.read();
  }
  else {
    temp = "None";
  }
   
   lcd.clear(); // Clears the Screen
   lcd.setCursor(0, 0); // Sets it to write at position (0, 0)
   // Doesn't print anything if it doesn't recieve anything (Checking connection)
   if (temp != "None") {
     lcd.print(((float(temp) - 32) * 5 / 9));
   }
   lcd.print(" C"); // Prints C for celcius 
   lcd.setCursor(0, 1); // Sets the cursor the one row down
   // Doesn't print anything if it doesn't recieve anything (Checking connection)
   if (temp != "None") {
     lcd.print(float(temp));
   }
   lcd.print(" F"); // Prints F for Fahrenheit

   delay(100);
}
