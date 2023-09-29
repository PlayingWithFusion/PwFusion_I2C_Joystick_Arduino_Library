/***************************************************************************
* File Name: PwFusion_I2C_Joystick_Arduino_Library.cpp
* Processor/Platform: PwFusion R3aktor M0 (tested)
* Development Environment: Arduino 2.1.1
*
* Designed to simplify the integration of the PwFusion I2C Joystick board
* Device (IFB-40002)
*   ---> <Insert Link>
*
* Copyright � 2023 Playing With Fusion, Inc.
* SOFTWARE LICENSE AGREEMENT: This code is released under the MIT License.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
* **************************************************************************
* REVISION HISTORY:
* Author		    Date		    Comments
* N. Johnson    2023Aug29   Original version
*
* Playing With Fusion, Inc. invests time and resources developing open-source
* code. Please support Playing With Fusion and continued open-source
* development by buying products from Playing With Fusion!
***************************************************************************/
#include "PwFusion_I2C_Joystick_Arduino_Library.h"
#include "Arduino.h"
#include <PwFusion_Data_Transfer.h>



Joystick::Joystick() {}

int Joystick::getVRX() {
  return transfer->getData(reg_VRX);
}

int Joystick::getVRY() {
  return transfer->getData(reg_VRY);
}

int Joystick::getSW() {
  return transfer->getData(reg_SW);
}

void Joystick::begin(uint8_t adr) {
    _adr = adr;
    transfer = new DataTransfer();
    transfer->begin(_adr, _numData);
}