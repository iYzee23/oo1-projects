#ifndef _oznaka_h_
#define _oznaka_h_

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class VremenskaOznaka {
private:
	int god, mes, dan;
	int hh, mm;
public:
	VremenskaOznaka(int god, int mes, int dan, int hh, int mm) 
		: god(god), mes(mes), dan(dan), hh(hh), mm(mm) {}

	friend ostream& operator<<(ostream& os, const VremenskaOznaka& v);
};

#endif // !_oznaka_h_