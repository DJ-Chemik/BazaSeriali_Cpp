#include "stdafx.h"
#include "Film.h"


Film::Film(string TYTU£) : Produkcja(TYTU£)
{
	d³ugoœæ = 0;
}

Film::Film(string TYTU£, int OCENA) : Produkcja(TYTU£, OCENA)
{
	d³ugoœæ = 0;
}

Film::Film(string TYTU£, int OCENA, int TOP100) : 
	Produkcja(TYTU£, OCENA, TOP100)
{	
	d³ugoœæ = 0; //
}

Film::Film(string TYTU£, int OCENA, int TOP100, int D£UGOSC) :
	Produkcja(TYTU£, OCENA, TOP100),
	d³ugoœæ(D£UGOSC)
{

}

void Film::set_d³ugoœæ(int D£UGOSC)
{
	d³ugoœæ = D£UGOSC;
}

int Film::get_d³ugoœæ()
{
	return d³ugoœæ;
}

void Film::wypisz_produkcje_na_ekran()
{
	Produkcja::wypisz_produkcje_na_ekran();
	cout << "\tFilm trwa: ";
	if (d³ugoœæ)
		cout << (this->d³ugoœæ)/60<<"h "<<(this->d³ugoœæ) % 60 <<"min\n";
	else cout << "---\n";
	cout << "\tTyp produkcji: Film\n";

	
}

string Film::make_rekord_bazy_danych()
{
	string wynikowy;
	wynikowy = "0\t";	//najpierw przypisanie identyfikatora klasy [Film: 0, Serial: 1, Live: 2] ¿eby przy wczytywaniu wiedzieæ jakiej klasy obiekt utworzyæ
	wynikowy.append(Produkcja::make_rekord_bazy_danych());	 // dodaje parametry które ma ka¿da produkcja
	
	wynikowy += IntToStr(d³ugoœæ) + "\n"; //dopisujemy typowe dla danej klasy parametry i koñczymy rekord (wiemy juz wsyztsko o tym obiekcie)
	return wynikowy;
}

Film::~Film()
{
}
