#include "korisnik.h"

ostream& operator<<(ostream& os, const Korisnik& k)
{
	return os << "(" << k.ime << ")" << k.email;
}
