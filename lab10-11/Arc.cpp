#include "CArc.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "MyString.h"


#pragma region Constructors
Arc::Arc() : CCircle()
{
	_startAngle = 0;
	_endAngle = 0;
}

Arc::Arc(float startAngle, float endAngle) : CCircle() {
	if(startAngle >= 0 && endAngle >= 0)
	{
		_startAngle = startAngle;
		_endAngle = endAngle;
	
	}else{
		throw(MyString("Negative angle has been entered."));
	}
}

Arc::Arc(float startAngle, float endAngle, float radius) : CCircle(radius) {
	if(startAngle >= 0 && endAngle >= 0)
	{
		_startAngle = startAngle;
		_endAngle = endAngle;
	
	}else{
		throw(MyString("Negative angle has been entered."));
	}
}

Arc::Arc(float startAngle, float endAngle, float radius, int x, int y) : CCircle(radius, x, y) {
	if(startAngle >= 0 && endAngle >= 0)
	{
		_startAngle = startAngle;
		_endAngle = endAngle;
	
	}else{
		throw(MyString("Negative angle has been entered."));
	}
}

Arc::Arc(const Arc& ArcIn) : CCircle(ArcIn) {
	_startAngle = ArcIn._startAngle;
	_endAngle = ArcIn._endAngle;
}

Arc::~Arc(){}  
#pragma endregion

#pragma region Operators

Arc Arc::operator=(const Arc rhs){
	_startAngle = rhs._startAngle;
	_endAngle = rhs._endAngle;
	(*this).CCircle::operator=(rhs);

	return *this;
}

ostream& operator<<(ostream& outStream, const Arc& rhs){
	outStream << rhs._startAngle << " " << rhs._endAngle << " ";
	outStream << CCircle(rhs);
	return outStream;
}

istream& operator>>(istream& inStream, Arc& rhs){
	inStream >> rhs._startAngle >> rhs._endAngle;
	float r;
	int x, y;
	inStream >> r >> x >> y;
	rhs.setRadius(r);
	rhs.setX(x);
	rhs.setY(y);

	return inStream;
}  
#pragma endregion

#pragma region Mutators
	void Arc::setStartAngle(const float angle){
		_startAngle = angle;
	}

	void Arc::setEndAngle(const float angle){
		_endAngle = angle;
	}
#pragma endregion

#pragma region Accessors
	float Arc::getStartAngle()const{
		return _startAngle;
	}

	float Arc::getEndAngle()const{
		return _endAngle;
	}

	float Arc::getArea(){
		//Area of Sector = ½ × (θ × π/180) × r2   (when θ is in degrees)
		return ((getRadius() * getRadius() * (((_endAngle - _startAngle)* M_PI )/180))/2);
	}

#pragma endregion

