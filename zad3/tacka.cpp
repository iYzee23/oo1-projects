#include "tacka.h"

bool operator==(const Tacka& t1, const Tacka& t2)
{
    return (t1.x == t2.x) && (t1.y == t2.y);
}

ostream& operator<<(ostream& os, const Tacka& t)
{
    return os << "(" << t.x << "," << t.y << ")";
}

double rastojanje(const Tacka& t1, const Tacka& t2)
{
    return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2));
}
