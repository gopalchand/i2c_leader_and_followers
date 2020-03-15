/*
    From version 1.4 onwards, libftd2xx easily supports devices with
    custom Vendor and Product Ids.  Call FT_SetVIDPID for every VID+PID
    that you wish your D2XX application to support.  There is no longer
    any need to call FT_GetVIDPID, and the deprecated LibTable method
    no longer works.
    
    To build:
    1. Install libftd2xx.so in the /usr/local/lib directory.
    2. gcc -o setVIDPID main.c -lftd2xx -lpthread -lrt -Wl,-rpath,/usr/local/lib
*/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../ftd2xx.h"
#include <unistd.h>

#ifndef _countof
    #define _countof(a) (sizeof(a)/sizeof(*(a)))
#endif /* _countof */



int main (void)
{
    FT_STATUS   ftStatus;
    size_t      i;
    int         retCode = EXIT_FAILURE;
    DWORD       libVersion = 0;
    DWORD       standardDevices = 0;
    DWORD       totalDevices = 0;
    /* Specify as many VID+PID pairs as you wish to support. */
    DWORD       vid[] = {0x0403, 0x7654, 0x7777, 0xdcba, 0x5a5a};
    DWORD       pid[] = {0x4242, 0x1234, 0xabcd, 0xa5a5, 0xdcba};

    FT_HANDLE   ftHandle;
    DWORD       numdev = 0; 

    (void)FT_GetLibraryVersion(&libVersion);
    printf("D2XX version %08X\n", (unsigned int)libVersion);

    if (libVersion < 0x00010400)
    {
        printf("This version of D2XX does not correctly support "
               "multiple calls to FT_SetVIDPID.\n");
        goto exit;
    }

    /* Initially, FT_ListDevices, FT_Open and FT_CreateDeviceInfoList 
     * only consider devices with standard FTDI Vendor and Product Ids. 
     */
    ftStatus = FT_ListDevices(&standardDevices, 
                              NULL, 
                              FT_LIST_NUMBER_ONLY);
    if (ftStatus != FT_OK) 
    {
        printf("FT_ListDevices failed: error code %d.\n", (int)ftStatus);
        goto exit;
    }

    printf(
        "%d device%s with standard FTDI Vendor and Product Ids detected.\n",
        (int)standardDevices,
        standardDevices == 1 ? "" : "s"
        );

    /* Tell D2XX about our additional VID+PID combinations. */
    assert(_countof(vid) == _countof(pid));
    for (i = 0; i < _countof(vid); i++)
    {
        ftStatus = FT_SetVIDPID(vid[i], pid[i]);
        if (ftStatus != FT_OK)
        {
            printf("FT_SetVIDPID failed: error code %d.\n", (int)ftStatus);
            goto exit;
        }
    }

    /* Now FT_ListDevices, FT_Open and FT_CreateDeviceInfoList will
     * consider devices with our custom Vendor and Product Ids, as 
     * well as the standard FTDI Vendor and Product Ids.
     */

    ftStatus = FT_ListDevices(&totalDevices, 
                              NULL, 
                              FT_LIST_NUMBER_ONLY);
    if (ftStatus != FT_OK) 
    {
        printf("FT_ListDevices failed: error code %d.\n", (int)ftStatus);
        goto exit;
    }

    printf(
        "%d supported device%s detected: %d standard, %d custom.\n",
        (int)totalDevices,
        totalDevices == 1 ? "" : "s",
        (int)standardDevices,
        (int)(totalDevices - standardDevices)
        );

    // Find out how many FTDI devices are connected and installed
    // If one or more is connected then open the first one

    ftStatus = FT_CreateDeviceInfoList(&numdev);

    printf("%d devices connected/installed\n",numdev);
   
    if ((ftStatus == FT_OK) && (numdev > 0) )   
    {
        // Open the device now
       ftStatus = FT_Open(0, &ftHandle);
       if(ftStatus != FT_OK)
          printf("FT_Open: status not OK %d\nCheck for ftdi_sio and usbserial in lsmod - if fuond then rmmod them plus any dependencies", ftStatus);
	
	// Set up transfer size 
	ftStatus = FT_SetUSBParameters(ftHandle, 16, 0);
	if(ftStatus != FT_OK)
	   printf("FT_SetUSBParameters: status not OK %d\n", ftStatus);

	// Reset the device
	ftStatus = FT_ResetDevice(ftHandle);
	if(ftStatus != FT_OK)
	   printf("FT_ResetDevice: status not OK %d\n", ftStatus);
       
	// Set handhaking mode in the driver (internal)
	ftStatus = FT_SetFlowControl(ftHandle, FT_FLOW_RTS_CTS, FT_STOP_BITS_1, FT_PARITY_NONE);
	if(ftStatus != FT_OK)
	   printf("FT_SetFlowControl: Status not OK %d\n", ftStatus);

	// Set timeouts to 5 seconds
	ftStatus = FT_SetTimeouts(ftHandle, 5000, 5000);
	if(ftStatus != FT_OK)
	   printf("FT_SetFlowControl: Status not OK %d\n", ftStatus);

	// Set Latency timer (default value of 16 ms)
	ftStatus = FT_SetLatencyTimer(ftHandle, 16);
	if(ftStatus != FT_OK)
	   printf("FT_SetLatencyTimer: Status not OK %d\n", ftStatus);

	// Wait for contact	
	DWORD MyBytesReceived = 0;
        while(MyBytesReceived == 0) 
	{ 	
	    printf("Waiting...\n");	
	    FT_GetQueueStatus(ftHandle, &MyBytesReceived);
            usleep(1000000); 			
	}

	printf("Responding...\"n");
	// Now read data 
	char data_out[2] = "Y";
	DWORD w_data_len = 2;
	DWORD data_written;

	ftStatus = FT_Write(ftHandle, data_out, w_data_len, &data_written);
	if(ftStatus != FT_OK)
	   printf("FT_Write: Status not OK %d\n", ftStatus);
	else
	   printf("1 byte sent\n");
        
        // Close the device
	ftStatus = FT_Close(ftHandle);
     }
     else
        printf("No FTDI devices connnected to the computer\n");
    	 
     retCode = EXIT_SUCCESS;

exit:
    return retCode;
}
