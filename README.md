# DIY_Stop_Me_Game_Kit

# Description and details
"Stop Me" game is small and simple game running on ATtiny13 microcontroller. It consists of 7 LEDs, push button, small CR2032 battery and microcontroller. The game starts with LEDs lightning up in sequential order. LED in the middle (4th in row) is different color in comparison to the rest of the LEDs. Goal of the game is very simple, player must press the push button when the middle LED (only one in different color) is light up. If the correct LED is turned on when the push button is pressed, the player goes on next level where time delay between LED lighting up is shortened. If any other LED is turned on when the push button is pressed, the game restarts to the first level. The game is designed to have multiple levels (12 in total). 


This game is designed as a DIY soldering kit. This kit is ideal for kids and soldering beginners who can exercise their skills with this simple & easy game. While learning to solder, you will also create unique gadget which you can carry around. In addition, while playing this simple game, players can exercise their reflex skills.

# Repository content

This repo is divided into two parts: Eagle Files and Firmware. Eagle Files folder contains Cadsoft Eagle .sch and .brd files for "Stop Me" game PCB board. in addition there is schematic in .pdf created from .sch eagle file. In Firmware folder you can find C code for programming ATtiny13 microcontroller. The entire program code uses less than 1kB of Flash memory.

# Instructions on soldering

1. Insert the 8 pin IC socket into IC. Flip the board over, then solder into place.
2. Insert the switch and pushbutton into S1 and S2. Flip the board over and solder into place.
3. Insert 7 LEDs into LED1, LED2, LED2, LED3, LED4, LED5, LED6. Each LED has a short leg and a long leg. The long leg goes into the hole closest to the "+" sign on the board. NOTE: The green LED goes into LED4 place. Flip the board over, then solder into place.
4. Flip the board over. Put CR2032 battery holder into BAT place. Don't put battery in holder just yet. Flip the board over again and solder into place. The battery holder is only piece which is soldered on the back side of PCB.
5. Insert Attiny13 microcontroller into 8 pin IC socket. Make sure the dot in the corner of the chip is on bottom left corner.
6. Insert CR2032 battery into soldered battery holder.
7. Yay you're done! Flip the switch to the ON position and the game should start. Have Fun playing it. 

# Board versions
- v1.0 - initial version

# License info
This product is open-source. YAY!

e-radionica.com Team.
