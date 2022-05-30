/********************************************************************************/
/*   Author  : Ahmed Farag  & Wajih                                             */
/*   Date    : 18/05/2022                                                       */
/*   Version : V02                                                              */
/********************************************************************************/

// Includes
#include "SBUS.h"
#include <Arduino.h>
#include <T_Motor.h>
#include <Curtis_Configuration.h>
#include <Brake.h>

uint16_t channels[16];
int Potentiometer_Readings = 0;
bool failSafe;
bool lostFrame;
char c;
int RC_Readings;
int RC_Switch;
int RC_Key_Switch_Reading;
int RC_Steering_Val;

// a SBUS object, which is on hardware
// serial port 1
SBUS x8r(Serial1);

void setup()
{
  // initialization functions
  Steering_Init();
  Curtis_Init();
  Brake_init();

  // begin the SBUS communication
  x8r.begin();

  // begin the serial communication
  Serial.begin(9600);
}

void loop()
{
  if (x8r.read(&channels[0], &failSafe, &lostFrame))
    ;

  RC_Readings = channels[RC_FW_CH_NUM];
  RC_Switch = channels[RC_ON_OFF_SW_CH_NUM];
  RC_Key_Switch_Reading = channels[RC_KEY_SW_CH_NUM];
  RC_Steering_Val = channels[STEERING_CH];

  Can3.events();
  Brake_Control(RC_Readings);

  RC_Control_Steps(RC_Steering_Val);
  Curtis_RC(RC_Readings, RC_Switch, RC_Key_Switch_Reading);
}
