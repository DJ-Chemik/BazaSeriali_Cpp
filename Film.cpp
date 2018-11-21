#include "stdafx.h"
#include "Film.h"


Film::Film(string TYTU�) : Produkcja(TYTU�)
{
	d�ugo�� = 0;
}

Film::Film(string TYTU�, int OCENA) : Produkcja(TYTU�, OCENA)
{
	d�ugo�� = 0;
}

Film::Film(string TYTU�, int OCENA, int TOP100) : 
	Produkcja(TYTU�, OCENA, TOP100)
{	
	d�ugo�� = 0; //
}

Film::Film(string TYTU�, int OCENA, int TOP100, int D�UGOSC) :
	Produkcja(TYTU�, OCENA, TOP100),
	d�ugo��(D�UGOSC)
{

}

void Film::set_d�ugo��(int D�UGOSC)
{
	d�ugo�� = D�UGOSC;
}

int Film::get_d�ugo��()
{
	return d�ugo��;
}

void Film::wypisz_produkcje_na_ekran()
{
	Produkcja::wypisz_produkcje_na_ekran();
	cout << "\tFilm trwa: ";
	if (d�ugo��)
		cout << (this->d�ugo��)/60<<"h "<<(this->d�ugo��) % 60 <<"min\n";
	else cout << "---\n";
	cout << "\tTyp produkcji: Film\n";

	
}

string Film::make_rekord_bazy_danych()
{
	string wynikowy;
	wynikowy = "0\t";	//najpierw przypisanie identyfikatora klasy [Film: 0, Serial: 1, Live: 2] �eby przy wczytywaniu wiedzie� jakiej klasy obiekt utworzy�
	wynikowy.append(Produkcja::make_rekord_bazy_danych());	 // dodaje parametry kt�re ma ka�da produkcja
	
	wynikowy += IntToStr(d�ugo��) + "\n"; //dopisujemy typowe dla danej klasy parametry i ko�czymy rekord (wiemy juz wsyztsko o tym obiekcie)
	return wynikowy;
}

Film::~Film()
{
}
