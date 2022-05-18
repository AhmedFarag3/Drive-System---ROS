/********************************************************************************/
/*   Author  : Ahmed Farag                                                      */
/*   Date    : 18/05/2022                                                       */
/*   Version : V01                                                              */
/********************************************************************************/

// Includes
#include "SBUS.h"
#include <Arduino.h>
#include <Curtis_Configuration.h>

int Potentiometer_Readings = 0;


void setup()
{

  // initialization function
  Curtis_Init();

  // begin the serial communication
  Serial.begin(9600);
}

char c;
void loop()
{

  Curtis_RC(CHANNEL_NUMBER);

  if (Serial.available())
  {
    c = Serial.read();
    Serial.println(c);
  }
  if (c == 'F')
  {

    Potentiometer_Readings = Get_Potentiometer_Readings(POTENTIOMETER_PIN_NUMBER);
    Serial.print("Forward: ");
    

   Curtis_Break(HIGH_BREAK_PIN,HIGH_BREAK_OFF_STATE);
   Curtis_Forward(Potentiometer_Readings, THROTTLE_FORWARD_PIN, THROTTLE_MIN_READINGS, THROTTLE_MAX_READINGS, THROTTLE_MIN_PWM, THROTTLE_MAX_PWM);
  }
  if (c == 'R')
  {
    Potentiometer_Readings = Get_Potentiometer_Readings(POTENTIOMETER_PIN_NUMBER);
    Serial.print("Reverse: ");
    

    Curtis_Break(HIGH_BREAK_PIN, HIGH_BREAK_OFF_STATE);
    // In this function call we will pass the arguments of the function as same as the forward since we are not using slider throttle with negative values
    Curtis_Reverse(Potentiometer_Readings, THROTTLE_FORWARD_PIN, THROTTLE_MIN_READINGS, THROTTLE_MAX_READINGS, THROTTLE_MIN_PWM, THROTTLE_MAX_PWM, REVERSE_DIRECTION_SWITCH);
  }
  if (c == 'B')
  {
    Serial.println("Break");

    Curtis_Break(HIGH_BREAK_PIN, HIGH_BREAK_ON_STATE);
  }
}

