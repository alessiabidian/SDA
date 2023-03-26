#include "IteratorColectie.h"
#include "Colectie.h"
#include <exception>

using namespace std;

IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	//seteaza iteratorul pe prima pozitie din vector
	this->curent_index = 0;
	this->curent_frecventa = 1;
}
//theta(1)

void IteratorColectie::prim() {
	//resseteaza iteratorul pe prima pozitie din vector
	//curent = 0; -la fel ca mai sus
	this->curent_index = 0;
	this->curent_frecventa = 1;
}
//theta(1)

void IteratorColectie::urmator() {
	
	if (this->curent_index >= this->col.n)
		throw exception();
	else {
		if (this->curent_frecventa < this->col.f[this->curent_index])
			this->curent_frecventa++;
		else {
			this->curent_index++;
			this->curent_frecventa = 1;
		}
	}
}
//theta(1)

bool IteratorColectie::valid() const {
	//verifica daca iteratorul indica spre un element al vectorului
	//return curent < col.dim();
	if (this->curent_index >= this->col.n)
		return false;
	else
		return true;
}
//theta(1)

TElem IteratorColectie::element() const {
	//elementul curent
	//return col.e[curent];
	if (this->curent_index >= this->col.n)
		throw exception();
	return this->col.e[this->curent_index];
}
//theta(1)

//pt frecventa -- in plus
TElem IteratorColectie::frecventa() const {
	if (this->curent_index >= this->col.n)
		throw exception();
	return this->col.f[this->curent_index];
}
//theta(1)