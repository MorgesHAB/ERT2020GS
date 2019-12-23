[<img src="doc/img/bellalui.png" width=180 align="right" >](https://epflrocketteam.ch/fr/)

# EPFL Rocket Team - <em>Bella Lui Project 2020</em>

### Goal 
Spaceport America Cup competition - Launch a Rocket to the exact altitude of 10'000 feets  
SRAD Hybrid Engine category. 
For more informations : https://epflrocketteam.ch/fr/ :rocket:

### Description
Code of the <b>Ground Segment system</b> which will run on a Raspberry Pi 4 with XBee RF modems.

-----------------------------------------------------------------
## Repository organization

 * doc
    * ...
    * html
        * ...
        * index.html // open this file on a web browser 
                after cloning the project, to read the doxygen documentation 
        * ...
  * Logger
    * ... // under development
  * src  // cpp file with a main() function
    * Gui.cpp  //for the multitread program GUI + RF communication management
    * Igniter.cpp  // for the ignition test simulate with a RPi
    * GSE.cpp // Ground Support Equipment
  * Telecom // Telecommunication Objects
    * DataHandler
      * DataHandler // contain Datagrams
      * Datagram // contain Data & a Packet
    * DataStructures // All kind of Data that will be transmit
      * Avionic
        * Avionic Data
      * File
        * Manage the transmission of all kind of file / image / picture with a TCP
      * FrameInfo
        * Header, Xbee options, etc
      * Propulsion
        * Ignition packet, Prop data, etc
      * ...
      * Template  // follow this when creating new Data structure
    * RFmodem
      * lib
        * serial // library for XBee module
        * RadioHead // library for LoRa module
      * ... // Your RFmodem classes 
    * Serializer
    * Worker // main routine - contain a RFmodem & a data handler
  * UI
    * GuiWindow // management of the front end part
    * ui_form.h  // the Gui description - auto generate by Qt
    * ... // gui classes
  * CmakeLists.txt // Main Compilation file
  * autoBuild.sh // bash script to compile the software : `bash autoBuild.sh`

-----------------------------------------------------------------
## Prerequisites

- [x] Raspbian operating system installed

If you just buy a Raspberry Pi, please follow this part first [Installation of Raspbian](#installation-of-Raspbian)

First enable the SPI interface on your Pi with 
```console
sudo raspi-config
```
In `Interfacing options` 
- [x] SPI   
- [x] Serial

In order to have a correct building, you will need to install the following software

First open a terminal, and update your Raspberry Pi, then upgrade it
```console
sudo apt-get update
```
```console
sudo apt-get upgrade
```
Now we need to install cmake to compile the code
```console
sudo apt-get install cmake
```
Install git to be able to clone this git repository
```console
sudo apt-get install git
```
Then we need to install wiringpi to interact with the Raspberry Pi GPIO
```console
sudo apt-get install wiringpi
```
If you aren't working on the RPi, do this to be able to build on Linux :
```console
git clone https://github.com/WiringPi/WiringPi.git
```
```console
cd WiringPi && ./build
```
(You can delete the WiringPi folder after a correct building)  


<img src="doc/img/Qt.png" width=120 align="right" >

### Install necessary Qt5 packages on Raspberry Pi 4

Run the following command as sudo in order to get needed packages before installing Qt5
```console
sudo apt-get install build-essential
```
Now you can refer to this tutorial:
Tutorial source : https://vitux.com/compiling-your-first-qt-program-in-ubuntu/

Or simply enter the following commands:  
To compile some Qt software
```console
sudo apt-get install qt5-default

sudo apt-get install qtmultimedia5-dev
```

Optional
```console
sudo apt-get install qtcreator
```
```console
sudo apt-get install qt5-doc qtbase5-examples qtbase5-doc-html 
```
### Install & configure your Pi to run a GPS (optional)

First follow this tutorial to [configure GPSD on your Raspberry Pi](https://wiki.dragino.com/index.php?title=Getting_GPS_to_work_on_Raspberry_Pi_3_Model_B)

Once this part achieved, install the library to use gpsd with c++
```console
sudo apt-get install libgps-dev
```
So at every boot you have to run this command to be 
able to read GPS data via gpsd
```console
 sudo gpsd /dev/ttyS0 -F /var/run/gpsd.sock
```
You can also add this command in the file ```/etc/rc.local```
in order to let the Raspberry Pi run this command automatically on boot

-----------------------------------------------------------------
## Building software

First clone this GitHub repository in a folder using:
```console
git clone https://github.com/MorgesHAB/ERT2020GS.git
```
Move to the root folder of the project and run the bash to compile and build the executable files:
```console
sudo bash autoBuild.sh
```
-----------------------------------------------------------------
## Run software
After having run the autoBuild.sh script correctly (no errors), many executable should have been created in a "build" folder.  
The main program calls "ERT2020GS" and is the one run on the Ground Station with a graphical user interface
```console
./ERT2020GS
```
-----------------------------------------------------------------
## How to use the software
Create a `main.cpp` file in the src directory. Add the executable in the main CmakeLists.txt  
Add a Packet instance and your Transceiver instance 
and fill data on your packet.
The Packet::write(T t) method can take all the data that are 
of a size 8, 16 or 32 bits. You can override this method and adapt it to for 
example string or GPS data as it's already done. 
This is the same thing for the Packet::parse(T t) method.

This is an example for the transmitter part with Xbee as RF modem :
```cpp
#include "Packet.h"
#include "Xbee.h"

int main() {
    Xbee xbee;
    Packet packet;
    
    // fill your packet with some data
    packet.write(123);
    packet.write(float(34.56));
    packet.write('A');
    packet.write("Hello World");

    // Finally send your packet by RF
    xbee.send(packet);

    return 0;
}
```

If you want to develop some more complex data structure, you have to follow this template: in Telecom/DataStructures
```cpp
// Pattern class
#include <Data.h>

class MyData : public Data {         // must inherite of the super class Data
public:
    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    void updateTx(std::shared_ptr<Connector> connector) override;
    void updateRx(std::shared_ptr<Connector> connector) override;

private:
    float nbr;
    int x;
    char id;
    // ... Your class attributes
};
```
Then choose the data you want to transmit for example nbr & x  
So you just need to implement the write & parse function by adding 
```cpp
void MyData::write(Packet &packet) {
    packet.write(nbr);  // Use low level function to write bit to bit the RFpacket
    packet.write(x);
}
// Now in same same data order :
void MyData::parse(Packet &packet) {
    packet.parse(nbr);  // Use low level function to parse bit to bit the RFpacket
    packet.parse(x);
}
```
Finally use std::cout for the print() function & update() your data as you need.

Now you can create your own Datagram in the [constructor of DataHandler](Telecom/DataHandler/DataHandler.cpp)
After adding a new PacketID in [DataHandler.h](Telecom/DataHandler/DataHandler.h)
```cpp
enum PacketID {
    GPSID, ..., MY_DATA_TYPE,
};
```
-----------------------------------------------------------------
## Appendix
### Installation of Raspbian

Installation of Raspbian operating system on your Rapsberry Pi

Download the last version of Raspbian on (a file with .img extension): https://www.raspberrypi.org/downloads/raspbian/

Then write the img file on your SD card. You can use Win32DiskImager as software

Plug a keyboard & a mouse via USB port and a screen via HDMI port to your Raspberry Pi. Finally plug the 5V power.

-----------------------------------------------------------------

[<img src="doc/img/ERTbig.png" width=800>](https://epflrocketteam.ch/fr/)
