#ifndef Motor_h
#define Motor_h
#include "Arduino.h"
class Motor
{
	public:
	        Motor(int Speed1Pin, int Dir1Pin, int Speed2Pin, int Dir2Pin);//Pins to which motors are connected.
			void GoForward(int Speed);//Int Speed regulates speed.
			void GoBackward(int Speed);
			void TurnRight(int Speed);
			void TurnLeft(int Speed);
			void Stop();
	        void GoSquare(int TGoForward, int Speed);//Int TGoForward regulates time of going forward.
			void Turn90Left();
			void Turn90Right();
			void Turn180(); //This function didn't tested. May work unstable.
	private:
            int _Speed;
    		int _TGoForward;
    		int _Speed1Pin;
			int _Speed2Pin;
			int _Dir1Pin;
			int _Dir2Pin;
};
#endif

