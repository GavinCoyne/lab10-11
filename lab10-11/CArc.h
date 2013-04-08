#include <iostream>
#include "CCircle.h"
#include "MyString.h"

#ifndef CARC_H
#define CARC_H

using namespace std;

class Arc : public CCircle 
{
public:
	Arc();
	Arc(float startAngle, float endAngle);
	Arc(float startAngle, float endAngle, float radius);
	Arc(float startAngle, float endAngle, float radius, int x, int y);
	Arc(const Arc& objIn);
	 ~Arc();

	Arc operator=(const Arc rhs);

	float getStartAngle()const;
	float getEndAngle()const;
	float getArea();

	void setStartAngle(const float)
		throw(MyString);
	void setEndAngle(const float)
		throw(MyString);

	friend ostream& operator<<(ostream& outStream, const Arc& rhs);
	friend istream& operator>>(istream& inStream, Arc& rhs);

private:
	float _startAngle, _endAngle;
};

#endif