#include <Wire.h>
#include <SPI.h>
#include <Ethernet.h>

//#define simulate_reset 1

#define use_ethernet 1
#define hidden_ethernet_settings 1

#ifdef use_ethernet

#ifdef hidden_ethernet_settings

#include "ipsettings.h"

#else

byte mac[] = {0x6A, 0x2F, 0x60, 0xC3, 0x8D, 0xB7};
char server[] = "www.google.com";
char getDirective[] = "GET / HTTP/1.1";
char hostDirective[] = "Host: www.google.com";
IPAddress myIP(192, 168, 1, 150);
IPAddress gatewayIP(192, 168, 1, 1);
IPAddress dnsIP(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

#endif

unsigned int timeForEthernetReady = 1000; // 1 second = 1000 ms
unsigned int httpPort = 80;
char resetSequence[] = {'#','#'}; 
boolean foundResetSequence = false;
unsigned int timeForResponse = 10000; // 10 seconds = 10000 ms

#endif

// I2C and Reset
uint8_t  piezoPin = 3; // Piezo buzzer
uint8_t  deviceCount = 2; // number of follower devices / computers
uint8_t  resetPin[2] = {5, 6}; // lines to reset computers
unsigned int interval[2] = {500, 500}; // intervals for reset for computers

uint8_t computer_id = 0;

uint8_t follower[2] = {0x21, 0x22}; // address of follower
uint8_t reg[2] = {42, 42}; // registers to read on followers
uint8_t maxRetry = 3; // retries before resetting computer
uint8_t retries[2] = {0, 0}; // number of retries for computers
unsigned int freq[2] = {300, 1000};  // note frequencies for piezo buzzer

unsigned int bytesReturned = 0; // number of bytes read from follower
uint8_t i; // index
char c; // first byte returned
uint8_t transmissionStatus = 0;

uint8_t minutesBetweenChecks = 60; // 60 minutes
uint8_t minutesForRestart = 30; // 30 minutes
uint8_t secondsInMinute = 60; // 60 seconds

char msg[100]; // Message buffer for serial output

void resetDevice(int device)
{
 sprintf(msg, "!! Resetting device %d", device+1); 
 Serial.println(msg);
 
 tone(piezoPin, freq[device], interval[device]);

#ifndef simulate_reset
 digitalWrite(resetPin[device], HIGH);
 delay(interval[device]);
 digitalWrite(resetPin[device], LOW);
#else
 sprintf(msg, "!! Simulation of device %d reset", device+1);
 Serial.println(msg); 
#endif
      
 sprintf(msg, "!! Waiting for device %d to come up", device+1);
 Serial.println(msg); 
 
 sprintf(msg, "!! Going to sleep for %d minutes", minutesForRestart);
 Serial.println(msg);  
 // Wait for device to come up
 for(i=0;i<minutesForRestart;i++)
  delay(secondsInMinute*1000UL); 
  
 sprintf(msg, "!! Done waiting for device %d", device+1);
 Serial.println(msg); 
}

#ifdef use_ethernet
void enableEthernet()
{
  // Set up Server on Ethernet
  Ethernet.begin(mac, myIP, dnsIP, gatewayIP, subnet);
  delay(timeForEthernetReady);
  if(Ethernet.localIP() != myIP)
  {
    sprintf(msg, "!! IP address not set");
    Serial.println(msg);
  }
}

void checkServer()
{
  EthernetClient client;
  sprintf(msg, "Attempting to connnect to server...");
  Serial.println(msg);
  
  if (client.connect(server, httpPort))
  {
    sprintf(msg, "Connected");
    Serial.println(msg);
    client.println(getDirective);
    client.println("User-Agent: Arduino/1.0 Ethernet2");
    client.println(hostDirective);
    client.println("Connection: close");
    client.println();
    sprintf(msg, "Sent Request");
    Serial.println(msg);
  }
  else
  {
    sprintf(msg, "Unable to connect to server");
    Serial.println(msg);
  }
  
  delay(timeForResponse);

  // reset all computers if reset sequence is encountered in the returned web page
  sprintf(msg, "Parsing response");
  Serial.println(msg);

  foundResetSequence = false;
  while((client.available()) && (foundResetSequence == false))
  {
    char c = client.read();
    if (c == resetSequence[0])
    {  
      if(client.available())
        {
          c = client.read();
          if (c == resetSequence[1])
            foundResetSequence = true;
        }
    }
    //Serial.print(c);
  }
    
  while(client.available())
  {
    c = client.read();
    //Serial.print(c);
  }
  client.stop();
}
#endif

void setup()
{
  Serial.begin(9600);  // start Serial for output
  
  sprintf(msg, "Running...");
  Serial.println(msg);

  Wire.begin();        // join i2c bus without an address
  
  // Set up reset lines
  for(i=0;i<deviceCount;i++)
  {
    pinMode(resetPin[i], OUTPUT); 
    digitalWrite(resetPin[i], LOW);
  }
#ifdef use_ethernet
  enableEthernet();
#endif
}

void loop()
{ 
#ifdef use_ethernet
  checkServer();
  // Reset all devices if reset sequence has been found
  if(foundResetSequence)
  {
    for(i=0;i<deviceCount;i++)
    {
      resetDevice(i);
      retries[i]=0; // reset retries
    } 
  }
#endif

  for(i=0;i<deviceCount;i++)
  {
    Wire.beginTransmission(folllower[i]); // start communication with follower
    Wire.write(reg[i]);      // request data from register
    
    sprintf(msg, "Transmitting to slave %d", i+1);
    Serial.println(msg);
    transmissionStatus = Wire.endTransmission(false);  // transmit bytes but do not release bus - do a repeat start
    if(transmissionStatus != 0)
    {
      sprintf(msg, "!! Failure to transmit to %d", i+1);
      Serial.println(msg);
      switch (transmissionStatus) 
      {
        case 1: sprintf(msg, "!! Data too long for tranmist buffer"); break;
        case 2: sprintf(msg, "!! NAK for transmit of address"); break;
        case 3: sprintf(msg, "!! NAK for transmit of data"); break;
        default: sprintf(msg, "!! Unknown error %d", transmissionStatus); break;
      }
      Serial.println(msg);
    }

    sprintf(msg, "Receiving data from slave %d", i+1);
    Serial.println(msg);
    bytesReturned = Wire.requestFrom(slave[i], (uint8_t) 1 , (uint8_t) true );  // get data from slave and release the bus

    sprintf(msg, "Checking response from %d", i+1);
    Serial.println(msg);
    if(bytesReturned > 0)
    {
      char c = Wire.read(); // receive a first byte as character
      
      sprintf(msg, "Read the following from slave %d: 0x%x (%c)\n", i+1, c, c);
      Serial.println(msg);
      
      if(c=='Y')
      {
        // Positive response
        sprintf(msg, "Positive response from slave %d", i+1);
        Serial.println(msg);

        retries[i]=0;        
      }
      else
      {
        sprintf(msg, "!! Unexpected response from slave %d", i+1);
        Serial.println(msg);

        retries[i]++;
      }
    }
    else
    {
        sprintf(msg, "!! Negative response from slave %d", i+1);
        Serial.println(msg);

        retries[i]++;
    }
    
    sprintf(msg, "Retry count for slave %d is %d\n", i+1, retries[i]);
    Serial.println(msg);

    if(retries[i] == maxRetry)
    { 
      retries[i]=0;
      resetDevice(i);
    }
  }

  // Sleep before next check
  sprintf(msg, "Going to sleep for %d minutes\n", minutesBetweenChecks);
  Serial.println(msg);  
  for(i=0;i<minutesBetweenChecks;i++)
      delay(secondsInMinute*1000UL); 
}
