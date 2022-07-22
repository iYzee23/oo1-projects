#include "mec.h"

Mec::Mec(const Mec& m) : timovi(nullptr, nullptr), poeni(nullptr, nullptr)
{
	kopiraj(m);
}

Mec::Mec(Mec&& m) : timovi(nullptr, nullptr), poeni(nullptr, nullptr)
{
	premesti(m);
}

Mec& Mec::operator=(const Mec& m)
{
	if (this != &m) {
		brisi();
		kopiraj(m);
	}
	return *this;
}

Mec& Mec::operator=(Mec&& m)
{
	if (this != &m) {
		brisi();
		premesti(m);
	}
	return *this;
}

Mec::~Mec()
{
	brisi();
}

Par<int>& Mec::getParPoena()
{
	if (!odigran) throw GrNijeOdigran();
	int* prvi = poeni.getPrviPok();
	int* drugi = poeni.getDrugiPok();
	if (prvi) delete prvi;
	if (drugi) delete drugi;
	poeni.setPrviPok(new int(ishod == POBEDA_DOMACIN ? 3 : (ishod == NERESENO ? 1 : 0)));
	poeni.setDrugiPok(new int(ishod == POBEDA_GOST ? 3 : (ishod == NERESENO ? 1 : 0)));
	return poeni;
}

void Mec::odigrajMec()
{
	odigran = true; 
	int curr1 = 0, curr2 = 0;
	double sum1 = timovi.getPrviPok()->getVrednostTima();
	double sum2 = timovi.getDrugiPok()->getVrednostTima();
	if (sum1 > sum2) {
		ishod = POBEDA_DOMACIN;
		for (int i = 0; curr1 < timovi.getPrviPok()->getBrIgraca(); i++) {
			Igrac* temp = (*timovi.getPrviPok())[i];
			if (temp) temp->promeniVrednost(10), curr1++;
		}
		for (int i = 0; curr2 < timovi.getDrugiPok()->getBrIgraca(); i++) {
			Igrac* temp = (*timovi.getDrugiPok())[i];
			if (temp) temp->promeniVrednost(-10), curr2++;
		}
	}
	else if (sum1 < sum2) {
		ishod = POBEDA_GOST;
		for (int i = 0; curr1 < timovi.getPrviPok()->getBrIgraca(); i++) {
			Igrac* temp = (*timovi.getPrviPok())[i];
			if (temp) temp->promeniVrednost(-10), curr1++;
		}
		for (int i = 0; curr2 < timovi.getDrugiPok()->getBrIgraca(); i++) {
			Igrac* temp = (*timovi.getDrugiPok())[i];
			if (temp) temp->promeniVrednost(10), curr2++;
		}
	}
	else ishod = NERESENO;
}

void Mec::brisi()
{
	int* prvi = poeni.getPrviPok();
	int* drugi = poeni.getDrugiPok();
	if (prvi) delete prvi, prvi = nullptr;
	if (drugi) delete drugi, drugi = nullptr;
}

void Mec::kopiraj(const Mec& m)
{
	timovi = m.timovi;
	ishod = m.ishod;
	odigran = m.odigran;
	const int* prvi = m.poeni.getPrviPok();
	const int* drugi = m.poeni.getDrugiPok();
	if (prvi) poeni.setPrviPok(new int(*prvi));
	if (drugi) poeni.setDrugiPok(new int(*drugi));
}

void Mec::premesti(Mec& m)
{
	timovi = m.timovi;
	ishod = m.ishod;
	odigran = m.odigran;
	poeni = m.poeni;
	m.poeni.setPrviPok(nullptr);
	m.poeni.setDrugiPok(nullptr);
}

ostream& operator<<(ostream& os, const Mec& m)
{
	os << m.timovi << endl;
	if (m.odigran) {
		string ish[3]{ "POBEDA_DOMACINA", "NERESENO", "POBEDA_GOSTA" };
		os << ish[m.ishod] << endl;
	}
	return os;
}
