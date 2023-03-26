#pragma once
#define MAX 13 //numarul maxim de locatii din tabela

#define NULL_TELEM -1
typedef int TElem;

class IteratorColectie;

class Colectie
{
	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
	//reprezentare folosind o TD - rezolvare coliziuni prin adresare deschisa si dispersie dubla
	//int m; //numarul de locatii din tabela de dispersie
	//TElem e[MAX]; //vectorul elementelor - vector dinamic
	TElem* e;
	// functia de dispersie extinsa 
	int d(TElem e, int i);
	void redim();

public:
	int m; //numarul de locatii din tabela de dispersie

	//constructorul implicit
	Colectie();

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	//bool cauta(TElem elem) const;
	bool cauta(TElem elem);

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;

	//adauga aparitii multiple, arunca exceptie pt nr negativ
	void adaugaAparitiiMultiple(int nr, TElem elem);

	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();

};
