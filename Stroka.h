#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Stroka
{
private:
	char str[80];
public:
	Stroka(char*);
	Stroka() {}
	Stroka(const Stroka&);
	Stroka& operator=(const Stroka&);
	Stroka& operator+(const Stroka&);
	int operator==(const Stroka&);
	int dlina();
	void vvod();
	void vyvod();
};
ostream& operator<<(ostream&, Stroka&);
istream& operator>>(istream&, Stroka&);