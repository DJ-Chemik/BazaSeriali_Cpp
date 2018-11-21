// BazaSeriali.cpp : Defines the entry point for the console application.
//
#pragma once

#include "stdafx.h"
#include "Generic.h"
#include "Pula.h"
#include "Produkcja.h"
#include "Film.h"
#include "Live.h"
#include "Serial.h"
#include "Menu.h"

#include <string>
#include <vector>

using namespace std;

int main()
{
	Menu menu;
	menu.komunikat_powitalny();
	Pula* baza = menu.pytanie_o_nazwę_pliku_do_wczytywania_puli();



	//(*baza) -= (*baza)[4];






	/* POMOC W UŻYWANIU WSKAŹNIKOW*/
	///////////////////////////////////////////////////////////////////////////////////////////
	//baza.operator-=(wsk_film);
	//Produkcja *wsk_serial = new Serial("TWD", 9, 11);		//dodawanie produkcji
	//*baza += wsk_serial;									//dodawanie produkcji
	//cout<< baza->operator[](0)->get_tytuł();				//wyświetlanie danego parametruy z konkretnej produkcji
	//cout<< (*baza)[0]->get_tytuł();				//to samo co wyzej tylko inaczej




	cout << endl;
	
	//baza->wyświetl_statystyki();
	string a;
	while (true)
	{
		int podMenu = menu.menu__główne();
		switch (podMenu)
		{
		case 0:
			menu.menu_0_dodaj_produkcje(baza);
			break;

		case 1:
			menu.menu_1_usun_produkcje(baza);
			break;

		case 2:
			menu.menu_2_edytuj_produkcje(baza);
			break;

		case 3:
			menu.menu_3_wyświetl_statystyki(baza);
			break;

		case 4:
			menu.menu_4_wyswietl_liste_produkcji(baza);
			break;

		case 5:
			return 0;
			break;
		}

		baza->zapisz_pule("BazaProdukcji.txt");
	}


	cout << endl;
   return 0;
}

