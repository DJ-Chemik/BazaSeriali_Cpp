#include "stdafx.h"
#include "Serial.h"
#include "Live.h"

Serial::Serial(string TYTU�) : Produkcja(TYTU�)
{
	czas_trwania_odcinka = 0;
	emission_day = -1;
	czy_�ledzony = false;
}

Serial::Serial(string TYTU�, int OCENA) : Produkcja::Produkcja(TYTU�, OCENA)
{
	czas_trwania_odcinka = 0;
	emission_day = -1;
	czy_�ledzony = false;
}

Serial::Serial(string TYTU�, int OCENA, int TOP100) : Produkcja::Produkcja(TYTU�, OCENA, TOP100)
{
	czas_trwania_odcinka = 0;
	emission_day = -1;
	czy_�ledzony = false;
}

void Serial::set_day(int day)
{
	if (day > 0 && day < 8)
		emission_day = day;
	//else cout << "Niepoprawny zakres\n";
}

int Serial::get_day()
{
	cout << "Czy wy�wietli� ci nazw� tego dnia?\n";
	cout << "[1] -TAK\n[2] - NIE\n";
	int decision;
	cin >> decision;
	while ((decision != 1) && (decision != 2))
	{
		cout << "Wpisz 1 lub 2 i kliknij ENTER\n";
		cin >> decision;
	}


	if (decision == 1)
		cout << "Dzien emisji tego serialu to: " << tab[emission_day - 1] << "\n";
	return emission_day;
}

void Serial::set_czas_odcinka(int d�ugo��)
{
	czas_trwania_odcinka = d�ugo��;
}

int Serial::get_czas_odcinka()
{
	return czas_trwania_odcinka;
}

bool Serial::czy_jest_�ledzony()
{
	return czy_�ledzony;
}

void Serial::zacznij_�ledzi�()
{
	if (czy_�ledzony == false)
	{
		//cout << "Zaczeto sledzic ten serial\n";
		czy_�ledzony = true;
	}
	else cout << "Juz sledzisz ten serial\n";
	
}

void Serial::przesta�_�ledzi�()
{
	if (czy_�ledzony == true)
	{
		cout << "Przestano sledzic ten serial\n";
		czy_�ledzony = false;
	}
	else cout << "Serial nie byl sledzony\n";
	
}

void Serial::wypisz_produkcje_na_ekran()
{
	Produkcja::wypisz_produkcje_na_ekran();
	//Wypisywanie danych o d�ugo�ci odcinka
	{
	cout << "\tDlugosc odcinka: ";
	if (czas_trwania_odcinka >= 60)
		cout << (czas_trwania_odcinka / 60) << "h " << czas_trwania_odcinka % 60 << "min\n";
	else if (czas_trwania_odcinka != 0)
		cout << czas_trwania_odcinka << "min\n";
	else cout << "---\n";
	}
	//wypisywanie danych o dniu emisji
	{
		cout << "\tDzien emisji: ";
		if (emission_day >= 0)
			cout << tab[emission_day - 1] << "\n";
		else cout << "---\n";
	}
	//wypisywanie danych o �ledzeniu
	{
		cout << "\tSledzony?: ";
		if (czy_�ledzony)
			cout << "TAK\n";
		else cout << "NIE\n";
	}
	cout << "\tTyp produkcji: Serial\n";
}



string Serial::make_rekord_bazy_danych()
{
	string wynikowy ,tmp,tmp1,tmp2,tmp3;
	wynikowy = "1\t";	//najpierw przypisanie identyfikatora klasy [Film: 0, Serial: 1, Live: 2] �eby przy wczytywaniu wiedzie� jakiej klasy obiekt utworzy�
	wynikowy += Produkcja::make_rekord_bazy_danych(); // dodaje parametry kt�re ma ka�da produkcja
											
	//dopisujemy typowe dla danej klasy parametry i ko�czymy rekord (wiemy juz wsyztsko o tym obiekcie)
	tmp = IntToStr(czas_trwania_odcinka) + "\t" + IntToStr(emission_day) + "\t" + IntToStr(czy_�ledzony) + "\n";
	
	wynikowy += tmp;
	return wynikowy;
}

Serial::~Serial()
{
}
