// credit LinusCDE98

#include <pigpio.h>
#include <iostream>

using namespace std;

int runSlave();
int closeSlave();
int getControlBits(int, bool);

const int slaveAddress = 0x21;
bsc_xfer_t xfer;

int main()
{
   if(runSlave() != 0)
      return 1; 
   else
   {
      closeSlave()
      return 0;  
   }
}

int val, status, data;

int RunSlave()
{
   val=gpio.Initialise();
   if(val <0)
   {
      printf("Unable to initialise GPIO\n");
      return 1;
   }
   xfer.control = getControlBits(slaveAddress, false);
   bscXfer(&xfer);
   xfer.control = getControlBits(slaveAdress, true);
   status = bsXfer(&xfer);
   if(status >= 0)
   {
      xfer.rxCnt = 0;
      while(1)
      {
         bscXfer(&xfer);
         if(xfer.rxCnt > 0)
         {
            data = xfer.rxBuf[i];
            printf("Received %d\n", data);
         }
      }
   }
}

int closeSlave()
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
      flags = (1<<7)| // Abort/Clea
              (0<<2)| // Disable i2c
              (0<<0);  // Disable Bsc

   return (address << 16) | flags;
}