# ABOS o.s.

__\*Note:__ _This software is an __alpha__ version, we do not recommend using this software, __if you do so at your own risk.___

__\*\*Note:__ _This software was created for school purposes and is not recommended for commercial use._

__\*\*\*Note:__ _If you find __bug__ or you have good idea use the specific page <a href="https://github.com/aleTerzi/magazzino/issues" target="_blank">here</a>._

## Configuration for a good installation:
1. Wath you need:
    - An Anet board V.1 or V.1.5
    - A power supply for the alimentation of your motherboard.
    - A usb cable with one end of type __USB B.__
    - The Arduino IDE, can you find it <a href="https://www.arduino.cc/en/Main/Software?" target="_blank">here</a>.
    _**Note:** use the offline version._
    
2. Before proceed we need to add a custom configuration, of the board, on the Arduino IDE:
    - Go to __utilities__, copy the directory __anet__ in your arduino installation (see point 1) and paste it in __arduino\hardware__.
    - Go to __utilities__, copy the directory __StandardCplusplus__ in your arduino installation (see point 1) and paste it in __arduino\libraries__.
3. Open Arduino IDE:
    - Go on __Tools, Board__ and select __Anet V1.0__
    - Now plug the board in the USB cable. _**Note:** if the card was already connected unplug it and reconnect it to avoid problems._
    - Now, go on __Tools, Door__ and select the right COM for your board.
4. The final step:
    - Download this code.
    - Open it in the Arduino IDE.
    - Upload it with the (upload) button or use "Ctrl+U".
 
#### YOU HAVE DONE !!