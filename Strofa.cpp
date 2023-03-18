#include "Strofa.h"

void Strofa::kopiraj(const Strofa& s)
{
	head = tail = nullptr;
	for (Elem* curr = s.head; curr; curr = curr->next) {
		Elem* n = new Elem(curr->data);
		tail = (!head ? head : tail->next) = n;
	}
}

void Strofa::premesti(Strofa& s)
{
	head = s.head;
	tail = s.tail;
	s.head = s.tail = nullptr;
}

void Strofa::isprazni()
{
	while (head) {
		Elem* old = head;
		head = head->next;
		delete old;
	}
	tail = nullptr;
}

void Strofa::umanji()
{
	this->pom--;
}

void Strofa::povecaj()
{
	this->pom++;
}

Strofa::Strofa(const Strofa& s)
{
	kopiraj(s);
}

Strofa::Strofa(Strofa&& s)
{
	premesti(s);
}

Strofa& Strofa::operator=(const Strofa& s)
{
	if (this != &s) { isprazni(); kopiraj(s); }
	return *this;
}

Strofa& Strofa::operator=(Strofa&& s)
{
	if (this != &s) { isprazni(); premesti(s); }
	return *this;
}

Strofa::~Strofa()
{
	isprazni();
}

Strofa& Strofa::operator+=(Stih s)
{
	Elem* k = new Elem(s);
	bool pomocna = true;

	for (Elem* curr = head; curr; curr = curr->next) {
		if ((~k->data) != (~curr->data)) pomocna = false;
	}

	if (this->pom != 0 && pomocna) {
		this->umanji();
		tail = (!head ? head : tail->next) = k;
		return *this;
	}else return *this;
}

void Strofa::operator-() {
	// Ako lista ima samo jedan element, obrisi ga i postavi pokazivac head i tail na nullptr
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}

	// Pronadji prethodni element
	Elem* current = head;
	while (current->next != tail) {
		current = current->next;
	}

	// Obrisi posljednji element i postavi pokazivac tail na prethodni element
	delete current->next;
	current->next = nullptr;
	tail = current;
	this->povecaj();
}

int Strofa::operator+()
{
	int i = 0;
	for (Elem* curr = this->head; curr; curr = curr->next) {
		i++;
	}
	return i;
}

Stih Strofa::operator[](int ind)
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

ostream& operator<<(ostream& it, const Strofa& s)
{
	for (Strofa::Elem* curr = s.head; curr; curr = curr->next) {
		it << curr->data << endl;
	}
	return it;
}

void Strofa::operator()(int i, int j) {
	if (i < 0 || j < 0 || i == j) return; 

	Elem* curr = head;
	Elem* prev = nullptr;
	Elem* prev_i = nullptr;
	Elem* prev_j = nullptr;
	Elem* i_elem = nullptr;
	Elem* j_elem = nullptr;
	int idx = 0;

	while (curr) {
		if (idx == i) {
			prev_i = prev;
			i_elem = curr;
		}
		else if (idx == j) {
			prev_j = prev;
			j_elem = curr;
		}

		prev = curr;
		curr = curr->next;
		idx++;
	}

	if (!i_elem || !j_elem) return; 

	if (!prev_i) head = j_elem;
	else prev_i->next = j_elem;

	if (!prev_j) head = i_elem; 
	else prev_j->next = i_elem;

	swap(i_elem->next, j_elem->next);

	// rotacija poslednja dva
	if (!i_elem->next && !j_elem->next) {
		tail = j_elem;
		j_elem->next = i_elem;
		i_elem->next = nullptr;
	}
	else if (!i_elem->next) {
		tail = i_elem;
	}
	else if (!j_elem->next) {
		tail = j_elem;
	}
}