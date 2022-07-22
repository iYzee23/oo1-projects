#ifndef _par_h_
#define _par_h_

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template<typename T>
class Par {
private:
	T* t1;
	T* t2;
public:
	Par(T* t1, T* t2) : t1(t1), t2(t2) {}

	friend bool operator==(const Par& p1, const Par& p2) {
		if ((p1.t1 && !p2.t1) || (!p1.t1 && p2.t1)) return false;
		else if ((p1.t2 && !p2.t2) || (!p1.t2 && p2.t2)) return false;
		else if (p1.t1 && p2.t1 && !(*p1.t1 == *p2.t1)) return false;
		else if (p1.t2 && p2.t2 && !(*p1.t2 == *p2.t2)) return false;
		else return true;
	}
	friend bool operator!=(const Par& p1, const Par& p2) {
		return !(p1 == p2);
	}
	friend ostream& operator<<(ostream& os, const Par& p) {
		return os << "[" << *p.t1 << "-" << *p.t2 << "]";
	}

	T* getPrviPok() { return t1; }
	const T* getPrviPok() const { return t1; }
	T* getDrugiPok() { return t2; }
	const T* getDrugiPok() const { return t2; }
	void setPrviPok(T* t1) { this->t1 = t1; }
	void setDrugiPok(T* t2) { this->t2 = t2; }
};

#endif // !_par_h_