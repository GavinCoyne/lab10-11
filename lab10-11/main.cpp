#include <iostream>
#include "CPoint.h"
#include "CCircle.h"
#include "CArc.h"
using namespace std;

void main(){
	try{
		CPoint* pointPointer;
		CCircle firstCircle = CCircle(5.5, 5, 5);
		Arc firstArc = Arc(0, 180, 5.5, 0, 0);
		Arc firstArc2 = Arc(180, 0, 5.5, 0, 0);


		pointPointer = &firstCircle;
		cout << "getArea() pointPointer(~95) = " << (*pointPointer).getArea() << endl;

		pointPointer = &firstArc;
		cout << "getArea() pointPOinter(~95/2) = " << (*pointPointer).getArea() << endl;
		cout << "getArea() pointPOinter(~95/2) = " << firstArc2.getArea() << endl;


		try{
			CCircle errorCirc(-15.0);
		}catch(MyString err){
			cout << err << endl;
		}
		try{
			Arc badAngles(15, 360, -1, 1, 1);
		}catch(MyString err){
			cout << endl << "Throwing CCircle error by setting arc radius negative: ";
			cout << endl << err << endl << endl;
		}

		try{
			Arc badAngles(-15, 360, 1, 1, 1);
		}catch(MyString err){
			cout << err << endl;
		}
		try{
			Arc badAngles(15, -360, 1, 1, 1);
		}catch(MyString err){
			cout << err << endl;
		}

		try{
			Arc badAngles(721, 360, 1, 1, 1);
			cout << "startAngle = " << badAngles.getStartAngle();
			cout << " EndAngle = " << badAngles.getEndAngle() << endl;
		}catch(MyString err){
			cout << err << endl;
		}
		
		try{
			Arc badAngles(400, 360, 1, 1, 1);
			cout << "startAngle = " << badAngles.getStartAngle();
			cout << " EndAngle = " << badAngles.getEndAngle() << endl;
		}catch(MyString err){
			cout << err << endl;
		}

	}catch(MyString err){
		cout << err <<endl;
	}
	system("pause");
}