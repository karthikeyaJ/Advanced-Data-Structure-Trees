#include "Interfaces04.h"
#include "Point.h"


int Point::getX()
{
	return X;
}

int Point::getY()
{
	return Y;
}

void Point::setX(int value)
{
	
	this->X = value;
}
void Point::setY(int value)
{
	this->Y = value;
}

int Point::getDist()
{
	return dist;
}
void Point::setDist(int value)
{
	this->dist = value;
}

