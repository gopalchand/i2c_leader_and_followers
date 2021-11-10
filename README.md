# i2c_leader_and_followers
Created by Gopal Chand

## What is it?
Lights out management using an Arduino. 

An Arduino i2c leader checks the status of Raspberry Pi 3, Linux or Windows® i2c followers and reboots them through a hardware reset if necessary. The reboot can be forced if required through a web page code downloaded using an Ethernet shield.

An i2c tutorial can be found here: https://www.robot-electronics.co.uk/i2c-tutorial

## When would I need it?
Remote hardware with internet connectivity that requires physical hardware reboots after becoming non-reseponsive on the network.

## Hardware pre-requisites
Arduino Uno Board (i2c leader)

Arduino ethernet shield e.g. WizNet Wiz550io

Raspberry Pi 3 B+ with BCM2837xx GPIO chip (i2c follower)

FTDI UMFT201XB-WE Development Board for Ubuntu or Windows® (i2c follower)

Logic Level Converter e.g. KeeYees 4 Channels IIC I2C Logic Level Converter Bi-Directional Module 3.3V to 5V Shifter for Arduino (convert Arduino +5V to Raspberry Pi and FTDI UMFT201XB-WE +3.3V).

## Hardware for device resets
PC prototyping board e.g. Gikfun Prototype Shield DIY KIT For Arduino UNO R3 Mega 328P

Up to 2 of the following (1 for each follower)

  10K resistor
  
  100K resistor
  
  BC108 transistor
  
Optional buzzer

## Hardware schematic

Subfolder Arduino_i2c_Leader_rev6 contains a KiCad EeSchema file (https://kicad.org/)

## Arduino Uno leader installation

Subfolder i2c_leader_arduino contains i2c_leader_arduino.ino file

The use_ethernet compiler directive is set to 1 if an Ethernet shield is being used
The hidden_ethernet_settings compiler directive is set to 1 then enter the details for the website with the reset code in the file ipsettings.h:

mac: MAC address for the Ethernet shield

server: DNS name of the web server

getDirective: GET directive to use (contains file to download after /). The file should contain "##" to force a reboot

hostDirective: HTTP directive required for proper operation

myIP: IP address of the Ethernet shield

gatewayIP: IP address of the gateway

dnsIP: IP address of the DNS server

subnet: Subnet mask

Note: If the return IP address is 0.67.67.67 then the Ethernet library may be too old e.g. Linux Arduino installation. In this case, compile it on a Windows® system with a an IDE version of 1.8.12 or higher transfer %temp%/arduino_build_xxx/i2c_leader_arduino.ino.hex to the target system. Run avrdude:

/usr/share/arduino/hardware/tools/avrdude -v -p atmega328p -c arduino -P /dev/ttyACM0 -b 115200 -D -U flash:w:i2c_leader_arduino.ino.hex:i 

In all cases, test the successful installation with:

stty -F /dev/ttyACM0 ispeed 9600 ospeed 9600 -ignpar cs8 -cstopb -echo
cat /dev/ttyACM0

Replace ttyACM0 with the correct Arduino device if necessary.

## Ubuntu follower installation
Download appropriate 16-bit or 32-bit D2XX drivers for Linux from https://www.ftdichip.com/Drivers/D2XX.htm

Download the readme file: https://www.ftdichip.com/Drivers/D2XX.htm

Extract to /root/libftd2xx (rename with a .tar extension may be necessary)

cp release/build/libftd2xx.* /usr/local/lib
chmod 0755 /usr/local/lib/libftd2xx*
ln -sf /usr/local/lib/libftd2xx.so.1.4.8 /usr/local/lib/libftd2xx.so

change 1.4.8 to the latest version if necessary

Copy subfolder i2c_follower_ubuntu files Makefile and heartbeat_i2c.cpp to release/examples/heartbeat_i2c

Ensure that installed modules do not interfere with D2XX driver access by editing /etc/modprobe.d/blacklist
add:
blacklist usb_wwan
blacklist qserial
blacklist usbserial
blacklist ftdi_sio

reboot

run make in hearbeat_i2c  
run heartbeat_i2c

A crontab entry is necessary to ensure that the follower software is able to respond to requests afer a reboot.

## Windows® follower installation
Download the Windows® driver from https://www.ftdichip.com/Drivers/D2XX.htm

Download the appropriate installation guide and follow the instructions: https://www.ftdichip.com/Support/Documents/InstallGuides.htm

See Ubuntu installation instructions for further details

## Raspberry pi Installation (model 3 only)
Background: https://raspberrypi.stackexchange.com/questions/76109/raspberry-as-an-i2c-slave

Install pigpio:

wget https://github.com/joan2937/pigpio/archive/master.zip
unzip master.zip
cd pigpio-master
make
sudo make install

Folder i2c_follower_raspberrypi contains the follower file. A crontab entry is necessary to ensure that the follower software is able to respond to requests afer a reboot.

## Known limitations
Raspberry Pi 3 is required. The Raspberry Pi 4 has the BCM2711 chip and is not supported in this code.

Raspberry Pi not using interrupts and CPU loading will occur.

The BCM2837 i2c follower using the Broadcom Serial Controller (BSC) does not support clock stretching or DMA.

## License
This entire project is available under the GNU General Public License v3 licence. See licence.txt for more details.
