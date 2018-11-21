#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Pula.h"
using namespace std;

class Menu
{
private:
	int decyzja_z_zakresu(int Od, int Do); //metoda do podejmowania decyzji z pewnego zakresu, zwraca wybran¹ (PRAWID£OW¥) wartoœæ

public:
	Menu();

	void komunikat_powitalny();
	Pula* pytanie_o_nazwê_pliku_do_wczytywania_puli();
	void clear_console();

	int menu__g³ówne();
	void menu_0_dodaj_produkcje(Pula* pula); //wywo³ywane poprzez 0 zwracane z menu g³ównego
	void menu_1_usun_produkcje(Pula* pula);	//wywo³ywane poprzez 1 zwracane z menu g³ównego
	void menu_2_edytuj_produkcje(Pula* pula);	//wywo³ywane poprzez 2 zwracane z menu g³ównego
	void menu_3_wyœwietl_statystyki(Pula* pula);	//wywo³ywane poprzez 3 zwracane z menu g³ównego
	void menu_4_wyswietl_liste_produkcji(Pula* pula);	//wywo³ywane poprzez 4 zwracane z menu g³ównego

	virtual ~Menu();
};

