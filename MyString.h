#pragma once
#include <iostream>
#include<cstring>
#include<string>
#pragma warning (disable:4996)
using namespace std;
class MyString 
{
	char* str;
	int len=0;
	public:
	MyString(): str(nullptr), len(0){}//explicit empty constructor
	MyString(const char* s); //constructor
	MyString(const MyString& ms); //copy constructor
	MyString& operator=(const MyString& ms); //assignment operator
	~MyString(); //destructor
	MyString(MyString&& ms); // move constructor
	MyString& operator=(MyString&& ms); //move assignment operator
	bool operator== (const MyString& sm) const;
	bool operator!= (const MyString& sm) const;
	bool operator<= (const MyString& sm) const;
	bool operator< (const MyString& sm) const;
	bool operator> (const MyString& sm) const;
	bool operator>= (const MyString& sm) const;
	char& operator[](int index);
	MyString insert(int index, const char* str);
	char* getStr()
	{
		return str;
	}
	
    friend ostream& operator<<(ostream& os, const MyString& ms);
	friend istream& operator>>(istream& is, MyString& ms);
};
