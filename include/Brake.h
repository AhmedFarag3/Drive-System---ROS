#ifndef Brake_h
#define Brake_h

// to be changed
#define Min_LS_Pin 34
#define Max_LS_Pin 41

//Cytron
#define Brake_Dir 32
#define Brake_PWM 29

#define Throttle_Zero   1002
#define Throttle_Max    1722
#define Throttle_Min    283

void Brake_init();
void Brake_Control(int Throttle_Value);
void Brake_Control_Serial();




#endif