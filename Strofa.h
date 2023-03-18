#ifndef _strofa_h_
#define _strofa_h_
#include "Stih.h"

class Strofa
{
protected:
	struct Elem {
		Stih data;
		Elem* next;
		Elem(Stih& s) : data(s), next(nullptr) {}
		~Elem() { ~data; }
	};
	Elem* head = nullptr;
	Elem* tail = nullptr;

	void kopiraj(const Strofa& s);
	void premesti(Strofa& s);
	void isprazni();

	void umanji();
	void povecaj();
	int kap;
	int pom; //treutno slobodnih mesta

public:
	Strofa(int kk) : kap(kk) { pom = kap; }

	int dohvKapacitet() const { return kap; }

	Strofa(const Strofa & s);
	Strofa(Strofa&& s);
	Strofa& operator=(const Strofa& s);
	Strofa& operator=(Strofa&& s);
	~Strofa();

	Strofa& operator+=(Stih s); //dodaje stih
	void operator-(); //uklanja stih sa kraja
	int operator+(); //duzina stiha
	Stih operator[](int ind); // dohvatanje stiha sa zadate pozicije
	void operator()(int i, int j); //rotira elemente zadatih indeksa
	virtual bool operator*() const = 0;
	virtual char oznaka() const = 0;

	friend ostream& operator<<(ostream& it, const Strofa& s);
};
#endif