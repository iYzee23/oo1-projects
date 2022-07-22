#ifndef _tacka_h_
#define _tacka_h_

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Tacka {
private:
	int x;
	int y;
public:
	Tacka(int x, int y) : x(x), y(y) {}

	friend bool operator==(const Tacka& t1, const Tacka& t2);
	friend ostream& operator<<(ostream& os, const Tacka& t);
	friend double rastojanje(const Tacka& t1, const Tacka& t2);
};

#endif // !_tacka_h_