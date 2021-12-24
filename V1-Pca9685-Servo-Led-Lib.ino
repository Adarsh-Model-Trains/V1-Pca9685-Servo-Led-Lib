/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshmodeltrains@gmail.com
*/

#include "Config.h"
#include "Pca9685BoardManager.h"

Pca9685BoardManager pcaBoardManager;

void setup() {
  Serial.begin(BROAD_RATE);
  pcaBoardManager.initPca9685Boards();
}

void loop() {
  int pinId = 0 ;

  pcaBoardManager.switchThrow(pinId);
  pcaBoardManager.switchClose(pinId);

  pcaBoardManager.switchOnSignal(pinId);
  pcaBoardManager.switchOffSignal(pinId);

  pcaBoardManager.switchOnLight(pinId);
  pcaBoardManager.switchOffLight(pinId);

  delay(DELAY_TIME);
}
