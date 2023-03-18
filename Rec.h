#ifndef _rec_h_
#define _rec_h_
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Rec
{
private:

	int brSlogova = 0;
	string rec;
	string skupNS = "";

	//Pomocne metode za pronalazenje samoglasnika
	bool jeSamoglasnik(char c) const;
	void proveraR(const string& s, int& brSl, string& str, Rec& r) const;
	void proveraL(const string& s, int& brSl, string& str, Rec& r) const;
	void proveraN(const string& s, int& brSl, string& str, Rec& r) const;

public:
	Rec(string r);
	//Rec() = default;

	friend int operator~(Rec& r); //ako je za ovu metodu predvidjeno da bude clanica klase, a ne friend metoda, svuda u telu umesto r. treba this->
	int operator()(int n);
	int operator+();
	friend bool operator^(Rec& r1, Rec& r2);

	friend ostream& operator<<(ostream& it, const Rec& r);
	friend istream& operator>>(istream& it, Rec& r);

};
#endif