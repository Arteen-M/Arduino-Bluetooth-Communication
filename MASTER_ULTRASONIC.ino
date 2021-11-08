# include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 10, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  
int Contrast = 50;
int temp = 0;

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

// Master Code

//#define greenLedPin 8
//#define masterSwitchPin 7
//int dataFromSlave = 0;

//void setup() {
//  pinMode(greenLedPin, OUTPUT);
//  digitalWrite(greenLedPin, LOW);
//  pinMode(masterSwitchPin, INPUT);
//  digitalWrite(masterSwitchPin,LOW);
//  Serial.begin(38400); // Default baud rate of the Bluetooth module
//}
//void loop() {
// if(Serial.available() > 0){ // Checks whether data is comming from the serial port
//   dataFromSlave = Serial.read(); // Reads the data from the serial port and store it in dataFromSlave variable
 //}
 // Controlling the Buzzer
 //if (dataFromSlave == '1') {
  //digitalWrite(greenLedPin, HIGH); // led ON
// }
// else if (dataFromSlave == '0') {
//  digitalWrite(greenLedPin, LOW); // led OFF
// }
 
 // Reading the masterSwitchValue
// int masterSwitchValue = digitalRead(masterSwitchPin);
// if (masterSwitchValue == HIGH) {
//   Serial.write('1'); // Sends '1' to the master to turn on BUZZER
// }
// else {
//   Serial.write('0');
// }  
// delay(10);
//}
