[<img src="doc/img/bellalui.png" width=180 align="right" >](https://epflrocketteam.ch/fr/)

# EPFL Rocket Team - <em>Bella Lui Project 2020</em>

### Goal 
Spaceport America Cup competition - Launch a Rocket to the exact altitude of 10'000 feets

### Description
Code of the <b>Ground Segment system</b> which will run on a Raspberry Pi 4 :rocket:

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
sudo apt install cmake
```
Then we need to install wiringpi to interact with the Raspberry Pi GPIO
```console
sudo apt install wiringpi
```
Finally install git to be able to clone this git repository
```console
sudo apt-get install git
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



<img src="doc/img/Qt.png" width=120 align="right" >

### Install necessary Qt5 packages on Raspberry Pi 4

Run the following command as sudo in order to get needed packages before installing Qt5
```console
sudo apt-get install build-essential
```
Now you can refer to this tutorial:
Tutorial source : https://vitux.com/compiling-your-first-qt-program-in-ubuntu/

Or simply enter the following commands:

```console
sudo apt-get install qtcreator
```
```console
sudo apt install qt5-default
```
```console
sudo apt-get install qt5-doc qtbase5-examples qtbase5-doc-html
```

-----------------------------------------------------------------
## Building software

First clone this GitHub repository in a folder using:
```console
git clone https://github.com/MorgesHAB/ERT2020GS.git
```
Move to the root folder of the project and run the bash to build the executable file:
```console
sudo bash autoBuild.sh
```

-----------------------------------------------------------------
## How to use the software
Create a `main.cpp` file. Add a Packet instance and your Transceiver instance 
and fill data on your packet.
The Packet::write(T t) method can take all the data that are 
of a size 8, 16 or 32 bits. You can override this method and adapt it to for 
example string or GPS data as it's already done. 
This is the same thing for the Packet::parse(T t) method.

This is an example for the transmitter part with LoRa as RF modem :
```cpp
#include "Packet.h"
#include "LoRa.h"

int main() {
    LoRa loRa;
    Packet packet;
    
    // fill your packet with some data
    packet.write(123);
    packet.write(float(34.56));
    packet.write('A');
    packet.write("Hello World");

    // Finally send your packet by RF
    loRa.send(packet);

    return 0;
}
```

If you want to develop some more complex data 
structure, see GPS class as an example.

-----------------------------------------------------------------
## Repository organization

 * doc
    * ...
    * html
        * ...
        * index.html // open this file on a web browser 
                after cloning the project, to read the doxygen documentation 
        * ...
  * lib
    * ... // the RadioHead library required for the LoRa class
  * src
    * ... // all the modules
    * GSE.cpp // main() for the transmitter
    * GST.cpp // main() for the Receiver


-----------------------------------------------------------------
## Appendix
### Installation of Raspbian

Installation of Raspbian operating system on your Rapsberry Pi

Download the last version of Raspbian on (a file with .img extension): https://www.raspberrypi.org/downloads/raspbian/

Then write the img file on your SD card. You can use Win32DiskImager as software

Plug a keyboard & a mouse via USB port and a screen via HDMI port to your Raspberry Pi. Finally plug the 5V power.

-----------------------------------------------------------------

[<img src="doc/img/ERTbig.png" width=800>](https://epflrocketteam.ch/fr/)
