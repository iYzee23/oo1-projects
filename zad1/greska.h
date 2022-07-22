#ifndef _greska_h_
#define _greska_h_

#include <iostream>
#include <exception>
using namespace std;

class GrNemaTekuci : public exception {
public:
	const char* what() const override {
		return "Greska: nema tekuci";
	}
};

class GrVecPoslata : public exception {
public:
	const char* what() const override {
		return "Greska: vec ste poslali poruku";
	}
};

#endif // !_greska_h_