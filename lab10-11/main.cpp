#include <iostream>
#include "CPoint.h"
#include "CCircle.h"
#include "CArc.h"

using namespace std;

float arrayAreas(CPoint *arr[], const float size);

void main(){
	try{
		cout << "***************************************" << endl;
		cout << "***************************************" << endl;
		cout << "***************LAB 10-11***************" << endl;
		cout << "**************GAVIN COYNE**************" << endl;
		cout << "***************************************" << endl;
		cout << "***************************************" << endl;
		cout << "***************************************" << endl;
		CCircle firstCircle = CCircle(5.5, 5, 5);
		CCircle secondCircle = CCircle(2.2);
		CCircle thirdCircle = CCircle();
		CCircle fourthCircle = CCircle(firstCircle);
		//CPoint point = CPoint();
		Arc firstArc = Arc(0, 180, 5.5, 0, 0);//5 parameter
		Arc secondArc = Arc(75, 0, 18.5);//3
		Arc thirdArc =  Arc();//no params
		Arc fourthArc =  Arc(firstArc);//copy constructor

		cout << "(expected 8)Count = " << firstCircle.getCount() << endl;
		try{
			Arc tmpArc =  Arc();
			cout << "(expected 9)Count = " << firstCircle.getCount() << endl;
		}catch(MyString err){
			cout << err << endl;
		}
		cout << "(expected 8)Count = " << firstCircle.getCount() << endl;

		cout << endl << "(expect the same)fourthArc" << fourthArc << endl << " == first arc " << firstArc <<endl;
		fourthArc = secondArc;
		cout << endl << "(expect the same)fourthArc" << fourthArc << endl << " == Second arc " << secondArc <<endl;


		cout << endl << "(expect the same)fourthCircle" << fourthCircle << endl << " == first Circle " << firstCircle <<endl;
		fourthCircle = secondCircle;
		cout << endl << "(expect the same)fourthCircle" << fourthCircle << endl << " == second Circle " << secondCircle <<endl;

		cout << endl << endl<< "***************************************" << endl;
		cout << "***************************************" << endl;
		cout <<"Test negative radius error:" << endl;
		try{
			thirdCircle.setRadius(-111);
		}catch(MyString err){
			cout << "(Error Caught)"  << err << endl;
		}
		cout << "***************************************" << endl;
		cout << "***************************************" << endl;

		cout << endl<< "***************************************";
		cout << endl<< "***************************************" << endl;
		cout <<"Test negative start angle error:" << endl;
		try{
			thirdArc.setStartAngle(-111);
		}catch(MyString err){
			cout <<"(Error Caught)" << err << endl;
		}
		cout << "***************************************" << endl;
		cout << "***************************************" << endl;

		cout << endl<< "***************************************";
		cout << endl<< "***************************************" << endl;
		cout <<"Test negative End angle error:" << endl;
		
		try{
			thirdArc.setEndAngle(-111);
		}catch(MyString err){
			cout <<"(Error Caught)" << err << endl;
		}
		cout << "***************************************" << endl;
		cout << "***************************************" << endl << endl;
		
		cout << "***************************************" << endl;
		cout << "***************************************" << endl;
		cout << "*************TESTING >>************" << endl;
		cout << "***************************************" << endl;

		cout << "enter values for an arc: ";
		cin >> thirdArc;
		cout << thirdArc << endl;


		cout <<"enter values for a circle: ";
		cin >> thirdCircle;
		cout << thirdCircle << endl;

		cout << endl << "***************************************" << endl;
		cout << "***************************************" << endl;
		cout << "*************TESTING MUTATORS and************" << endl;
		cout << "*************************Accessors**********" << endl;


		thirdArc.setStartAngle(199.99);
		thirdArc.setEndAngle(360);
		thirdArc.setRadius(25.50);
		thirdArc.setX(4);
		thirdArc.setX(6);

		cout << "Expected \"199.99 0 r =25.50 (4, 6)\"" <<endl;
		cout << thirdArc << endl;


		Arc twoParam = Arc (5.5, 4.5);




	}catch(MyString err){
		cout << err << endl;
	}

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


		CCircle* circle1 = new CCircle(1.0, 1, 2);
		CCircle* circle2 = new CCircle(2.0, 3, 4);
		Arc* arc1 = new Arc(0, 360, 2.0, 5, 6);
		Arc* arc2 = new Arc(0, 180, 2.0, 7, 8);

		pointArray[0] = circle1;
		pointArray[1] = circle2;
		pointArray[2] = arc1;
		pointArray[3] = arc2;

		float totalArea = 0.0;
	
	for(int i = 0; i < size; i++)
		totalArea += pointArray[i]->getArea();
	cout << "***************************************" << endl;
	cout << "***************************************" << endl;
	cout << "**********OUTPUTTING (x, y)************" << endl;
	cout << "***************************************" << endl;
	cout << "TotalArray = " << (*pointArray[0]) << endl;
	cout << "TotalArray = " << (*pointArray[1]) << endl;
	cout << "TotalArray = " << (*pointArray[2]) << endl;
	cout << "TotalArray = " << (*pointArray[3]) << endl;

	cout << "(Expect around:34.55)Total area = " << totalArea << endl;
	
		//float testflaot = arrayAreas(pointArray, size);
		//cout << "TotalArray = " << testflaot << endl;
		
	}catch(MyString err){
		cout << err << endl;
	}

	//Commented out Cpoint (can't instantiate becuase of pure virtual class)
	//CPoint ERROR_POINT();
	system("pause");
}


float arrayAreas(CPoint *arr[], const int size){
	//float area = 0.0;
	
	//for(int i = 0; i < size; i++)area += arr[i]->getArea();

	return 0.0;
}