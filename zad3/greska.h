#ifndef _greska_h_
#define _greska_h_

#include <iostream>
#include <exception>
using namespace std;

class GrLosIndex : public exception {
public:
	const char* what() const override {
		return "Greska: nevalidan index";
	}
};

class GrTackaVecPostoji : public exception {
public:
	const char* what() const override {
		return "Greska: tacka vec postoji";
	}
};

#endif // !_greska_h_