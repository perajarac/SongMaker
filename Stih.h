#ifndef _stih_h_
#define _stih_h_
#include "Rec.h"
class Stih
{
private:
	struct Elem {
		Rec data;
		Elem* next;
		Elem(Rec& r) : data(r), next(nullptr) {}
	};
	Elem* head = nullptr;
	Elem* tail = nullptr;

	void kopiraj(const Stih& s);
	void premesti(Stih& s);
	void isprazni();

public:
	Stih() = default;

	Stih(const Stih& s);
	Stih(Stih&& s);
	Stih& operator=(const Stih& s);
	Stih& operator=(Stih&& s);
	~Stih();

	Stih& operator+=(Rec& r);
	int operator+(); // racunanje duzine stiha
	int operator~(); // broj slogova u stihu
	Stih& operator()(int ind); // brisanje sa proizvoljne pozicije
	Rec operator[](int ind); // dohvatanje reci sa zadate pozicije
	Stih& operator()(Rec& r, int ind);

	friend bool operator^( Stih& s1,  Stih& s2);

	friend ostream& operator<<(ostream& it, const Stih& s);
	friend istream& operator>>(istream& it, Stih& s);

};

#endif