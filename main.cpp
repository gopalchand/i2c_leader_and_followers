/*
    To build:
    1. Install libftd2xx.so in the /usr/local/lib directory.
    2. gcc -o heartbeat_i2c.c -lftd2xx -lpthread -lrt -Wl,-rpath,/usr/local/lib
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../ftd2xx.h"
#include <unistd.h>

int main (void)
{
    FT_STATUS   ftStatus;
    int         retCode = EXIT_FAILURE;
    FT_HANDLE   ftHandle;
    DWORD       numdev = 0; 

    // Find out how many FTDI devices are connected and installed
    // If one or more is connected then open the first one

    ftStatus = FT_CreateDeviceInfoList(&numdev);

    if ((ftStatus == FT_OK) && (numdev > 0) )   
    {
        // Open the device now
       ftStatus = FT_Open(0, &ftHandle);
       if(ftStatus != FT_OK)
       {
          printf("FT_Open: status not OK %d\nCheck for ftdi_sio and usbserial in lsmod - if fuond then rmmod them plus any dependencies", ftStatus);
	  return(retCode);
        }

	// Set up transfer size 
	ftStatus = FT_SetUSBParameters(ftHandle, 16, 0);
	if(ftStatus != FT_OK)
	{
	   printf("FT_SetUSBParameters: status not OK %d\n", ftStatus);
	   return(retCode);
	}

	// Reset the device
	ftStatus = FT_ResetDevice(ftHandle);
	if(ftStatus != FT_OK)
	{
	   printf("FT_ResetDevice: status not OK %d\n", ftStatus);
       	   return(retCode);
	}

	// Set handhaking mode in the driver (internal)
	ftStatus = FT_SetFlowControl(ftHandle, FT_FLOW_RTS_CTS, FT_STOP_BITS_1, FT_PARITY_NONE);
	if(ftStatus != FT_OK)
	{
	   printf("FT_SetFlowControl: Status not OK %d\n", ftStatus);
	   return(retCode);
	}

	// Set timeouts to 5 seconds
	ftStatus = FT_SetTimeouts(ftHandle, 5000, 5000);
	if(ftStatus != FT_OK)
	{
	   printf("FT_SetFlowControl: Status not OK %d\n", ftStatus);
	   return(retCode);
	}

	// Set Latency timer (default value of 16 ms)
	ftStatus = FT_SetLatencyTimer(ftHandle, 16);
	if(ftStatus != FT_OK)
	{
	   printf("FT_SetLatencyTimer: Status not OK %d\n", ftStatus);
	   return(retCode);
	}

	// Wait for contact	
	while(1)
	{
		printf("Waiting...\n");
		DWORD MyBytesReceived = 0;
		DWORD MyBytesRead = 0;
		char InputBuffer[1];

		InputBuffer[0]=0;
		
		while(MyBytesReceived==0)
		{
		   ftStatus = FT_GetQueueStatus(ftHandle, &MyBytesReceived);
		   printf("bytes received: %d\n", MyBytesReceived);
		   if((ftStatus == FT_OK) && (MyBytesReceived != 0))
		      FT_Read(ftHandle, &InputBuffer, 1, &MyBytesRead);
		   usleep(1000000);
	    	}

		printf("Read %d\n",InputBuffer[0]);
		if(InputBuffer[0] == 0)
		{
		   printf("Ignoring...\n");
		}	

		if(InputBuffer[0] == 42)
		{
		   printf("Register 42 response is positive...\n");
		   // Now read data 
		   char data_out[2] = "Y";
		   DWORD w_data_len = 1;
		   DWORD data_written;
		
		   ftStatus = FT_Write(ftHandle, data_out, w_data_len, &data_written);
		   if(ftStatus != FT_OK)
		   {
		      printf("FT_Write: Status not OK %d\n", ftStatus);
		      return(retCode);
		   }
		   else
		      printf("1 byte sent\n");
		}
        }
        // Close the device
	ftStatus = FT_Close(ftHandle);
	if(ftStatus != FT_OK)
	{
	   printf("FT_Close: Status not OK %d\n", ftStatus);
	   return(retCode);
	}
     }
     else
        printf("No FTDI devices connnected to the computer\n");
    	 
    retCode = EXIT_SUCCESS;
    return retCode;
}
