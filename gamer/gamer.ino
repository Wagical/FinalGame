#include <AsyncDelay.h>
#include <Adafruit_CircuitPlayground.h>
AsyncDelay delay_7s;
float midi[127];
int A_four = 440; // a is 440 hz...
int switchCase = 0;
int switchPin = 7;
int buttonPinA = 4;
int buttonPinB = 5;
int rando = 0;
int score = 0;
int light;
bool buttonFlagA = 0;
bool buttonFlagB = 0;
bool switchFlag = 0;
bool switchState = 0;
bool game = 0;

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  pinMode(switchPin, INPUT_PULLUP); //activating pin and the modes
  pinMode(buttonPinA, INPUT_PULLDOWN);
  pinMode(buttonPinB, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(switchPin), switchISR, CHANGE);//assigning the interrupts to certain pins
  attachInterrupt(digitalPinToInterrupt(buttonPinA), buttonAISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPinB), buttonBISR, FALLING);
  generateMIDI();
  randomSeed(analogRead(0)); // Seed the random, randomly
}

void loop() {
  light = CircuitPlayground.lightSensor();
  CircuitPlayground.setBrightness(map(light,0,1030,1,255));
      Serial.print(" Light Sensor: ");
      Serial.println(light);
    if(switchFlag){//reset the flag and switch the state of the switch
    delay(5);
    switchFlag = 0;
    if (rando == 2){
      CircuitPlayground.clearPixels();
      CircuitPlayground.playTone(midi[60+score], 100);
      CircuitPlayground.playTone(midi[62+score], 100);
      CircuitPlayground.playTone(midi[64+score], 100);
      score++;
      game = 0;
      Serial.print(" Score: ");
      Serial.println(score);
    }else{
      CircuitPlayground.clearPixels();
      CircuitPlayground.playTone(midi[63], 100);
      CircuitPlayground.playTone(midi[62], 100);
      CircuitPlayground.playTone(midi[60], 100);
      score=0;
      game = 0;
      Serial.println(" Wrong ");
      Serial.print(" Score: ");
      Serial.println(score);
    }
  }
  if(buttonFlagA){//reset the flag and restart the count
    delay(5);
    buttonFlagA = 0;
      if (rando == 0){
      CircuitPlayground.clearPixels();
      CircuitPlayground.playTone(midi[60+score], 100);
      CircuitPlayground.playTone(midi[62+score], 100);
      CircuitPlayground.playTone(midi[64+score], 100);
      score++;
      game = 0;
      Serial.print(" Score: ");
      Serial.println(score);
    }else{
      CircuitPlayground.clearPixels();
      CircuitPlayground.playTone(midi[63], 100);
      CircuitPlayground.playTone(midi[62], 100);
      CircuitPlayground.playTone(midi[60], 100);
      score=0;
      game = 0;
      Serial.println(" Wrong ");
      Serial.print(" Score: ");
      Serial.println(score);
    }
    }
    if(buttonFlagB){//reset the flag and restart the count
    delay(5);
    buttonFlagB = 0;
      if (rando == 1){
      CircuitPlayground.clearPixels();
      CircuitPlayground.playTone(midi[60+score], 100);
      CircuitPlayground.playTone(midi[62+score], 100);
      CircuitPlayground.playTone(midi[64+score], 100);
      score++;
      game = 0;
      Serial.print(" Score: ");
      Serial.println(score);
    }else{
      CircuitPlayground.clearPixels();
      CircuitPlayground.playTone(midi[63], 100);
      CircuitPlayground.playTone(midi[62], 100);
      CircuitPlayground.playTone(midi[60], 100);
      score=0;
      game = 0;
      Serial.println(" Wrong ");
      Serial.print(" Score: ");
      Serial.println(score);
    }
    }
    if (delay_7s.isExpired()){
      CircuitPlayground.clearPixels();
      CircuitPlayground.playTone(midi[63], 100);
      CircuitPlayground.playTone(midi[62], 100);
      CircuitPlayground.playTone(midi[60], 100);
      score=0;
      game = 0;
      Serial.println(" Out Of Time ");
      Serial.print (" Score: ");
      Serial.println(score);
    }
    if (!game){
rando = random(3);
switch(rando){
  case 0:
      for(int i = 0; i<5; i++){
      CircuitPlayground.setPixelColor(i, 255, 0, 0);
      }
      game = 1;
      delay_7s.start(7000, AsyncDelay::MILLIS);//expires ever 7000 mil seconds
    break;
  case 1:
      for(int i = 5; i<10; i++){
      CircuitPlayground.setPixelColor(i, 255, 0, 0);
      }
      game = 1;
      delay_7s.start(7000, AsyncDelay::MILLIS);//expires ever 7000 mil seconds
    break;
  case 2:
    for(int i = 0; i<10; i++){
      CircuitPlayground.setPixelColor(i, 255, 0, 0);
      }
      game = 1;
      delay_7s.start(7000, AsyncDelay::MILLIS);//expires ever 7000 mil seconds
    break;
  default:
    break;
}
}
}
    void buttonAISR(void){
  buttonFlagA = 1;
}
    void buttonBISR(void){
  buttonFlagB = 1;
}
    void switchISR(void){//interrupt switch flag
  switchFlag = 1;
}
void generateMIDI() //genretes values
{
  for (int x = 0; x < 127; ++x)
  {
    midi[x] = (A_four / 32.0) * pow(2.0, ((x - 9.0) / 12.0));
    Serial.println(midi[x]);
  }
}