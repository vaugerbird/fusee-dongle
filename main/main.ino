#include <Arduino.h>

#include "fuseegelee.h"
#include "led_cc.h"

//Change hekate.h to appropriate payload name if necessary
#include "hekate.h"


void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
  if (usbInit() == -1) sleepDeep(-1);

  while (!searchTegraDevice())
  {
    ledBlink("blue", 1, 1000);
    //ledFade("blue", 10, 255);
  }

  setupTegraDevice();

  sendPayload(fuseeBin, FUSEE_BIN_SIZE);

  launchPayload();

  sleepDeep(1);
}

void loop()
{
}
