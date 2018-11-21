#pragma once

#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class Produkcja
{
private:
	string tytu�;
	int ocena = 0; //standardowo brak oceny
	int miejsce_w_TOP100 = 0; //standardowo brak w rankingu


public:

	const string tab[7] = { "Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela" };

	Produkcja(string TYTU�);
	Produkcja(string TYTU�, int OCENA);
	Produkcja(string TYTU�, int OCENA, int TOP100);


	void set_tytu�(string TYTU�);
	string get_tytu�();
	void set_ocena(int OCENA);
	int get_ocena();
	void set_ranking(int RANK);
	int get_ranking();
	virtual void wypisz_produkcje_na_ekran(); //polimorfizm
	bool operator==(Produkcja x); //do por�wnywania czy 2 produkcje to ta sama produkcja
	virtual string make_rekord_bazy_danych(); //polimorfizm
	string IntToStr(int n);
	
	virtual void set_d�ugo��(int D�UGOSC) {};
	virtual int get_d�ugo��() { return 0; };

	virtual void set_day(int x) {};
	virtual int get_day() { return 0; };
	virtual void set_czas_odcinka(int x) {};
	virtual int get_czas_odcinka() { return 0; };
	virtual bool czy_jest_�ledzony() { return false; };
	virtual void zacznij_�ledzi�() {};
	virtual void przesta�_�ledzic() {};
	//virtual bool czy_jest_�ledzony() { return false; };

	virtual void set_hour(int x) {};
	virtual int get_hour() { return 0; };
	virtual void set_przypomnienie(int x) {};
	virtual int get_przypomnienie() { return 0; };
	virtual void przypomnij_o_wydarzeniu() {};

	virtual ~Produkcja();

};

