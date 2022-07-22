#include "oznaka.h"

ostream& operator<<(ostream& os, const VremenskaOznaka& v)
{
    os << v.dan << "." << v.mes << "." << v.god;
    return os << "-" << v.hh << "-" << v.mm;
}
