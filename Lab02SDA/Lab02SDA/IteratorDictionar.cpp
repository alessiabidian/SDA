#include "IteratorDictionar.h"
#include "Dictionar.h"
#include <exception>
#include <iostream>

using namespace std;

IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d) {
	/* de adaugat */
	curent = dict.prim;
	curent2 = dict.ultim;
}
//theta(1)

void IteratorDictionar::prim() {
	/* de adaugat */
	curent = dict.prim;
	curent2 = dict.ultim;
}
//theta(1)

void IteratorDictionar::urmator() {
	/* de adaugat */
	//if (curent->urmator() == nullptr)
	if(curent == nullptr)
		throw exception();
	else
		curent = curent->urmator();
}
//theta(1)

TElem IteratorDictionar::element() const {
	/* de adaugat */
	//return pair <TCheie, TValoare>  (-1, -1);
	if (curent == nullptr)
		throw exception();
	else
		return curent->element();
}


bool IteratorDictionar::valid() const {
	/* de adaugat */
	//return false;
	return curent != nullptr;
}

//in plus
bool IteratorDictionar::valid2() const {
	/* de adaugat */
	//return false;
	return curent2 != nullptr;
}

TElem IteratorDictionar::element2() const {
	/* de adaugat */
	//return pair <TCheie, TValoare>  (-1, -1);
	if (curent2 == nullptr)
		throw exception();
	else
		return curent2->element();
}

void IteratorDictionar::anterior()
{
	if (curent2 == nullptr)
	{
		throw exception();
	}
	if (curent2 == dict.prim)
	{
		curent2 = nullptr;
	}
	else {
		PNod p = dict.prim;
		while (p->urmator() != nullptr && !(p->urmator() == curent2))
		{
			p = p->urmator();
		}
		curent2 = p;
	}
}
//Caz favorabil:theta(1), Caz Defavorabil:theta(n) - cand curent2 e pe ultimul element, Caz Mediu:theta(n)
//n - nr de perechi din dictionar

void IteratorDictionar::anterior2()
{
	if (curent == nullptr)
	{
		throw exception();
	}
	if (curent == dict.prim)
	{
		curent = nullptr;
	}
	else {
		PNod p = dict.prim;
		while (p->urmator() != nullptr && !(p->urmator() == curent))
		{
			p = p->urmator();
		}
		curent = p;
	}
}

void IteratorDictionar::revinoKpasi(int k)
{
	if (curent == nullptr || k<=0)
	{
		throw exception();
	}

	PNod p = dict.prim;
	int cont = 1;
	while (p->urmator() != nullptr && p->urmator() != curent)
	{
		p = p->urmator();
		cont++;
	}

	if (curent == dict.prim || cont < k)
	{
		curent = nullptr;
	}
	else {
		while (k != 0)
		{
			anterior2();
			k--;
		}
	}
}
//Complexitati: Caz favorabil: theta(1), Defavorabil: theta(n^2), total: O(n^2)
	//daca curent not valid sau k <= 0
	//		arunca exceptie
	// Nod nou p = prim
	// cat timp [p].urmator != nil si != curent
	//		p<-[p].urmator 
	//		cont++
	//if curent == prim sau cont < k
	//		curent <- nil
	// altfel
	//		cat timp k!=0
	//			curent<-anterior
	//			k<-k-1
