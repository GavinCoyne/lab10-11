#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using namespace std;

class MyString
{
public:
	MyString();
	MyString(char* MyStringArray);
	MyString(const MyString& cpyArray);
	~MyString();//Destructor

	
	//Public member Functions
	bool operator ==(const MyString& rhs)const;
	bool operator >=(const MyString& rhs)const;
	bool operator <=(const MyString& rhs)const;
	bool operator >(const MyString& rhs)const;
	bool operator <(const MyString& rhs)const;
	bool operator !=(const MyString& rhs)const;
	MyString operator =(const MyString& rhs);

	MyString operator +(const MyString& rhs);
	MyString operator +=(const MyString& rhs);

	friend ostream& operator <<(ostream& out, const MyString& rhs);
	friend istream& operator >>(istream& in, MyString& rhs);

private:
	char* _MyStringArray;
	int _length;
	
};
#endif
