// Joystick.h

#ifndef Joystick_h
#define Joystick_h

#include "Arduino.h"
#include "DataTransfer.h"

class Joystick {

  private:
    uint8_t _adr;
    DataTransfer* transfer;

    uint8_t reg_VRX = 0x00;
    uint8_t reg_VRY = 0x01;
    uint8_t reg_SW = 0x02;
    int _numData = 3;

  public:
    Joystick(uint8_t adr);
    int getVRX();
    int getVRY();
    int getSW();

};

#endif