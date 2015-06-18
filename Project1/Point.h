#pragma once
#include "Interfaces04.h"

class Point:public IPoint
{
public:
	Point() { X = 0; Y = 0; dist = 0; }
	~Point() {}
	int getX();
	int getY();
	void setX(int value);
	void setY(int value);
	int getDist();
	void setDist(int value);
private:
	
	int X;
	int Y;
	int dist;


	


};