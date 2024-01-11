/***************************************************************************
* File Name: PwFusion_Joystick_LED_example.ino
* Processor/Platform: R3aktor (tested)
* Development Environment: Arduino 2.2.1
*
* Designed for use with with Playing With Fusion I2C Joystick
* interface board: IFB-40002
*
* MIT License
* SOFTWARE LICENSE AGREEMENT: This code is released under the MIT License.
* Copyright (c) 2024 Playing With Fusion, Inc
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
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
* - Activate and Deactivate select LEDs based on the position of the Joystick
*	- Broadcast results to COM port
*  Circuit: (see Schematic.png)
*    R3aktor     -->  I2C Joystick
*    Qwiic pins  -->  Qwiic pins
*    R3aktor     -->  LEDS
*    DIO 05      -->  LED 1 in series with 220 ohm resistor
*    DIO 06      -->  LED 2 in series with 220 ohm resistor
*    DIO 09      -->  LED 3 in series with 220 ohm resistor
*    DIO 10      -->  LED 4 in series with 220 ohm resistor
*    DIO 11      -->  LED 5 in series with 220 ohm resistor
***************************************************************************/

// Include the PwFusion I2C Joystick library
#include <PwFusion_I2C_Joystick_Arduino_Library.h>

// Define address for the i2c joystick
uint8_t ADR = 0x05;
//uint8_t ADR = 0x06;
//uint8_t ADR = 0x07;
//uint8_t ADR = 0x08;

// Define pins for the 5 leds
int l1 = 5;
int l2 = 6;
int l3 = 9;
int l4 = 10;
int l5 = 11;



// Create a new Joystick object
Joystick joy;

void setup() {
  Serial.begin(9600);

  // Start the Joystick object and pass in the i2c address
  joy.begin(ADR);

  // Define the pin mode for each LED
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
}

void loop() {

  // Print out the values of the Joystick to the Serial Monitor
  Serial.print("Joystick X:  ");
  Serial.print(joy.getVRX());
  Serial.print("  Joystick Y: ");
  Serial.print(joy.getVRY());
  Serial.print("  Joystick Switch: ");
  Serial.println(joy.getSW());

  int vrx = joy.getVRX();
  int vry = joy.getVRY();
  int sw = joy.getSW();

  // Light up the LEDs based on the position of the Joystick
  if(vrx > 200)  digitalWrite(l1, HIGH);   else digitalWrite(l1, LOW);
  if(vrx < 55)   digitalWrite(l4, HIGH);   else digitalWrite(l4, LOW);
  if(vry < 55)   digitalWrite(l5, HIGH);   else digitalWrite(l5, LOW);
  if(vry > 200)  digitalWrite(l3, HIGH);   else digitalWrite(l3, LOW);
  if(sw == 1)    digitalWrite(l2, HIGH);   else digitalWrite(l2, LOW);
}