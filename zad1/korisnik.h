#ifndef _korisnik_h_
#define _korisnik_h_

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Korisnik {
private:
	string ime;
	string email;
public:
	Korisnik(string ime, string email) : ime(ime), email(email) {}
	Korisnik(const Korisnik&) = delete;
	Korisnik& operator=(const Korisnik&) = delete;

	friend ostream& operator<<(ostream& os, const Korisnik& k);

	string getIme() const { return ime; }
	string getEmail() const { return email; }
};

#endif // !_korisnik_h_