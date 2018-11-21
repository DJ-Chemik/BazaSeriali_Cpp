#include "stdafx.h"
#include "Live.h"


Live::Live(string TYTU£) : Produkcja(TYTU£)
{
	
}

Live::Live(string TYTU£, int OCENA) : Produkcja(TYTU£, OCENA)
{
}

Live::Live(string TYTU£, int OCENA, int TOP100) : Produkcja(TYTU£, OCENA, TOP100)
{

}



void Live::set_day(int day)
{
	if (day > 0 && day < 8)
		emission_day = day;
	else cout << "Niepoprawny zakres\n"; 
}

int Live::get_day()
{
	cout << "Czy wyœwietliæ ci nazwê tego dnia?\n";
	cout << "[1] -TAK\n[2] - NIE\n";
	int decision;
	cin >> decision;
	while ((decision != 1) && (decision != 2))
	{
		cout << "Wpisz 1 lub 2 i kliknij ENTER\n";
		cin >> decision;
	}

	
	if (decision == 1)
		cout <<"Dzien emisji tego wydarzenia to: "<< tab[emission_day - 1]<<"\n";
	return emission_day;
	
	
}

void Live::set_hour(int hour)
{
	if (hour >= 0 && hour < 24)
		emission_hour = hour;
	//else cout << "Niepoprawny zakres\n";
}

int Live::get_hour()
{
	return emission_hour;
}

void Live::set_przypomnienie(int rem)
{
	if (rem>=0)
		ile_wczeœniej_przypomnieæ = rem;
	else cout << "Podaj liczbe naturalna!\n";
}

int Live::get_przypomnienie()
{

	return ile_wczeœniej_przypomnieæ;
}

void Live::wypisz_produkcje_na_ekran()
{
	Produkcja::wypisz_produkcje_na_ekran();
	//wypisywanie danych o dniu emisji
	{
		cout << "\tDzien emisji: ";
		if (emission_day >= 0)
			cout << tab[emission_day - 1] << "\n";
		else cout << "---\n";
	}
	//Wypisywanie danych o godzinie emisji
	{
		cout << "\tGodzina emisji: ";
		if (emission_hour >= 0)
			cout << emission_hour << ":00\n";
		else cout << "---\n";
	}	
	//wypisywanie danych o przypomnieniu
	{
		cout << "\tPrzypomnienie: ";
		if (ile_wczeœniej_przypomnieæ)
			cout << ile_wczeœniej_przypomnieæ << "h przed wydarzeniem\n";
		else cout << "---\n";
	}
	cout << "\tTyp produkcji: Wydarzenie na zywo\n";
}

void Live::przypomnij_o_wydarzeniu()
{
	
	int a = emission_hour - ile_wczeœniej_przypomnieæ;
	int d = emission_hour;
	while (a<0)
	{
		if (d > 1)
			d = d - 1;
		else d = 7; //zmiana modulo z poniedzia³ku na niedziele

		a = a + 24; //godzina w poprzednim dniu
	}

	cout << "Przypomnienie ustawione jest na: " << tab[d - 1] << " o godzinie: " << a << endl;
}

string Live::make_rekord_bazy_danych()
{
	string wynikowy, tmp;
	wynikowy = "2\t";	//najpierw przypisanie identyfikatora klasy [Film: 0, Serial: 1, Live: 2] ¿eby przy wczytywaniu wiedzieæ jakiej klasy obiekt utworzyæ
	wynikowy += Produkcja::make_rekord_bazy_danych(); // dodaje parametry które ma ka¿da produkcja

													  
	//dopisujemy typowe dla danej klasy parametry i koñczymy rekord (wiemy juz wsyztsko o tym obiekcie)
	tmp = IntToStr(emission_day) + "\t" + IntToStr(emission_hour) + "\t" + IntToStr(ile_wczeœniej_przypomnieæ) + "\n";
	
	wynikowy += tmp;
	return wynikowy;
}

Live::~Live()
{
}
