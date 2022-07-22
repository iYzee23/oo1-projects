#ifndef _put_h_
#define _put_h_

#include "lista.h"
#include "tacka.h"

class Put {
private:
	Lista<Tacka> lista;
public:
	Put() = default;

	Put& operator+=(Tacka t);
	friend ostream& operator<<(ostream& os, const Put& p);
	double duzinaPuta() const;
};

#endif // !_put_h_