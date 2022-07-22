#ifndef _vozilo_h_
#define _vozilo_h_

#include "put.h"

class Vozilo {
protected:
	virtual void pisi(ostream& os) const;

	string nazivModela;
public:
	Vozilo(string naziv) : nazivModela(naziv) {}
	virtual ~Vozilo() {}

	friend ostream& operator<<(ostream& os, const Vozilo& v);
	double cenaPrevoza(const Put& p) const;
	virtual double startnaCena() const = 0;
};

class Obicno : public Vozilo {
public:
	Obicno(string naziv) : Vozilo(naziv) {}
	double startnaCena() const override { return 120; }
};

#endif // !_vozilo_h_