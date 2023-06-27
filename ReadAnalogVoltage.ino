#include <SoftwareSerial.h>

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
   gsmSerial.begin(9600); // Setting the baud rate of GSM Module
   Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
   delay(1000);
   Serial.println("Preparing to send SMS");
   SendMessage();
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  if(sensorValue>400)
  {
    digitalWrite(3,HIGH); /// RED LED FOR INDICATION
    digitalWrite(4,HIGH);  /// BUZZER
    Serial.println("Setting the GSM in text mode");
   gsmSerial.println("AT+CMGF=1\r");
   delay(2000);
   Serial.println("Sending SMS to the desired phone number!");
   gsmSerial.println("AT+CMGS=\"+917094751201\"\r");
   delay(2000);

   gsmSerial.println("Gas Leakage Detected ");
   gsmSerial.println("Your Location:https://goo.gl/maps/7rb7YUoCde1cK3329");       // SMS Text
   delay(200);
   gsmSerial.println((char)26);               // ASCII code of CTRL+Z
   delay(2000);


  }
  else
  {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);

  }
}
