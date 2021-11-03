# HOPEFULLY THIS WARNING IS BIG ENOUGH!
**DO NOT use this repository as it stands!!! I still have much to work on, I just made it public in case there was anybody that wanted to see what I'm doing or help out**

# fusee-dongle
A single PCB fusee injector dongle based around the Atmel SAMD21. Based on my [sam fusee launcher](https://github.com/vaugerbird/sam-fusee-launcher) project, which is based on [sam fusee launcher](https://github.com/noemu/sam-fusee-launcher). This project uses the main.ino from [electronrancher's SAMD_Fusee_Multiloader](https://github.com/electronrancher/SAMD_Fusee_Multiloader) to allow multiple for payloads.

## Standard disclaimer
This project was created only for educational purposes, and does not enable any kind of copyright infringement. Seriously, don't use this project for anything illegal, I don't need or want the Ninty ninjas coming after me.

# Build and Install
### Create/Update the Payload
* Download your favorite payload(s) from its appropriate repository(s)
* Run the python script in the `tools` folder, using the appropriate converter for your payload, with this command, replacing the path with your own:
`python binConverterPayload.py "C:\pathToMyPayload\payloadName.bin"`, or just drag the .bin file on the script to automatically add the path
* In the same folder as the .bin file is located, a new .h file should appear. Make sure the new file is named `hekate.h`, `fusee.h`, and `package3.h`. Copy the new file to the `main` folder and choose to replace the old file

### Install Board to IDE
* Download and install arduino IDE http://www.arduino.cc/en/Main/Software
* In Arduino: go to "Preferences" and add to "Additional Board Manager URLs" following URL:  `custom board definition coming soon`
* Go to "Tools > Board > Board Manager" and select "Type: All" and
* Input "Fusee Dongle" in the search box
* Install "SAMD Fusee Dongle"
* Select the dongle with "Tools > Board > SAMD Fusee Dongle"

### IDE Setup
* Go to "Sketch > Include Library > Manage Libraries" and install USBHost and FlashStorage
* Connect the dongle to your computer and double click the reset button
* Go to "Tools > Port" and select your connected dongle. (If the name does not show up, use Device Manager to find the proper COM port)
* Download this repository, open main/main.ino with Arduino IDE

### Usage
* When the LED is blinking blue, plug the dongle in and the payload should inject automatically
* To change the payload, press the leftmost button once to advance the payload, and press the rightmost one to confirm the selected payload.
* If you want to inject again, press the middle button and the light should start blinking blue again

Status LED meanings:
* 1 blink blue -> searching for Switch, injecting payload 1
* 2 blinks blue -> searching for Switch, injecting payload 2
* 3 blinks blue -> searching for Switch, injecting payload 3
* Red -> no Switch found
* Solid green, then off (except the power LED) -> finished successfully

# Thanks to:
* [electronrancher](https://github.com/electronrancher)
* [noemu](https://github.com/noemu/sam-fusee-launcher)
* [atlas44](https://github.com/atlas44/sam-fusee-launcher)
* [CTCaer](https://github.com/CTCaer/hekate)
* [SciresM](https://github.com/SciresM)
* And the rest of the community!
