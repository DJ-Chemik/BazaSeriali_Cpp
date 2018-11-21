#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Pula.h"
using namespace std;

class Menu
{
private:
	int decyzja_z_zakresu(int Od, int Do); //metoda do podejmowania decyzji z pewnego zakresu, zwraca wybran� (PRAWID�OW�) warto��

public:
	Menu();

	void komunikat_powitalny();
	Pula* pytanie_o_nazw�_pliku_do_wczytywania_puli();
	void clear_console();

	int menu__g��wne();
	void menu_0_dodaj_produkcje(Pula* pula); //wywo�ywane poprzez 0 zwracane z menu g��wnego
	void menu_1_usun_produkcje(Pula* pula);	//wywo�ywane poprzez 1 zwracane z menu g��wnego
	void menu_2_edytuj_produkcje(Pula* pula);	//wywo�ywane poprzez 2 zwracane z menu g��wnego
	void menu_3_wy�wietl_statystyki(Pula* pula);	//wywo�ywane poprzez 3 zwracane z menu g��wnego
	void menu_4_wyswietl_liste_produkcji(Pula* pula);	//wywo�ywane poprzez 4 zwracane z menu g��wnego

	virtual ~Menu();
};

