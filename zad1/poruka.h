#ifndef _poruka_h_
#define _poruka_h_

#include "korisnik.h"

class ElPoruka {
public:
	enum Stanje { U_PRIPREMI, POSLATA, PRIMLJENA };
protected:
	virtual void pisi(ostream& os) const;

	Korisnik* posiljalac;
	Korisnik* primalac;
	Stanje stanje = U_PRIPREMI;
	string naslov;
public:
	ElPoruka(Korisnik* pos, Korisnik* prim, string nasl) : posiljalac(pos), primalac(prim), naslov(nasl) {}
	virtual ~ElPoruka() {}

	virtual void posaljiPoruku() = 0;
	virtual ElPoruka* kopija() const = 0;
	friend ostream& operator<<(ostream& os, const ElPoruka& e);

	Korisnik* getPosiljalac() const { return posiljalac; }
	Korisnik* getPrimalac() const { return primalac; }
	Stanje getStanje() const { return stanje; }
	void setStanje(Stanje stanje) { this->stanje = stanje; }
	string getNaslov() const { return naslov; }
};

#endif // !_poruka_h_