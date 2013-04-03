#include <iostream>

#ifndef CPOINT_H
#define CPOINT_H
using namespace std;


class CPoint{
public:
CPoint();
CPoint(const CPoint& objIn);
CPoint(int x, int y);
~CPoint();

int getX()const;
int getY()const;
int getArea()const;
int getCount()const;

void setX(const int x);
void setY(const int y);

void display(ostream& outPut);

CPoint& operator=(const CPoint& rhs);
friend ostream& operator<<(ostream& outStream, const CPoint& rhs);
friend istream& operator>>(istream& inStream, CPoint& rhs);



private:
	int _x, _y;
	static int counter;


};

#endif