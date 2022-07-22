#include "put.h"

Put& Put::operator+=(Tacka t)
{
    for (int i = 0; i < lista.getBrElem(); i++)
        if (lista[i] == t) throw GrTackaVecPostoji();
    lista += t;
    return *this;
}

double Put::duzinaPuta() const
{
    double sum = 0;
    for (int i = 0; i < lista.getBrElem() - 1; i++)
        sum += rastojanje(lista[i], lista[i + 1]);
    return sum;
}

ostream& operator<<(ostream& os, const Put& p)
{
    for (int i = 0; i < p.lista.getBrElem(); i++)
        os << p.lista[i] << endl;
    return os;
}
