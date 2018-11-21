#pragma once
#include "Produkcja.h"
#include <string>
#include <iostream>
using namespace std;

class Serial :
	public Produkcja
{
private:
	int czas_trwania_odcinka; //w minutach
	int emission_day;
	bool czy_œledzony;
public:
	Serial(string TYTU£);
	Serial(string TYTU£, int OCENA);
	Serial(string TYTU£, int OCENA, int TOP100);
	void set_day(int day);
	int get_day();
	void set_czas_odcinka(int d³ugoœæ);
	int get_czas_odcinka();
	bool czy_jest_œledzony();
	void zacznij_œledziæ();
	void przestañ_œledziæ();
	void wypisz_produkcje_na_ekran();
	string make_rekord_bazy_danych();
	virtual ~Serial();
};

