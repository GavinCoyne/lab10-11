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
	setStartAngle(startAngle);
	setEndAngle(endAngle);
}

Arc::Arc(float startAngle, float endAngle, float radius) : CCircle(radius) {
	setStartAngle(startAngle);
	setEndAngle(endAngle);
}

Arc::Arc(float startAngle, float endAngle, float radius, int x, int y) : CCircle(radius, x, y) {
	setStartAngle(startAngle);
	setEndAngle(endAngle);
}

Arc::Arc(const Arc& ArcIn) : CCircle(ArcIn) {
	setStartAngle(ArcIn._startAngle);
	setEndAngle(ArcIn._endAngle);
}

Arc::~Arc(){
	
}  
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
		if(angle >= 360){
			_startAngle = angle - 360;
			Arc::setStartAngle(_startAngle);
		}else if(angle < 0){
			throw(MyString("Arc Error start angle can't be a negative value."));
		}else{
			_startAngle = angle;
		}
	}

	void Arc::setEndAngle(const float angle){
		if(angle >= 360){
			_endAngle = angle -360;
			Arc::setEndAngle(_endAngle);
		}else if(angle < 0){
			throw(MyString("Arc Error End angle must be positive."));
		}else{
			_endAngle = angle;
		}
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
		//Make all areas positive with abs(theta)
		float theta = (abs(_endAngle-_startAngle));
		if(theta == 0)theta = 1*360;
		//Area of Sector = ½ × (θ × π/180) × r2   (when θ is in degrees)
		return (((theta)/360)*CCircle::getArea());
	}

#pragma endregion

