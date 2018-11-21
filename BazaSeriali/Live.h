#pragma once
#include "Produkcja.h"
#include <iostream>
#include <string>
using namespace std;

class Live :
	public Produkcja
{
private:
	int emission_day = -1;
	int emission_hour = -1;
	int ile_wczeœniej_przypomnieæ = 0; //w godzinach //domyœlnie brak przypomnienia
	
public:
	Live(string TYTU£);
	Live(string TYTU£, int OCENA);
	Live(string TYTU£, int OCENA, int TOP100);
	void set_day(int day);
	int get_day();
	void set_hour(int hour);
	int get_hour();
	void set_przypomnienie(int rem);
	int get_przypomnienie();
	void wypisz_produkcje_na_ekran();
	void przypomnij_o_wydarzeniu();
	string make_rekord_bazy_danych();
	virtual ~Live();
};

