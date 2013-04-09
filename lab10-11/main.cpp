#include <iostream>
#include "CPoint.h"
#include "CCircle.h"
#include "CArc.h"

using namespace std;

float arrayAreas(CPoint *arr[], const float size);

void main(){
	//Program testing 1
	//Question 3
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
		cout << endl << endl;
	}catch(MyString err){
		cout << err <<endl;
	}


	//Question 4 - Program 2
	try{
		const int size = 4;
		CPoint *pointArray[size];


		CCircle* circle1 = new CCircle(1.0, 1, 1);
		CCircle* circle2 = new CCircle(2.0, 2, 2);
		Arc* arc1 = new Arc(180, 360, 1.0, 1, 1);
		Arc* arc2 = new Arc(0, 180, 2.0, 2, 2);

		pointArray[0] = circle1;
		pointArray[1] = circle2;
		pointArray[2] = arc1;
		pointArray[3] = arc2;

		float totalArea = 0.0;
	
	//for(int i = 0; i < size; i++)totalArea += pointArray[i]->getArea();

		cout << "TotalArray = " << (*pointArray[0]) << endl;
		cout << "TotalArray = " << (*pointArray[1]) << endl;
		cout << "TotalArray = " << (*pointArray[2]) << endl;
		cout << "TotalArray = " << (*pointArray[3]) << endl;
		cout << "TotalArray = " << arrayAreas(pointArray, size) << endl;
		
	}catch(MyString err){
		cout << err << endl;
	}

	//Commented out Cpoint (can't instantiate becuase of pure virtual class)
	//CPoint ERROR_POINT();
	system("pause");
}


float arrayAreas(CPoint *arr[], const int size){
	float area = 0.0;
	
	//for(int i = 0; i < size; i++)area += arr[i]->getArea();

	return area;
}