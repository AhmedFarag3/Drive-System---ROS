#ifndef Brake_h
#define Brake_h

// to be changed
#define Min_LS_Pin 34
#define Max_LS_Pin 41

//Cytron
#define Brake_Dir 32
#define Brake_PWM 13

#define Throttle_Zero   0
#define Throttle_Max    100
#define Throttle_Min    283

#define RC_E_
void Brake_init();
void Brake_Control(int Throttle_Value);
void Brake_Control_Serial();




#endif