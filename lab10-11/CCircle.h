#include <iostream>
#include "CPoint.h"
#include "MyString.h"

#ifndef CCIRCLE_H
#define CCIRCLE_H


using namespace std;

class CCircle : public CPoint{
	public:
		CCircle();
		CCircle(const float radius);
			
		CCircle(const float radius, const int x, const int y);
			
		CCircle(const CCircle& cpyObj);
		virtual ~CCircle();
		float getRadius()const;
		float getArea();
		void setRadius(float radius)
			throw(MyString);

		CCircle& operator=(const CCircle rhs);
		friend ostream& operator<<(ostream& outStream, const CCircle& rhs);
		friend istream& operator>>(istream& outStream, CCircle& rhs);

	private:
		float _radius;
};
#endif