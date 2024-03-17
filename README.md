Team Östermalm
Members:
Abraham Jacobson
Adam Schedin
Linus Leitz
Mehdi Majid
Milad Flores

TinkerCad: https://www.tinkercad.com/things/bzNoRZl1CPc-copy-of-memory-game/editel?returnTo=%2Fdashboard%3Fcollection%3Ddesigns&sharecode=fQjF2-mh4wXeyKr9PfdipjIVoMxjlJ6kKznewWGSh-A


**Simon Says Game**

**Description -**
The Simon Says Game is a memory and reaction-based game implemented using an Arduino microcontroller. The game randomly generates a sequence of colored LEDs, which the player must then replicate by pressing corresponding buttons. As the game progresses, the sequence length increases, challenging the player's memory and reflexes.


**Installation -**
Connect the required components to the Arduino as per the provided schematic (tinkercad link).
Upload the game code ('MemoryGame.ino') to the Arduino using the Arduino IDE.
Turn on the Arduino and begin playing the game.


**Instructions -**
Upon starting the game, the Arduino will display the amount of lives you have twice followed by a random sequence of colored LEDs.
Memorize the sequence and replicate it by pressing the corresponding buttons in the correct order.
If you press the correct buttons in the correct order the game will make a victory-sound and progress to the next level, increasing the sequence length.
If you make a mistake, you lose a life up to 4 times and finally lose the game. To restart the game you shall restart the Arduino.


**Configuration -**
The game code can be modified to adjust parameters such as sequence length, button mappings, LED colors, and game difficulty.
Refer to the code comments for guidance on configuration options and how to make changes.


**Version History -**
Version 1.0: Initial release with basic game functionality
Version 1.1: Added sound effects and improved user interface
