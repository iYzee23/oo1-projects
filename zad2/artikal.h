#ifndef _artikal_h_
#define _artikal_h_

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Artikal {
private:
	string naziv;
	int barKod;
	double nabCena;
public:
	Artikal() = default;
	Artikal(string naz, int bar, double cena) : naziv(naz), barKod(bar), nabCena(cena) {}

	friend bool operator==(const Artikal& a1, const Artikal& a2);
	friend bool operator!=(const Artikal& a1, const Artikal& a2);
	string getNaziv() const { return naziv; }
	int getBarKod() const { return barKod; }
	double getNabCena() const { return nabCena; }
};

#endif // !_artikal_h_