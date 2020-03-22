# i2c_master_and_slaves
i2c Arduino master and Raspberry Pi plus Ubuntu slaves

# Arduino Uno installation
If the return IP address is 0.67.67.67 then the Ethernet library is too old (Linux Arduino). Compile on a Windows system with a an IDE version of 1.8.12 or higher.

# Ubuntu PC installation

https://www.ftdichip.com/Drivers/D2XX.htm
Check the readme file: https://www.ftdichip.com/Drivers/D2XX.htm
Download 16-bit or 32-bit D2XX driver for Linu
Extract to /root/libftd2xx (rename with a .tar extension may be necessary)

cp release/build/libftd2xx.* /usr/local/lib
chmod 0755 /usr/local/lib/libftd2xx*
ln -sf /usr/local/lib/libftd2xx.so.1.4.8 /usr/local/lib/libftd2xx.so

change 1.4.8 to the latest version if necessary

Copy Makefile and main.cpp to release/examples/heartbeat_i2c

edit /etc/modprobe.d/blacklist`
add:
blacklist usb_wwan
blacklist qserial
blacklist usbserial
blacklist ftdi_sio

reboot

run make in hearbeat_i2c  
run heartbeat_i2c

# Raspberry pi Installation (model 3 only)
