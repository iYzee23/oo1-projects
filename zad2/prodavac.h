#ifndef _prodavac_h_
#define _prodavac_h_

#include "lista.h"
#include "artikal.h"
#include "posiljka.h"

class Prodavac : public Rukovalac {
private:
	string naziv;
	Lista<Artikal> artikli;
	Lista<double> marze;
	Lista<int> daniNabavke;
public:
	Prodavac(string naziv) : naziv(naziv) {}

	Prodavac& dodajUKatalog(Artikal& a, double marza, int dani);
	double prodajnaCenaArtikla(const Artikal& a, double marza) const;
	void obradiPosiljku(Posiljka* p) const override;
	string getNaziv() const { return naziv; }
};

#endif // !_prodavac_h_