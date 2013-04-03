#include <iostream>
#include "CPoint.h"

using namespace std;
int CPoint::counter = 0;

/*********************************************/
/*******************CONSTRUCTORz*************/
/*******************************************/
CPoint::CPoint()
{
	_x = 0;
	_y = 0;
	CPoint::counter++;
}

CPoint::CPoint(const CPoint& objIn)
{
	_x = objIn._x;
	_y = objIn._y;
	CPoint::counter++;
}

CPoint::CPoint(int x, int y)
{
	_x = x;
	_y = y;
	CPoint::counter++;
}
/*********************************************/
/*******************Destructor***************/
/*******************************************/
CPoint::~CPoint()
{
	CPoint::counter--;
}

/*********************************************/
/*******************Accessors****************/
/*******************************************/

int CPoint::getX()const
{
		return _x;
}

int CPoint::getY()const
{
	return _y;
}

int CPoint::getCount()const
{
	return CPoint::counter;
}

int CPoint::getArea()const
{
	return 0;
}

/*********************************************/
/*******************Mutators*****************/
/*******************************************/

void CPoint::setX(const int x)
{
	_x = x;
}

void  CPoint::setY(const int y)
{
	_y = y;
}

void CPoint::display(ostream& outPut)
{
	outPut << "(" << _x << ", " << _y << ")";
}

/*********************************************/
/*******************Operators*****************/
/*******************************************/
CPoint& CPoint::operator=(const CPoint& rhs)
{
	_x = rhs._x;
	_y = rhs._y;
	return *this;
}
ostream& operator<<(ostream& outStream, const CPoint& rhs)
{
	outStream << "(" << rhs._x << ", " << rhs._y << ")";
	return outStream;
}
istream& operator>>(istream& inStream, CPoint& rhs)
{
	inStream >> rhs._x >> rhs._y;
	return inStream;
}
