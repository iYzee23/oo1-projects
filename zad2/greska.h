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

class GrNijeIzracunato : public exception {
public:
	const char* what() const override {
		return "Greska: detalji posiljke jos uvek nisu izracunati";
	}
};

class GrNoviRukovalac : public exception {
public:
	const char* what() const override {
		return "Greska: detalji posiljke su vec izracunati";
	}
};

#endif // !_greska_h_