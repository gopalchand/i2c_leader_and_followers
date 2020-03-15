#include <Wire.h>

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

char command;
int piezo = 3; // Piezo buzzer
int reset1 = 5;  // Reset Computer1
int reset2 = 6;  // Reset Computer2

unsigned long interval = 500; //default interval is 500 milliseconds
unsigned long counter = 0;
unsigned long maxCounter = 1000;

int freq1 = 500;  // note 1 frequency
int freq2 = 1024; // note 2 frequency

void setup()
{
  pinMode(reset1, OUTPUT);
  pinMode(reset2, OUTPUT);
  
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start Serial for output

  Serial.println("Enter 1 or 2 to reset device 1 or 2 respectively");
  
  digitalWrite(reset1, LOW);
  digitalWrite(reset2, LOW);
}

void loop()
{
  Wire.requestFrom(22, 1);    // request 1 bytes from slave device 

  while(Wire.available())    // slave may send less than requested
  { 
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }

  delay(100);

  // Wait until a key is pressed or timeout
  counter=0;
  while((Serial.available() == 0) && counter != maxCounter)
  {
    counter++;
  }
  if(counter!=maxCounter)
  {  
    inputString = "";
    stringComplete = false;
    // Parse the string
    while (!stringComplete && (inputString.length() == 0)) 
    {
      Serial.println("reading...");
      char inChar = (char)Serial.read();
      inputString += inChar;
      if (inChar == '\n') 
      {
        stringComplete = true;
      } 
    }
   Serial.println("Just read " + String(inputString));
    Serial.println("------------------------------------------------");
    if(inputString.equalsIgnoreCase(String("1")))
    {
      tone(piezo, freq1, interval);
    
      Serial.println("Reset 1");    
      digitalWrite(reset1, HIGH);
      delay(interval);
      digitalWrite(reset1, LOW);
    }
    if(inputString.equalsIgnoreCase(String("2")))
    {
      tone(piezo, freq1, interval>>2);
      delay(interval>>2);
      tone(piezo, freq2, interval>>2);
    
      Serial.println("Reset 2");    
      digitalWrite(reset2, HIGH);
      delay(interval);
      digitalWrite(reset2, LOW);
    }
    Serial.println("------------------------------------------------");
  }
}
