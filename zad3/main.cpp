#include "vozilo.h"

int main() {
	{
		try {
			Put p;
			p += Tacka(0, 0);
			p += Tacka(-1, -1);
			p += Tacka(2, 2);
			p += Tacka(-3, 4);
			p += Tacka(5, -7);
			cout << p.duzinaPuta() << endl;
			cout << p << endl;

			Vozilo* v = new Obicno("Ferrari");
			cout << *v << endl;
			cout << v->cenaPrevoza(p) << endl;
			delete v;
		}
		catch (exception& e) {
			cout << e.what();
			cout << endl;
		}
	}
	_CrtDumpMemoryLeaks();
}