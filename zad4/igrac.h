#ifndef _igrac_h_
#define _igrac_h_

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Igrac {
private:
	string ime;
	int vrednost;
public:
	Igrac(string ime, int vrednost = 1000) : ime(ime), vrednost(vrednost) {}

	friend bool operator==(const Igrac& i1, const Igrac& i2);
	friend bool operator!=(const Igrac& i1, const Igrac& i2);
	friend ostream& operator<<(ostream& os, const Igrac& i);
	string getIme() const { return ime; }
	int getVrednost() const { return vrednost; }
	void promeniVrednost(double procenat);
};

#endif // !_igrac_h_