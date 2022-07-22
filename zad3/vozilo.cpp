#include "vozilo.h"

void Vozilo::pisi(ostream& os) const
{
    os << nazivModela;
}

double Vozilo::cenaPrevoza(const Put& p) const
{
    return startnaCena() + p.duzinaPuta() * 0.1;
}

ostream& operator<<(ostream& os, const Vozilo& v)
{
    v.pisi(os);
    return os;
}
