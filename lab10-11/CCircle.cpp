#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "MyString.h"

CCircle::CCircle() : CPoint(){
	_radius = 0.0;
}

CCircle::CCircle(float radius) : CPoint(){
	if(radius > 0)_radius = radius;
	else throw(MyString("Error. Negative radius in 1 param constructor."));
}

CCircle::CCircle(float radius, int x, int y) : CPoint(x, y){
	if(radius > 0)_radius = radius;
	else throw(MyString("Error. Negative radius in 3 param constructor."));
}

CCircle::CCircle(const CCircle& cpyObj) : CPoint(cpyObj){
	_radius = cpyObj._radius;
}

CCircle::~CCircle(){
	
}

float CCircle::getRadius(){
	return _radius;
}

float CCircle::getArea(){
	return (_radius * _radius * M_PI);
}

void CCircle::setRadius(float radius){
	if(radius > 0)_radius = radius;
	else throw(MyString("Error calling setRadius(float): negative float entered."));
}

CCircle& CCircle::operator=(const CCircle rhs){
	_radius = rhs._radius;
	(*this).CPoint::operator=(rhs);
	return *this;
}

ostream& operator<<(ostream& outStream, const CCircle& rhs){
	outStream << "r = " << rhs._radius;
	outStream << " (" <<rhs.getX() << ", " << rhs.getY() << ")";
	return outStream;
}

istream& operator>>(istream& inStream, CCircle& rhs){
	int x, y;
	inStream>> rhs._radius >> x >> y;
	rhs.setX(x);
	rhs.setY(y);
	return inStream;
}