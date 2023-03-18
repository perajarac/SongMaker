#include "Stih.h"

void Stih::kopiraj(const Stih& s)
{
	head = tail = nullptr;
	for (Elem* curr = s.head; curr; curr = curr->next) {
		Elem* n = new Elem(curr->data);
		tail = (!head ? head : tail->next) = n;
	}
}

void Stih::premesti(Stih& s)
{
	head = s.head;
	tail = s.tail;
	s.head = s.tail = nullptr;
}

void Stih::isprazni()
{
	while (head) {
		Elem* old = head;
		head = head->next;
		delete old; 
	}
	tail = nullptr;
}

Stih::Stih(const Stih& s)
{
	kopiraj(s);
}

Stih::Stih(Stih&& s)
{
	premesti(s);
}

Stih& Stih::operator=(const Stih& s) 
{
	if (this != &s) { isprazni(); kopiraj(s); }
	return *this;
}

Stih& Stih::operator=(Stih&& s)
{
	if (this != &s) { isprazni(); premesti(s); }
	return *this;
}

Stih::~Stih()
{
	isprazni();
}

Stih& Stih::operator+=(Rec& r)
{
	tail = (!head ? head : tail->next) = new Elem(r);
	return *this;
}

int Stih::operator+()
{
	int i = 0;
	for (Stih::Elem* curr = this->head; curr; curr = curr->next) {
		i++;
	}
	return i;
}

int Stih::operator~()
{
	int i = 0;
	for (Stih::Elem* curr = this->head; curr; curr = curr->next) {
		int k = ~curr->data;
		i += k;
	}
	return i;
}

Stih& Stih::operator()(int ind)
{
	int a = 0;
	for (Stih::Elem* curr = this->head; curr; curr = curr->next) {
		a++;
	}
	if (a < ind) return *this;

	if (!head) return *this;
	int br = 0;
	Elem* temp = head;
	Elem* curr = head->next;
	if (ind == 0) {
		head = curr;
		delete temp;
	}
	else {
		while (curr && br < ind - 1) {
			temp = curr;
			curr = curr->next;
			br++;
		}
		if (!curr)
			return *this;

		temp->next = curr->next;
		delete curr;
	}
	return *this;
}

Rec Stih::operator[](int ind)
{
	int a = +*this;
	
	if (a > ind) {	

		Elem* curr = this->head;

		for (int k = 0; k < ind; k++) {
			if (k == ind) break;
			curr = curr->next;
		}

		return curr->data;
	}
}

Stih& Stih::operator()(Rec& r, int ind)
{
	if (!head) return *this;
	if (+*this == 1 && ind == 1) {
		*this += r;
		return *this;
	}

	if (ind == 0) {
		Elem* curr = new Elem(r);
		curr->next = head;
		head = curr;
		return *this;
	}
	// Pronadji element koji ce biti prethodnik elementa koji se umece
	Elem* curr = head;
	for (int i = 0; i < ind- 1; i++) {
		curr = curr->next;
	}
	// Kreiraj novi element i postavi pokazivace
	Elem* newNode = new Elem(r);
	newNode->next = curr->next;
	curr->next = newNode;
	return *this;

}

bool operator^(Stih& s1,Stih& s2)
{
	if (!s1.head || !s2.head) return false;

	int a = +s1;
	int b = +s2;

	Rec r1 = s1[a - 1];
	Rec r2 = s2[b - 1];

	return r1^r2;

}

ostream& operator<<(ostream& it, const Stih& s)
{
	for (Stih::Elem* curr = s.head; curr; curr = curr->next) {
		it << curr->data << " ";
	}
	return it;
}

istream& operator>>(istream& it, Stih& s)
{
	string str;
	getline(it, str);
	str += " ";
	string rec = "";
	for (auto x : str)
	{
		if (x == ' ')
		{
			Rec temp(rec);
			s += temp;
			rec = "";
		}
		else {
			rec = rec + x;
		}
	}

	return it;
}