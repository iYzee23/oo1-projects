#ifndef _posiljka_h_
#define _posiljka_h_

#include "lista.h"
#include "rukovalac.h"
#include "artikal.h"

class Posiljka {
private:
	friend class Prodavac;

	void brisi() {}
	void kopiraj(const Posiljka& p);
	void premesti(Posiljka& p);

	static int ID;
	int id = ++ID;
	Artikal artikal;
	Lista<Rukovalac*> lista;
	int daniCekanja = 0;
	double cena = 0;
	bool izracunata = false;
public:
	Posiljka(Artikal& art) : artikal(art) {}
	Posiljka(const Posiljka& p);
	Posiljka(Posiljka&& p);
	Posiljka& operator=(const Posiljka& p);
	Posiljka& operator=(Posiljka&& p);
	~Posiljka();

	Posiljka& operator+=(Rukovalac* r);
	friend ostream& operator<<(ostream& os, const Posiljka& p);
	void izracunajDetalje();

	Artikal& getArtikal() { return artikal; }
	const Artikal& getArtikal() const { return artikal; }
	int getID() const { return id; }
	int getDaniCekanja() const;
	double getCena() const;
};

#endif // !_posiljka_h_