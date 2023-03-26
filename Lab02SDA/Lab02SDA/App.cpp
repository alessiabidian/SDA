#include "TestExtins.h"
#include "TestScurt.h"
#include "Dictionar.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "IteratorDictionar.h"
#include <iostream>
using namespace std;

/*
15. TAD Dictionar - reprezentare sub forma unei LSI cu perechi (cheie, valoare).
*/

void creeazaDictionar(Dictionar& dict)
{
	dict.adauga(1, 2);
	dict.adauga(2, 5);
	dict.adauga(3, 4);
	dict.adauga(4, 8);
	dict.adauga(5, 3);
	dict.adauga(6, 1);
	//dict.sterge(5);
	//dict.sterge(1);
	cout << dict.dim()<<endl;
}

void tiparesteDictionar(Dictionar& dict) {
	IteratorDictionar it = dict.iterator();
	
	while (it.valid2()) {
		cout << it.element2().first << ' ' << it.element2().second << endl;
		//it.urmator();
		it.anterior();
	}
}

void tiparesteKianpoi(Dictionar& dict) {
	IteratorDictionar it = dict.iterator();
	cout << endl;
	it.urmator();
	it.urmator();
	it.urmator();
	it.urmator();
	it.revinoKpasi(2);
	if(it.valid())
		cout << it.element().first << ' ' << it.element().second << endl;
		
}

int main() {
	testAll();
	testAllExtins();
	Dictionar dict;
	creeazaDictionar(dict);
	tiparesteDictionar(dict);
	tiparesteKianpoi(dict);
	cout << "That's all!" << endl;
	
	return 0;
}

