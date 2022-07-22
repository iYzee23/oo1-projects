#include "prodavac.h"

Prodavac& Prodavac::dodajUKatalog(Artikal& a, double marza, int dani)
{
	artikli += a;
	marze += marza;
	daniNabavke += dani;
	return *this;
}

double Prodavac::prodajnaCenaArtikla(const Artikal& a, double marza) const
{
	return a.getNabCena() * marza;
}

void Prodavac::obradiPosiljku(Posiljka* p) const
{
	for (int i = 0; i < artikli.getBrElem(); i++) {
		if (p->artikal == artikli[i]) {
			p->daniCekanja += daniNabavke[i];
			p->cena += prodajnaCenaArtikla(artikli[i], marze[i]);
		}
	}
}
