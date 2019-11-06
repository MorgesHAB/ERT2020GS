<img src="doc/img/bellalui.png" width=180 align="right" >

# EPFL Rocket Team - <em>Bella Lui Project 2020</em>

### Goal 
Spaceport America Cup competition - Launch a Rocket to the exact altitude of 10'000 feets

### Description
Code of the <b>Ground Segment system</b> which will run on a Raspberry Pi 4.

-----------------------------------------------------------------
## Prerequisites

- [x] Raspbian operating system installed

If you just buy a Raspberry Pi, please follow this part first [Installation of Raspbian](#installation-of-Raspbian)

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
sudo bash run.sh
```

-----------------------------------------------------------------
## Installation of Raspbian

Installation of Raspbian operating system on your Rapsberry Pi

Download the last version of Raspbian on (a file with .img extension): https://www.raspberrypi.org/downloads/raspbian/

Then write the img file on your SD card. You can use Win32DiskImager as software

Plug a keyboard & a mouse via USB port and a screen via HDMI port to your Raspberry Pi. Finally plug the 5V power.

-----------------------------------------------------------------

<img src="doc/img/ERTbig.png" width=800>
