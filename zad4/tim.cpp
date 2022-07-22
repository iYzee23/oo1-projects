#include "tim.h"

void Tim::brisi()
{
	for (int i = 0; i < n; i++)
		if (igraci[i]) igraci[i] = nullptr;
	delete[] igraci;
	igraci = nullptr;
}

void Tim::kopiraj(const Tim& t)
{
	naziv = t.naziv;
	n = t.n;
	igraci = new Igrac * [n]();
	for (int i = 0; i < n; i++)
		if (t.igraci[i]) igraci[i] = t.igraci[i];
}

void Tim::premesti(Tim& t)
{
	naziv = t.naziv;
	n = t.n;
	igraci = t.igraci;
	t.igraci = nullptr;
}

void Tim::pisi(ostream& os) const
{
	os << naziv << "[";
	bool ind = false;
	for (int i = 0; i < n; i++) {
		if (igraci[i]) {
			if (ind) { os << ","; }
			else ind = true;
			os << *igraci[i];
		}
	}
	os << "]";
}

Tim::Tim(const Tim& t)
{
	kopiraj(t);
}

Tim::Tim(Tim&& t)
{
	premesti(t);
}

Tim& Tim::operator=(const Tim& t)
{
	if (this != &t) {
		brisi();
		kopiraj(t);
	}
	return *this;
}

Tim& Tim::operator=(Tim&& t)
{
	if (this != &t) {
		brisi();
		premesti(t);
	}
	return *this;
}

Tim::~Tim()
{
	brisi();
}

Igrac* Tim::operator[](int i)
{
	return igraci[i];
}

const Igrac* Tim::operator[](int i) const
{
	return igraci[i];
}

Tim& Tim::dodaj(Igrac* igr, int i)
{
	if (i < 0 || i >= n) throw GrLosIndeks();
	igraci[i] = igr;
	return *this;
}

int Tim::getBrIgraca() const
{
	int counter = 0;
	for (int i = 0; i < n; i++)
		if (igraci[i]) counter++;
	return counter;
}

double Tim::getVrednostTima() const
{
	double vrednost = 0;
	for (int i = 0; i < n; i++)
		if (igraci[i]) 
			vrednost += igraci[i]->getVrednost();
	int curr = getBrIgraca();
	return (curr ? vrednost / curr : 0);
}

bool operator==(const Tim& t1, const Tim& t2)
{
	if ((t1.naziv != t2.naziv) || (t1.n != t2.n)) return false;
	for (int i = 0; i < t1.n; i++) {
		if (t1.igraci[i] && !t2.igraci[i]) return false;
		else if (!t1.igraci[i] && t2.igraci[i]) return false;
		else if (t1.igraci[i] && t2.igraci[i] && !(*t1.igraci[i] == *t2.igraci[i])) return false;
	}
	return true;
}

bool operator!=(const Tim& t1, const Tim& t2)
{
	return !(t1 == t2);
}

ostream& operator<<(ostream& os, const Tim& t)
{
	t.pisi(os);
	return os;
}
