// Joystick.cpp

#include "Joystick.h"
#include "Arduino.h"
#include "DataTransfer.h"



Joystick::Joystick(uint8_t adr) {
  _adr = adr;

  transfer = new DataTransfer(_adr, _numData);

}

int Joystick::getVRX() {
  return transfer->getData(reg_VRX);
}

int Joystick::getVRY() {
  return transfer->getData(reg_VRY);
}

int Joystick::getSW() {
  return transfer->getData(reg_SW);
}