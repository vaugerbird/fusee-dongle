#include <Arduino.h>

void setLedColor(const char color[], int bright) {
  if (color == "red") {
    analogWrite(A1, bright); //R
    analogWrite(A2, 0); //G
    analogWrite(A3, 0); //B
  } else if (color == "green") {
    analogWrite(A1, 0); //R
    analogWrite(A2, bright); //G
    analogWrite(A3, 0); //B
  } else if (color == "black") {
    analogWrite(A1, 0); //R
    analogWrite(A2, 0); //G
    analogWrite(A3, 0); //B
  } else if (color == "blue") {
    analogWrite(A1, 0); //R
    analogWrite(A2, 0); //G
    analogWrite(A3, bright); //B
  } else {
    analogWrite(A1, bright); //R
    analogWrite(A2, bright); //G
    analogWrite(A3, bright); //B
  }
}

void ledBlink(const char color[], int count, int duration) {
  for (int counter = 0; counter < count; counter++) {
    for (int onOff = 1; onOff >= 0; onOff--) {
      if (onOff == 1) {
        setLedColor(color, 100);
      } else {
        setLedColor("black", 0);
      }
      delay(duration / (2.0 * count));
    }
  }
}

void sleepDeep(int errorCode) {
  // Turn off all LEDs and go to sleep. To launch another payload, press the reset button on the device.
  //delay(100);
  if (errorCode == 1) {
    setLedColor("green", 100); //led to green
    delay(3000);
    setLedColor("black", 0); //led off
  } else {
    setLedColor("red", 100); //led to red
  }
  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk; /* Enable deepsleep */
  __DSB(); /* Ensure effect of last store takes effect */
  __WFI(); /* Enter sleep mode */
}
