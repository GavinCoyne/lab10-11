#include <iostream>
#include "CPoint.h"
#include "CCircle.h"
#include "CArc.h"
using namespace std;

void main(){
	CCircle test(1,1,1);
	Arc test1(1.0,1.0,1.0,1,1);
	Arc testArc2;
	testArc2 = test1;
	cout << testArc2;

	system("pause");
}