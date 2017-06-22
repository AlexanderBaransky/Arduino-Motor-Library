/*
Motor.ccp библиотека для управления робото-платформой
С двумя коллекторными моторами.
Версия 1.0 Beta
Тестировалась на Amperka Motor Shield.
Создана Александром Баранским 22 Июня 2017 года.

Motor.ccp a library for controlling robot platform
With two manifold motors.
Version 1.0 Beta
Tested on Amperka Motor Shield.
Created by Alexander Baransky 22 June 2017 year.
*/
#include "Arduino.h"
#include "Motor.h"
Motor::Motor(int Speed1Pin, int Dir1Pin, int Speed2Pin, int Dir2Pin)//Пины к которым подключены моторы. Pins to which motors are connected.
{
	_Speed1Pin = Speed1Pin;
	_Dir1Pin = Dir1Pin;
	_Speed2Pin = Speed2Pin;
	_Dir2Pin = Dir2Pin;
	pinMode(_Speed1Pin, OUTPUT);//Настраивает пины в режим выхода. Sets pins to output mode.
	pinMode(_Dir1Pin, OUTPUT);
	pinMode(_Speed2Pin, OUTPUT);
	pinMode(_Dir2Pin, OUTPUT);
}

void Motor::GoForward(int Speed)//Int Speed регулирует скорость. Int Speed regulates speed.
{
	_Speed = Speed;
	digitalWrite(_Dir1Pin, HIGH);//Установливает направление вперед. Sets direction to forward.
	digitalWrite(_Dir2Pin, HIGH);
	analogWrite(_Speed1Pin, _Speed);//Запитывает моторы. Powers motors.
	analogWrite(_Speed2Pin, _Speed);
}

void Motor::GoBackward(int Speed)
{
	_Speed = Speed;
	digitalWrite(_Dir1Pin, LOW);//Установливает направление назад. Sets direction to backward.
	digitalWrite(_Dir2Pin, LOW);
	analogWrite(_Speed1Pin, _Speed);
	analogWrite(_Speed2Pin, _Speed);
}

void Motor::TurnRight(int Speed)
{
	_Speed = Speed;
	digitalWrite(_Dir1Pin, HIGH);//Устанавливает направление левого мотора вперед. Sets direction of left motor to forward.
	digitalWrite(_Dir2Pin, LOW);//Устанавливает направление правого мотора назад. Sets direction of right motor to backward.
	analogWrite(_Speed1Pin, _Speed);
	analogWrite(_Speed2Pin, _Speed);
}

void Motor::TurnLeft(int Speed)
{
	_Speed = Speed;
	digitalWrite(_Dir1Pin, LOW);//Устанавливает направление левого мотора назад. Sets direction of left motor to backward.
	digitalWrite(_Dir2Pin, HIGH);//Устанавливает направление правого мотора вперед. Sets direction of right motor to forward.
	analogWrite(_Speed1Pin, _Speed);
	analogWrite(_Speed2Pin, _Speed);
}

void Motor::Stop()
{
	analogWrite(_Speed1Pin, 0);//Останавливает моторы. Stops motors.
	analogWrite(_Speed2Pin, 0);
}

void Motor::GoSquare(int TGoForward, int Speed)//Int TGoForward регулирует время движения вперед. Int TGoForward regulates time of going forward.
{
	_Speed = Speed;
	_TGoForward = TGoForward;
	digitalWrite(_Dir1Pin, HIGH);
	digitalWrite(_Dir2Pin, HIGH);
	analogWrite(_Speed1Pin, _Speed);
	analogWrite(_Speed2Pin, _Speed);
	delay(_TGoForward);//Задержка для движения вперед. Delay to go forward.
	analogWrite(_Speed1Pin, 0);
	analogWrite(_Speed2Pin, 0);
	delay(1000);
	digitalWrite(_Dir1Pin, HIGH);
	digitalWrite(_Dir2Pin, LOW);
	analogWrite(_Speed1Pin, 75);//Устанавливает скорость моторов на 75. Sets motors speed to 75.
	analogWrite(_Speed2Pin, 75);
	delay(255);//Задержка для поворота на 90 градусов. Delay to turn left on 90 deg.
	analogWrite(_Speed1Pin, 0);
	analogWrite(_Speed2Pin, 0);
	delay(1000);
	digitalWrite(_Dir1Pin, HIGH);
	digitalWrite(_Dir2Pin, HIGH);
	analogWrite(_Speed1Pin, _Speed);
	analogWrite(_Speed2Pin, _Speed);
	delay(_TGoForward);
	analogWrite(_Speed1Pin, 0);
	analogWrite(_Speed2Pin, 0);
	delay(1000);
	digitalWrite(_Dir1Pin, HIGH);
	digitalWrite(_Dir2Pin, LOW);
	analogWrite(_Speed1Pin, 75);
	analogWrite(_Speed2Pin, 75);
	delay(255);
	analogWrite(_Speed1Pin, 0);
	analogWrite(_Speed2Pin, 0);
	delay(1000);
	digitalWrite(_Dir1Pin, HIGH);
	digitalWrite(_Dir2Pin, HIGH);
	analogWrite(_Speed1Pin, _Speed);
	analogWrite(_Speed2Pin, _Speed);
	delay(_TGoForward);
	analogWrite(_Speed1Pin, 0);
	analogWrite(_Speed2Pin, 0);
	delay(1000);
	digitalWrite(_Dir1Pin, HIGH);
	digitalWrite(_Dir2Pin, LOW);
	analogWrite(_Speed1Pin, 75);
	analogWrite(_Speed2Pin, 75);
	delay(255);
	analogWrite(_Speed1Pin, 0);
	analogWrite(_Speed2Pin, 0);
	delay(1000);
	digitalWrite(_Dir1Pin, HIGH);
	digitalWrite(_Dir2Pin, HIGH);
	analogWrite(_Speed1Pin, _Speed);
	analogWrite(_Speed2Pin, _Speed);
	delay(_TGoForward);
	analogWrite(_Speed1Pin, 0);
	analogWrite(_Speed2Pin, 0);
	delay(1000);
	digitalWrite(_Dir1Pin, HIGH);
	digitalWrite(_Dir2Pin, LOW);
	analogWrite(_Speed1Pin, 75);
	analogWrite(_Speed2Pin, 75);
	delay(255);
	analogWrite(_Speed1Pin, 0);
	analogWrite(_Speed2Pin, 0);
	delay(1000);
}

void Motor::Turn90Left()
{
	digitalWrite(_Dir1Pin, LOW);
	digitalWrite(_Dir2Pin, HIGH);
	analogWrite(_Speed1Pin, 75);
	analogWrite(_Speed2Pin, 75);
	delay(255);
	analogWrite(_Speed1Pin, 0);
	analogWrite(_Speed2Pin, 0);
}

void Motor::Turn90Right()
{
	digitalWrite(_Dir1Pin, HIGH);
	digitalWrite(_Dir2Pin, LOW);
	analogWrite(_Speed1Pin, 75);
	analogWrite(_Speed2Pin, 75);
	delay(255);
	analogWrite(_Speed1Pin, 0);
	analogWrite(_Speed2Pin, 0);
}

void Motor::Turn180()//This function didn't tested. You can correct this function if your robot platform turns more or less then 180 deb.
{
	digitalWrite(_Dir1Pin, HIGH);
	digitalWrite(_Dir2Pin, LOW);
	analogWrite(_Speed1Pin, 75);
	analogWrite(_Speed2Pin, 75);
	delay(580);
	analogWrite(_Speed1Pin, 0);
	analogWrite(_Speed2Pin, 0);
}

