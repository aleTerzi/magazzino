# ABOS o.s.

__\*Note:__ _This software is an __alpha__ version, don't make any changes if you don't understand what are you doing._

__\*\*Note:__ _If you find __bug__ or you have good idea use the specific page [here](https://github.com/aleTerzi/magazzino/issues)._

## Configuration for a good installation:
1. Wath you need:
    - An Anet board V.1 or V.1.5
    - A power supply for the alimentation of your motherboard.
    - A usb cable with one end of type __USB B.__
    - The Arduino IDE, can you find it [here](https://www.arduino.cc/en/Main/Software?).
    _**Note:** use the offline version._
    
2. Before proceed we need to add a custom configuration, of the board, on the Arduino IDE:
    - Download the configuration [here](https://github.com/SkyNet3D/anet-board).
    - Unzip the file.
    - Find the directory "anet" in "anet-board-master/hardware", copy or cut the directory.
    - Now, go in your Arduino folder and in the subfolder named hardware, paste here the folder you had previously copied.
3. Open Arduino IDE:
    - Go on __Tools, Board__ and select __Anet V1.0__
    - Now plug the board in the USB cable. _**Note:** if the card was already connected unplug it and reconnect it to avoid problems._
    - Now, go on __Tools, Door__ and select the right COM for your board.
4. The final step:
    - Download this code.
    - Open it in the Arduino IDE.
    - Upload it with the (upload) button or use "Ctrl+U".
 
## YOU HAVE DONE !!