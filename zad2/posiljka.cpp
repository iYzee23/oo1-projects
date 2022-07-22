#include "posiljka.h"

int Posiljka::ID = 0;

ostream& operator<<(ostream& os, const Posiljka& p)
{
    return os << "Posiljka[" << p.id << ", " << p.artikal.getNaziv() << "]";
}

void Posiljka::kopiraj(const Posiljka& p)
{
    artikal = p.artikal;
    lista = p.lista;
    daniCekanja = p.daniCekanja;
    cena = p.cena;
    izracunata = p.izracunata;
}

void Posiljka::premesti(Posiljka& p)
{
    artikal = p.artikal;
    lista = p.lista;
    daniCekanja = p.daniCekanja;
    cena = p.cena;
    izracunata = p.izracunata;
}

Posiljka::Posiljka(const Posiljka& p)
{
    kopiraj(p);
}

Posiljka::Posiljka(Posiljka&& p)
{
    premesti(p);
}

Posiljka& Posiljka::operator=(const Posiljka& p)
{
    if (this != &p) {
        brisi();
        kopiraj(p);
    }
    return *this;
}

Posiljka& Posiljka::operator=(Posiljka&& p)
{
    if (this != &p) {
        brisi();
        premesti(p);
    }
    return *this;
}

Posiljka& Posiljka::operator+=(Rukovalac* r)
{
    if (izracunata) throw GrNoviRukovalac();
    lista += r;
    return *this;
}

Posiljka::~Posiljka()
{
    brisi();
}

void Posiljka::izracunajDetalje()
{
    for (int i = 0; i < lista.getBrElem(); i++)
        lista[i]->obradiPosiljku(this);
    izracunata = true;
}

int Posiljka::getDaniCekanja() const
{
    if (!izracunata) throw GrNijeIzracunato();
    return daniCekanja;
}

double Posiljka::getCena() const
{
    if (!izracunata) throw GrNijeIzracunato();
    return cena;
}
