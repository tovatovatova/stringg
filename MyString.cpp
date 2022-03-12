#include "MyString.h"
#include <iostream>
#include<cstring>
#include<string>
#pragma warning (disable:4996)
using namespace std;
MyString::MyString(const char* s)
{
	if (s)
	{
		len = strlen(s) ;
		str = new char[len+1];
		strcpy(str, s);
	}
	else
		str = nullptr;
}
MyString::MyString(const MyString& ms) :MyString(ms.str){}//copy constructor
MyString& MyString::operator=(const MyString& ms)//assignment operator
{
	if (str)
		delete[] str;
	if (ms.str)
	{
		str = new char[ms.len + 1];
		strcpy(str, ms.str);
	}
	else
		str = nullptr;
	len = strlen(str);
	//cout << "operator= : " << str << endl;
	return *this;
}
MyString::~MyString() //destructor
{
	if (str)
		delete[]str;
	str = nullptr;
}
MyString::MyString(MyString&& ms)
{ // move constructor
	len = ms.len;
	str = ms.str; //steal (dont copy) rvalue's data
	ms.str = nullptr; //very important!!!
	cout << "move ctor" << endl;
}
MyString& MyString::operator=(MyString&& ms)
{ // move assignment operator
	if (str)
		delete[] str;
	len = ms.len;
	str = ms.str; // steal (dont copy) rvalue's data
	ms.str = nullptr; //very important!!!
	cout << "move assign" << endl;
	return *this;
}
	bool MyString::operator== (const MyString & sm) const
	{
		if (len != sm.len)
			return false;
		return (strcmp(str, sm.str) == 0);
	}
	bool MyString::operator!= (const MyString & sm) const
	{
		return !(str==sm.str);

	}
	bool MyString::operator<= (const MyString & sm) const 
	{
		return !(*this > sm);

	}
	bool MyString::operator< (const MyString & sm) const
	{
		return !(str >= sm.str);
	}
	bool MyString:: operator> (const MyString & sm) const 
	{
		return !(str <= sm.str);

	}
	bool MyString::operator>= (const MyString & sm) const 
	{
		return strcmp(str, sm.str) >= 0;

	}
	char& MyString::operator[](int index) 
	{
		if (strlen(str) <= index || index<0)
		{
			cout << "ERROR\n";
			exit(0);
		}
		else
			return str[index];
	}
	MyString MyString::insert(int index, const char* sm)
	{
		MyString newst;
		int rest;
		char*temp;
		temp = new char[index+1];
		if (index<=strlen(str))
		{
			newst.len = strlen(str)+strlen(sm);
			newst.str = new char[newst.len + 1];
			strncpy(temp, str, index);
			temp[index] = '\0';
			strcpy(newst.str, temp);
			//cout << newst.str;
			rest = strlen(str) + strlen(sm) - index;
			strcat(newst.str, sm);
			//cout << newst.str;
			rest -= strlen(sm);
			bool flag = false;
			
			if (rest>0)
			{
				strcat(newst.str, str + index);

				
				
			}
		

			return newst;


		}
		else
		{
			cout << "ERROR\n";
			newst = nullptr;
			return newst;
		}
	}
	
/*
* hello
world
2
a>b
move ctor
move assign
wohellorld
?
2
wo?ellorld

*/
	