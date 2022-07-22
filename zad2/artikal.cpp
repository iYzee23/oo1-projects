#include "artikal.h"

bool operator==(const Artikal& a1, const Artikal& a2)
{
    return a1.barKod == a2.barKod;
}

bool operator!=(const Artikal& a1, const Artikal& a2)
{
    return !(a1 == a2);
}
