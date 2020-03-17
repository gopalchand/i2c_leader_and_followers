#include <Wire.h>

char errMsg[255];
uint8_t  piezoPin = 3; // Piezo buzzer
uint8_t  deviceCount = 2; // number of slave devices / computers
uint8_t  resetPin[2] = {5, 6}; // lines to reset computers
unsigned int interval[2] = {500, 500}; // intervals for reset for computers

uint8_t computer_id = 0;
uint8_t slave[2] = {0x21, 0x22}; // address of slaves
uint8_t reg[2] = {42, 42}; // registers to read on slaves
uint8_t maxRetry = 3; // retries before resetting computer
uint8_t retries[2] = {0, 0}; // number of retries for computers
unsigned int freq[2] = {300, 1000};  // note frequencies for piezo buzzer

unsigned int bytesReturned = 0; // number of bytes read from slave
uint8_t i; // index
char c; // first byte returned
uint8_t transmissionStatus = 0;

//unsigned long timeBetweenChecks = 60*60*1000; // 60 minutes  // TODO - use for production
unsigned long timeBetweenChecks = 5000; // 5 seconds
//unsigned long timeForRestart = 30*60*1000 // 30 minutes // TODO - use for production
unsigned long timeForRestart = 5000; // 5 seconds

// Display debug message for particular device (slave/computer)
void debugMsg(String string1, unsigned int device)
{
    Serial.print(string1);
    Serial.println(device);
}

void setup()
{
  Serial.begin(9600);  // start Serial for output
  Wire.begin();        // join i2c bus without an address
  
  // Set up reset lines
  for(i=0;i<deviceCount;i++)
  {
    pinMode(resetPin[i], OUTPUT); 
    digitalWrite(resetPin[i], LOW);
  }
}

void loop()
{
  for(i=0;i<deviceCount;i++)
  {
    debugMsg("Requesting data from device ", i+1);    
    Wire.beginTransmission(slave[i]); // start communication with slave
    //debugMsg("..Register ", i+1);
    Wire.write(reg[i]);      // request data from register
    //debugMsg("..Transmit ", i+1);
    transmissionStatus = Wire.endTransmission(false);  // transmit bytes but do not release bus - do a repeat start
    if(transmissionStatus != 0)
    {
      debugMsg("...Error in transmission #1 for device ", i+1);
      switch (transmissionStatus) 
      {
        case 1: sprintf(errMsg, "Data too long for tranmist buffer"); break;
        case 2: sprintf(errMsg, "NAK for transmit of address"); break;
        case 3: sprintf(errMsg, "NAK for transmit of data"); break;
        default: sprintf(errMsg, "Unknown error %d", transmissionStatus); break;
      }
      Serial.println(errMsg);
    }
    //debugMsg("..Request ", i+1);
    bytesReturned = Wire.requestFrom(slave[i], (uint8_t) 1 , (uint8_t) true );  // get data from slave and release the bus

    //debugMsg("..Check ", i+1);
    if(bytesReturned > 0)
    {
      char c = Wire.read(); // receive a first byte as character
      if(c=='Y')
      {
        // Positive response
        debugMsg("...Positive response from device ", i+1);
        retries[i]=0;        
      }
    }
    else
    {
        debugMsg("...Negative/no response from device ", i+1);
        retries[i]++;
    }
    if(retries[i] == maxRetry)
    { 
      retries[i]=0;     
      debugMsg(">>>>>>>>>>>>> Resetting device ", i+1);      
      tone(piezoPin, freq[i], interval[i]);
      
      digitalWrite(resetPin[i], HIGH);
      delay(interval[i]);
      digitalWrite(resetPin[i], LOW);
      
      debugMsg(">>>>>>>>>>>>> Waiting for device to come up ", i+1); 
      delay(timeForRestart); // Wait for device to come up
      debugMsg(">>>>>>>>>>>>> Done waiting ", i+1); 
    }
  }
  delay(timeBetweenChecks);
}
