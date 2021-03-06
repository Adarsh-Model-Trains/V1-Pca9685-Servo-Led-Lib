# PCA9685 SERVO TURNOUT & SIGNAAL LIGHT LIBRARY VERSION 1

---

### [LIB-DOWNLOAD-LINK](https://github.com/Adarsh-Model-Trains/V1-Pca9685-Servo-Led-Lib/raw/main/lib/V1-Pca9685-Servo-Led-Lib.zip)

### Create a file Config.h in the project sample is below 

* Config.h 
```
#ifndef Config_h
#define Config_h
#include "Arduino.h"

/************************************************************************************************/
const bool signalLedTypeAnode = true;
const bool slowMove = true;
#define BROAD_RATE 115200
#define NO_OF_TURNOUT_BOARDS 2
#define NO_OF_LIGHT_BOARDS 3
#define NO_OF_TOTAL_BOARDS 5

/*
int turnoutRange[][TOTAL_BOARD_PIN][RANGE_TYPE] = {
  {  // BOARD 0 
    {OPEN_RANGE, CLOSE_RANGE},  // PIN 0
    {OPEN_RANGE, CLOSE_RANGE}   // PIN 1
    ........
   },
   {  // BOARD 1 
    {OPEN_RANGE, CLOSE_RANGE},  // PIN 0
    {OPEN_RANGE, CLOSE_RANGE}   // PIN 1
    ........
   },
   
   ........
   ........
   
   {  // BOARD N 
    {OPEN_RANGE, CLOSE_RANGE},  // PIN 0
    {OPEN_RANGE, CLOSE_RANGE}   // PIN 1
    ........
   }
};
*/
#define RANGE_TYPE 2
#define TOTAL_BOARD_PIN 16
const int turnoutRange[][TOTAL_BOARD_PIN][RANGE_TYPE] = {
  {
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000}
  },
  {
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000},
    {1000, 2000}
  }
};

#endif
```


### Configuration of the number of boards based on the turnout light and 2 and 3 led signals 
> msut match in node configuraiton in transformer 
```
#define NO_OF_TURNOUT_BOARDS 3
#define NO_OF_LIGHT_BOARDS 3
#define NO_OF_TOTAL_BOARDS 6
```

### other configuration 
``` 
#define BROAD_RATE 115200
#define DELAY_TIME 200
const bool slowMove = true;
```

### Configuration of the open and close range for the servo moter 
> use the callibration application "servo-turnout-calibration" for the finding the open and close range present in example 
> for the each servo and feed in the array board wise for each pin 

```
int turnoutRange[][TOTAL_BOARD_PIN][RANGE_TYPE] = {
  {  // BOARD 0 
    {OPEN_RANGE, CLOSE_RANGE},  // PIN 0
    {OPEN_RANGE, CLOSE_RANGE}   // PIN 1
    ........
    ........
    {OPEN_RANGE, CLOSE_RANGE}   // PIN N
   },
   {  // BOARD 1 
    {OPEN_RANGE, CLOSE_RANGE},  // PIN 0
    {OPEN_RANGE, CLOSE_RANGE}   // PIN 1
   ........
    ........
    {OPEN_RANGE, CLOSE_RANGE}   // PIN N
   },
   
   ........
   ........
   ........
   ........
   
   {  // BOARD N 
    {OPEN_RANGE, CLOSE_RANGE},  // PIN 0
    {OPEN_RANGE, CLOSE_RANGE}   // PIN 1
    ........
    ........
    {OPEN_RANGE, CLOSE_RANGE}   // PIN N
   }
};
```

### import in the main file or sttart file 
```
#include "Config.h"
#include "Pca9685BoardManager.h"
```

### Object creation 
```
Pca9685BoardManager pcaBoardManager;
```

### in setup method init the lib 
```
void setup() {
  Serial.begin(BROAD_RATE);
  pcaBoardManager.initPca9685Boards();
}
```

### in loop method call the functions 
```
void loop() {
   pcaBoardManager.switchThrow(pinId);      // turnout throw and close 
   pcaBoardManager.switchClose(pinId);

   pcaBoardManager.switchOnSignal(pinId);    //for signal light on and off 
   pcaBoardManager.switchOffSignal(pinId);

   pcaBoardManager.switchOnLight(pinId);     //for layout light on and off 
   pcaBoardManager.switchOffLight(pinId);

   delay(DELAY_TIME);
  } 

```