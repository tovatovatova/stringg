#include <iostream>
#include<cstring>
#include<string>
#include "MyString.h"
#pragma warning (disable:4996)
using namespace std;
ostream& operator<<(ostream& os, const MyString& ms)
{
	{
		if (ms.str)
			os << ms.str << endl;
	//	cout << ms.str << endl;
		return os;
	}
}
istream& operator>>(istream& is, MyString& ms)
{
	ms.str = new char[100+1];
	ms.len = 100;
	is >> ms.str;
	return is;
}
int main() 
{
	//MyString a, b;
	int n;
	MyString a;
	MyString b;
	cin >> a;
	cin >> b;
	
	cin >> n;
	cout << "a";
	if (a > b)
		cout << ">";
	else if (a == b)
		cout << "=";
	 else  if (a < b)
		cout << "<";
	cout << "b\n";
	/*cout << "move ctor" << endl;
	cout << "move assign" << endl;*/

	MyString s;
	s=b.insert(n, a.getStr());
	if (s.getStr() != nullptr)
		cout << s;
	else
	{
		cout << "ERROR";
	}
	char tav;
	int indexx;
	cin >> tav;
	cin >> indexx;
	s[indexx] = tav;
	cout << s;

}