/*
Gavin Coyne
march 19th/2013
*/
#include <iostream>
#include "MyString.h"
#include <cstring>

using namespace std;

MyString::MyString()
{
	_length = 0;
	_MyStringArray = new char[_length + 1];
	*_MyStringArray = '\0';

}

MyString::MyString(char* MyStringArray)
{
	_length = strlen(MyStringArray);
	
	_MyStringArray = new char[_length + 1];
	strcpy(_MyStringArray, MyStringArray);

}

MyString::MyString(const MyString& cpyArray)
{
	_length = cpyArray._length;
	_MyStringArray = new char[cpyArray._length+1];
	strcpy(_MyStringArray, cpyArray._MyStringArray);
}

//Destructor
MyString::~MyString()
{
	delete[] (_MyStringArray);
}


/*
Coparisons operators
!!!!!!!!!!!!!!!!!!!!
*/
bool MyString::operator ==(const MyString& rhs)const
{
	return (strcmp(_MyStringArray, rhs._MyStringArray) == 0);
}

bool MyString::operator !=(const MyString& rhs)const
{
	return (strcmp(_MyStringArray, rhs._MyStringArray) != 0);
}

bool MyString::operator >=(const MyString& rhs)const
{
	return (strcmp(_MyStringArray, rhs._MyStringArray) >= 0);
}

bool MyString::operator >(const MyString& rhs)const
{
	return (strcmp(_MyStringArray, rhs._MyStringArray) > 0);
}

bool MyString::operator <(const MyString& rhs)const
{
	return (strcmp(_MyStringArray, rhs._MyStringArray) < 0);
}

bool MyString::operator <=(const MyString& rhs)const
{
	return (strcmp(_MyStringArray, rhs._MyStringArray) <= 0);
}



MyString MyString::operator =(const MyString& rhs)
{
	if(*this != rhs)
	{
		delete[] _MyStringArray;
		_MyStringArray = NULL;
		_length = strlen(rhs._MyStringArray);
	
		_MyStringArray = new char[strlen(rhs._MyStringArray) + 1];
		strcpy(_MyStringArray, rhs._MyStringArray);
	}

	return *this;
}

/*
**********************ADDITIONS START******************************
*/
 MyString MyString::operator +(const MyString& rhs)
{
	char *tmpString = new char[strlen(_MyStringArray) + strlen(rhs._MyStringArray) + 1];
	strcpy(tmpString, _MyStringArray);
	return MyString(strcat(tmpString, rhs._MyStringArray));
}


MyString MyString::operator +=(const MyString& rhs)
{
	//*this = *this + rhs;
	char *tmpString = new char[strlen(_MyStringArray) + strlen(rhs._MyStringArray) + 1];
	strcpy(tmpString, _MyStringArray);
	_length = strlen(_MyStringArray) + strlen(rhs._MyStringArray);
	delete [] _MyStringArray;
	_MyStringArray = new char[strlen(_MyStringArray) + strlen(rhs._MyStringArray) + 1];
	strcpy(_MyStringArray, tmpString);
	strcat(_MyStringArray, rhs._MyStringArray);
	return *this;
}

/*
**********************ADDITIONS END******************************
*/
//Output operator
ostream& operator <<(ostream& out, const MyString& rhs)
{
	out << rhs._MyStringArray;
	return out;
}
//input operator
istream& operator >>(istream& in, MyString& rhs)
{
	char *tmpString = new char[1024 + 1];
	in.getline(tmpString, 1024);

	delete[] rhs._MyStringArray;
	rhs._length = strlen(tmpString);
	rhs._MyStringArray = new char[rhs._length + 1];
	strcpy(rhs._MyStringArray, tmpString);

	return  in;
}
