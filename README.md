<img src="img/bellalui.svg" width=180 align="right" >

# EPFL Rocket Team - <em>Bella Lui Project 2020</em>

### Goal 
Spaceport America Cup competition - Launch a Rocket to the exact altitude of 10'000 feets

### Description
Code of the <b>Ground Segment system</b> which will run on a Raspberry Pi 4.

-----------------------------------------------------------------
## Installation of the required software

First you need to update & upgrade your Raspberry Pi
```
sudo apt-get update
```
```
sudo apt-get upgrade
```
Now we need to install cmake to compile the code
```
sudo apt install cmake
```
Then we need to install wiringpi to interact with the Raspberry Pi GPIO
```
sudo apt install wiringpi
```
Finally install git to be able to clone this git repository
```
sudo apt-get install git
```

-----------------------------------------------------------------
<img src="img/Qt.png" width=120 align="right" >

## Install necessary Qt5 packages on Raspberry Pi 4

Run the following command as sudo in order to get needed packages before installing Qt5
```
sudo apt-get install build-essential
```
Now you can refer to this tutorial:
Tutorial source : https://vitux.com/compiling-your-first-qt-program-in-ubuntu/

Or simply enter the following commands:

```
sudo apt-get install qtcreator
```
```
sudo apt install qt5-default
```
```
sudo apt-get install qt5-doc qtbase5-examples qtbase5-doc-html
```

-----------------------------------------------------------------
## Building software

First clone this GitHub repository in a folder using:
```
git clone https://github.com/MorgesHAB/ERT2020GS.git
```
Move to the root folder of the project and run the bash to build the executable file:
```
sudo bash run.sh
```

-----------------------------------------------------------------
## Installation of Raspbian
Installation of Raspbian operating system on your Rapsberry Pi

Download the last version of Raspbian on (a file with .img extension): https://www.raspberrypi.org/downloads/raspbian/

Then write the img file on your SD card. You can use Win32DiskImager as software

-----------------------------------------------------------------

<img src="img/ERT.png" width=800>
