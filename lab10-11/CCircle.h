#include <iostream>
#include "CPoint.h"

#ifndef CCIRCLE_H
#define CCIRCLE_H


using namespace std;

class CCircle : public CPoint
{
	public:
		CCircle();
		CCircle(const float radius);
		CCircle(const float radius, const int x, const int y);
		CCircle(const CCircle& cpyObj);
		~CCircle();
		float getRadius();
		float getArea();
		void setRadius(float radius);

		CCircle& operator=(const CCircle rhs);
		friend ostream& operator<<(ostream& outStream, const CCircle& rhs);
		friend istream& operator>>(istream& outStream, CCircle& rhs);

	private:
		float _radius;
};

#endif