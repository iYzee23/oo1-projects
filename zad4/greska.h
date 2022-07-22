#ifndef _greska_h_
#define _greska_h_

#include <iostream>
#include <exception>
using namespace std;

class GrLosIndeks : public exception {
public:
	const char* what() const override {
		return "Greska: nevalidan indeks";
	}
};

class GrBezvredanIgrac : public exception {
public:
	const char* what() const override {
		return "Greska: igrac nema dovoljnu vrednost";
	}
};

class GrNijeOdigran : public exception {
public:
	const char* what() const override {
		return "Greska: mec jos uvek nije odigran";
	}
};

#endif // !_greska_h_