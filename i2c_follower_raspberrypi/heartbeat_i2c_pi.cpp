// credit LinusCDE98

#include <pigpio.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int runFollower();
int closeFollower();
int getControlBits(int, bool);

const int slaveAddress = 0x21;
bsc_xfer_t xfer;

int main()
{
   if(runFollower() != 0)
      return 1; 
   else
   {
      closeFollower();
      return 0;  
   }
}

int val, status, data;

int runFollower()
{
   val=gpioInitialise();
   if(val <0)
   {
      printf("Unable to initialise GPIO\n");
      return 1;
   }
   xfer.control = getControlBits(slaveAddress, false);
   bscXfer(&xfer);
   xfer.control = getControlBits(slaveAddress, true);
   status = bscXfer(&xfer);
   printf("bscXfer returns with %d\n", status);
   if(status >= 0)
   {
      xfer.rxCnt = 0;
      while(1)
      {
         bscXfer(&xfer);
         if(xfer.rxCnt > 0)
         {
            data = xfer.rxBuf[0];
            printf("Received %d\n", data);
            if (data == 42)
            {
               // transmit positive response 
               printf("Responding with Y\n", data); 
               xfer.txBuf[0]=89; // ASCII "Y"
               xfer.txCnt = 1;
               bscXfer(&xfer); 
            }
         }
         usleep(1000000); // sleep for a second
      }
   }
}

int closeFollower()
{
   gpioInitialise();

   xfer.control = getControlBits(slaveAddress, false);
   bscXfer(&xfer);
   
   gpioTerminate();
   
   return 0;
}

int getControlBits(int address, bool open)
{
   int flags;

   if(open)
      flags = (1<<9)| // Enable Rx
              (1<<8)| // Enable Tx
              (1<<2)| // Enable i2c 
              (1<<0);  // Enable Bsc
   else
      flags = (1<<7)| // Abort/Clear
              (0<<2)| // Disable i2c
              (0<<0);  // Disable Bsc

   return (address << 16) | flags;
}
