#include "poruka.h"

void ElPoruka::pisi(ostream& os) const
{
	os << naslov << endl;
	os << *posiljalac << endl;
	os << *primalac << endl;
}

ostream& operator<<(ostream& os, const ElPoruka& e)
{
	e.pisi(os);
	return os;
}
