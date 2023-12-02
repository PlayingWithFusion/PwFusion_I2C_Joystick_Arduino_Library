/***************************************************************************
* File Name: PwFusion_Joystick_example.ino
* Processor/Platform: R3aktor (tested)
* Development Environment: Arduino 2.2.1
*
* Designed for use with with Playing With Fusion I2C Joystick
* interface board: IFB-40002
*
* Copyright © 2015-18 Playing With Fusion, Inc.
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
* Author		  Date	    Comments
* N. Johnson  2023Aug10 Original Version
*
* Playing With Fusion, Inc. invests time and resources developing open-source
* code. Please support Playing With Fusion and continued open-source
* development by buying products from Playing With Fusion!
* **************************************************************************
* ADDITIONAL NOTES:
* This file contains functions to initialize and run a Playing With Fusion R3aktor in
* order to communicate with the I2C Joystick board. Funcionality is as described below:
*	- Configure R3aktor to receive information from the I2C Joystick board
*	- Broadcast results to COM port
*  Circuit:
*    R3aktor     -->  I2C Joystick
*    Qwiic pins  -->  Qwiic pins
***************************************************************************/

// Include the PwFusion I2C Joystick library
#include <PwFusion_I2C_Joystick_Arduino_Library.h>

// Define address for the i2c joystick
uint8_t ADR = 0x05;
//uint8_t ADR = 0x06;
//uint8_t ADR = 0x07;
//uint8_t ADR = 0x08;


// Create a new Joystick object
Joystick joy;

void setup() {
  Serial.begin(9600);
  // Start the Joystick object and pass in the i2c address
  joy.begin(ADR);
}

void loop() {
  // Print out the values of the Joystick to the Serial Monitor
  Serial.print("Joystick X:  ");
  Serial.print(joy.getVRX());
  Serial.print("  Joystick Y: ");
  Serial.print(joy.getVRY());
  Serial.print("  Joystick Switch: ");
  Serial.println(joy.getSW());
}