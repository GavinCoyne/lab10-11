#include "CArc.h"


Arc::Arc() : CCircle()
{
	_startAngle = 0;
	_endAngle = 0;
}

Arc::Arc(float startAngle, float endAngle) : CCircle() {
	_startAngle = startAngle;
	_endAngle = endAngle;
}

Arc::Arc(float startAngle, float endAngle, float radius) : CCircle(radius) {
	_startAngle = startAngle;
	_endAngle = endAngle;
}

Arc::Arc(float startAngle, float endAngle, float radius, int x, int y) : CCircle(radius, x, y) {
	_startAngle = startAngle;
	_endAngle = endAngle;
}

Arc::Arc(const Arc& ArcIn){
	*this = ArcIn;
}

Arc::~Arc(){}

Arc Arc::operator=(const Arc rhs){
	_startAngle = rhs._startAngle;
	_endAngle = rhs._endAngle;
	//(*this).CCircle::operator=(rhs);

	return *this;
}

ostream& operator<<(ostream& outStream, const Arc rhs){
	return outStream;
}