#include "Rec.h"

bool Rec::jeSamoglasnik(char c) const {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void Rec:: proveraR(const string& s, int& brSl, string& str, Rec& r) const {
	for (int i = 0; i < s.size(); i++) {
		// Proveri da li je trenutni karakter r
		if (s[i] == 'r' || s[i] == 'R') {
			// Proveri da li je samoglasnik iza ili ispred slova
			if ((i == 0 || !r.jeSamoglasnik(s[i - 1])) && (i == s.size() - 1 || !r.jeSamoglasnik(s[i + 1]))) {
				brSl++;
				str += to_string(i) + " ";
			}
		}
	}
	return;
}

void Rec::proveraL(const string& s, int& brSl, string& str, Rec& r) const {
	for (int i = 0; i < s.size(); i++) {
		// Proveri da li je trenutni karakter r
		if ((s[i] == 'l' || s[i] == 'L' )&& s[i+1]!= 'j' ) {
			// Proveri da li je samoglasnik iza ili ispred slova
			if ((i == 0 || !r.jeSamoglasnik(s[i - 1])) && (i == s.size() - 1 || !r.jeSamoglasnik(s[i + 1]))) {
				brSl++;
				str += to_string(i) + " ";
			}
		}
	}
	return;
}

void Rec::proveraN(const string& s, int& brSl, string& str, Rec& r) const {
	for (int i = 0; i < s.size(); i++) {
		// Proveri da li je trenutni karakter r
		if ((s[i] == 'n' || s[i] == 'N') && s[i + 1] != 'j') {
			// Proveri da li je samoglasnik iza ili ispred slova
			if ((i == 0 || !r.jeSamoglasnik(s[i - 1])) && (i == s.size() - 1 || !r.jeSamoglasnik(s[i + 1]))) {
				brSl++;
				str += to_string(i) + " ";
			}
		}
	}
	return;
}

Rec::Rec(string r)
{
	for (char c : r) {
		if (isalpha(c)) {
			rec += c;
		}
	}
}

int Rec::operator()(int m)
{
	if (this->skupNS == "") {
		~(*this);
	}
	stringstream ss(this->skupNS); // kreiranje stringstream objekta od stringa
	string item;
	int i = 0;
	int* arr = new int[100];
	while (getline(ss, item, ' ')) {
		arr[i++] = stoi(item);
	}
	int n = i;

	for (i = 1; i < n; i++) {
		int value = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > value) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = value;
	}

	if (m > this->brSlogova || -m > this->brSlogova) return -1;

	if (m < 0) return arr[m + i];
	else return arr[m];

}

int operator~(Rec& r)
{
	if (r.skupNS != "") {
		r.skupNS = "";
		r.brSlogova = 0;
	}
	int i = 0;
	int brSl = 0;
	for (char c : r.rec) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
			brSl++;
 			r.skupNS += to_string(i)+ " ";
		}
		i++;
	}
	r.proveraR(r.rec, brSl, r.skupNS, r);
	r.proveraL(r.rec, brSl, r.skupNS, r);
	r.proveraN(r.rec, brSl, r.skupNS, r);
	r.brSlogova = brSl;
	return brSl;
}

int Rec::operator+()
{
	return this->rec.size();
}

bool operator^(Rec& r1, Rec& r2)
{
	int duzinaR1 = ~r1;
	int duzinaR2 = ~r2;
	bool rimuje = false;
	char c1 = r1.rec[r1(-2)];
	char c2 = r2.rec[r2(-2)];

	if (duzinaR1 >= 2 && duzinaR2 >= 2) {
		if ((r1.rec[r1(-2)] == r2.rec[r2(-2)]) && (r1.rec[r1(-1)] == r2.rec[r2(-1)])) {
			rimuje = true;
			return rimuje;
		}
	}
	else if (r1.rec[r1(-1)] == r2.rec[r2(-1)]) { rimuje = true; return rimuje; }
	
	return false;
	
}

ostream& operator<<(ostream& it, const Rec& r)
{
	return it << r.rec;
}

istream& operator>>(istream& it, Rec& r)
{
	string s;
	it >> s;
	r = Rec(s);
	return it;
}
