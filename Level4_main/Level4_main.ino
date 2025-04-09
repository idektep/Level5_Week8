//Arduino Uno
#include <Wire.h>
#include <avr/wdt.h>

uint32_t Data = 0;

/*-----------------------------------------------*/
void setup() {
  Serial.begin(9600); //set the baud rate for serial communication
  NeopixelSetup();
  ServoSetup();
  ServoHome();
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.println("Level 4");
  LcdSetup();
}
/*-----------------------------------------------*/

void loop() {
  if (Serial.available() > 0) {
    int newData = Serial.parseInt();
    if (newData != 0) {
      Data = newData;
    }
  }
  switch (Data) {
    case 1:
      //Add function 
      break;

    case 2:
      //Add function 
      break;

    case 3:
      //Add function 
      break;

    case 4:
      //Add function 
      break;
    
    case 5:
      //Add function 
      break;

    case 6:
      //Add function 
      break;

    case 7:
      //Add function 
      break;
    
    case 8://Stop
      DisplayLcd(6, "STOP", 0, "");
      ServoStop();
      NeopixelClose();
      break;

    case 9://Reset
      DisplayLcd(5, "RESET", 0, "");
      resetFunc();
      break;         

    case 11: 
      //Add function 
      break;

    case 12: 
      //Add function 
      break;
  }
}

void resetFunc() { // Restart
  wdt_disable();
  wdt_enable(WDTO_15MS);
  while (1) {}
}
