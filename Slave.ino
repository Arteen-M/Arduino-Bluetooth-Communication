int ThermistorPin = A0;  // Thermistor Analog Input Pin
int Vo;  // Voltage Variable
// Constants for Temperature Calculations
const float R1 = 10000;
const float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
// Variables for Temperature Calculations
float logR2, R2, T;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);  // Starts the Serial Communication between the two modules
}

void loop() {
  // put your main code here, to run repeatedly:
  Vo = analogRead(ThermistorPin); // Reads Voltage
  // Calculates Temperature
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0;
  
  Serial.write(long(T)); // Sends the Temperature (If it's not long, it will error)
  
  delay(100);
   
}
