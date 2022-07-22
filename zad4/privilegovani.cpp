#include "privilegovani.h"

void Privilegovani::pisi(ostream& os) const
{
	os << naziv << "(" << minVrednost << ")[";
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

Privilegovani& Privilegovani::dodaj(Igrac* igr, int i)
{
    if (igr->getVrednost() < minVrednost) throw GrBezvredanIgrac();
    Tim::dodaj(igr, i);
    return *this;
}
