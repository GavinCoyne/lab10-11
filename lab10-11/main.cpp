#include <iostream>
#include "CPoint.h"
#include "CCircle.h"
#include "CArc.h"
using namespace std;

void main(){
	try{
		CCircle test(1,1,1);
		Arc test1(1.0,1.0,1.0,1,1);
		Arc testArc2;
		testArc2 = test1;
		testArc2 = Arc(0,360, 2.0, 52, 6);
		cout << testArc2 << endl;
		cout << "Arc area = " << testArc2.getArea() << endl;

		try{
			testArc2.setRadius(-3);
		}catch(MyString err){
			cout << err << endl;
		}

		
		Arc newArc(50, 50);
		

		cout << newArc.getCount() << endl;
	}catch(MyString err){
		cout << err <<endl;
	}
	system("pause");
}