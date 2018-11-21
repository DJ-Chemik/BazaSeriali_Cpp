#pragma once
#include "Produkcja.h"
#include <string>

using namespace std;

class Film :
	public Produkcja
{
private:
	int d³ugoœæ; //w minutach

public:
	Film(string TYTU£);
	Film(string TYTU£, int OCENA);
	Film(string TYTU£, int OCENA, int TOP100);
	Film(string TYTU£, int OCENA, int TOP100, int D£UGOSC);
	void set_d³ugoœæ(int D£UGOSC);
	int get_d³ugoœæ();
	void wypisz_produkcje_na_ekran();
	string make_rekord_bazy_danych();
	virtual ~Film();

};

