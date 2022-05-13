/********************************************************************************/
/*   Author  : Ahmed Farag                                                      */
/*   Date    : 13/05/2022                                                       */
/*   Version : V01                                                              */
/********************************************************************************/

#ifndef CURTIS_CONFIGURATION_H
#define CURTIS_CONFIGURATION_H


// Inputs pins 
#define POTENTIOMETER_PIN_NUMBER 22


// Transistors Pin number 


// Forward motor driver parameters

#define THROTTLE_FORWARD_PIN   2
#define THROTTLE_MIN_PWM       0
#define THROTTLE_MAX_PWM       200
#define THROTTLE_MIN_READINGS  0
#define THROTTLE_MAX_READINGS  900


// REVERSE motor driver parameters

#define THROTTLE_REVERSE_PIN             2
#define REVERSE_DIRECTION_SWITCH         16 
#define THROTTLE_MIN_PWM_REVERSE        -200
#define THROTTLE_MAX_PWM_REVERSE         0
#define THROTTLE_MIN_READINGS_REVERSE   -600
#define THROTTLE_MAX_READINGS_REVERSE    0

// HIGH Break PINS
#define HIGH_BREAK_PIN           37
#define HIGH_BREAK_OFF_STATE     LOW
#define HIGH_BREAK_ON_STATE      HIGH

// Spedometer PINS
#define SPEDOMETER_PIN                 
#define SPEDOMETER_PULSE_MODE_HIGH    HIGH 



// Functions Prototype

void Curtis_Init();
int  Get_Potentiometer_Readings (int Potentiometer_Pin_Num) ;
void Curtis_Forward (int Throttle_Pin , int Potentiometer_Readings , int Throttle_Min_Readings, int Throttle_Max_Readings, int Throttle_Min_PWM ,int Throttle_Max_PWM );
void Curtis_Reverse(int Throttle_Pin , int Potentiometer_Readings , int Throttle_Min_Readings, int Throttle_Max_Readings, int Throttle_Min_PWM ,int Throttle_Max_PWM, int Reverse_Switch_Pin);
void Curtis_Break(int Break_Pin , int State);
int  Curtis_Speedometer(int Sedometer_Pin , int Mode);




#endif