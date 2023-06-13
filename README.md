# FinalGame
A Game somewhat similar to Simon Says AND Bop It
The game that I will attempt to recurtate is Simon Says/Bop It. 
In which the game will start playing a good start sound then flashing either a Red, Green, or Blue color on the LEDS. 
Depending on the color you will need to do something withing a 10 Second time frame otherwise it will auto fail you. As your continue playing the time frame will decrease making it a increase in difficulty each level.
Red = Push right button;
Green = Flip the switch;
Blue = Push left button;
If done right then it will play a good sound then choose another color to do. While getting the correct score the sound will reach a higher pitch as your score goes up. The score will print it self to the serial monitor ever correct awnser.
If done wrong it will play sad sound. This will reset your score back to 0.
Create a user inputs/outputs definition sheet:
This sheet details the user input controls into the game system. Define the sensors used, their function, their raw ranges, what they will be assigned to control, any threshold or map() functions applied.

Switch;
attachInterrupt(digitalPinToInterrupt(switchPin), switchISR, CHANGE);
Will activate the SwitchFlag after going into the ISR which will signal that the user used the switch. Which they should do if its green.

Light;
CircuitPlayground.lightSensor();
Return a integer light value that rages from 1 to 1000.

Left Button;
attachInterrupt(digitalPinToInterrupt(buttonPinA), buttonISR, FALLING);
Will activate the ButtonAFlag after going into the ISR which will signal that the user used the Left button. Which they should do if its Blue.

Right Button;
attachInterrupt(digitalPinToInterrupt(buttonPinB), buttonISR, FALLING);
Will activate the ButtonBFlag after going into the ISR which will signal that the user used the Right button. Which they should do if its Red.

Light sensor will be used to adjust the brightness of the game incase of playing in a differently lit room.
CircuitPlayground.setBrightness
(map(light,50,1030,50,255));

Sounds outputs will be played in a minor key if failed and in major key if they succeed to help diffritriate what is happening.
CircuitPlayground.playTone









