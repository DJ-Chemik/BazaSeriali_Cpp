#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Serial.h"
#include "Film.h"
#include "Live.h"
#include "Generic.h"

using namespace std;

class Pula
{
private:
	ListaGeneryczna<Produkcja*> produkcje;
		//przy usuwaniu elementów z listy generycznej PAMIÊTAJ ¿eby
		//usuwaæ najpierw obiekty na które wskazuj¹ te wskaŸniki!!!
	fstream Plik;
	void wczytaj_z_pliku(); //metoda wywo³ywana tylko w innych metodach w tej klasie
	void InsertSort(); // -||-
public:
	
	Pula(); 
	Pula(string nazwa_pliku);
	void operator+=(Produkcja* x);
	void operator-=(Produkcja* x);
	int size();
	Produkcja* operator[](int INDEKS); // zwraca element tego samego typu z którego zbudowana jest ListaGeneryczna
	void wypisz_pule();
	void zapisz_pule(string nazwa_pliku);
	void wyœwietl_statystyki();
	void sortuj_wg_oceny();
	void sortuj_wg_rankingu();
	virtual ~Pula();
};

