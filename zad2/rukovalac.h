#ifndef _rukovalac_h_
#define _rukovalac_h_

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Posiljka;

class Rukovalac {
public:
	virtual ~Rukovalac() {}
	virtual void obradiPosiljku(Posiljka* p) const = 0;
};

#endif // !_rukovalac_h_