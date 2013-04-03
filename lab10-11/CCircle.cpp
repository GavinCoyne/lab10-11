#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>

CCircle::CCircle() : CPoint() 
{
	_radius = 0.0;
}

CCircle::CCircle(float radius) : CPoint()
{
	_radius = radius;
}

CCircle::CCircle(float radius, int x, int y) : CPoint(x, y)
{
	_radius = radius;
}



CCircle::~CCircle(){
	
}

float CCircle::getRadius(){
	return _radius;
}

float CCircle::getArea(){
	
	return (_radius * _radius * M_PI);
}

void CCircle::setRadius(float radius)
{
	_radius = radius;
}

CCircle& CCircle::operator=(const CCircle rhs){
	_radius = rhs._radius;
	(*this).CPoint::operator=(rhs);
	return *this;
}

ostream& operator<<(ostream& outStream, const CCircle& rhs){
	outStream << "Radius = " << rhs._radius;
	outStream << " Point = " << CPoint(rhs);
	return outStream;
}

istream& operator>>(istream& inStream, CCircle& rhs){
	inStream >> rhs._radius;
	int x, y;
	inStream >> x >> y;

	rhs.setX(x);
	rhs.setY(y);
	return inStream;
}