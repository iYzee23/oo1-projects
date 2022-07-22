#include "mec.h"
#include "privilegovani.h"

int main() {
	{
		try {
			Igrac i1("Pedja", 900);
			Igrac i2("Milica", 1100);
			Igrac i3("Luka", 1200);
			Igrac i4("Marija", 1300);

			Tim t1("MG", 5);
			Tim t2("ETS", 10);

			t1.dodaj(&i3, 2); t1.dodaj(&i4, 3);
			t2.dodaj(&i1, 5); t2.dodaj(&i2, 1);

			Mec m(&t1, &t2);
			m.odigrajMec();
			cout << m << endl;
		}
		catch (exception& e) {
			cout << e.what();
			cout << endl;
		}
	}
	_CrtDumpMemoryLeaks();
}