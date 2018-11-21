#include "stdafx.h"
#include "Pula.h"


Pula::Pula()
{
	Plik.open("BazaProdukcji.txt", ios::in);	
	wczytaj_z_pliku();
	Plik.close();
}

Pula::Pula(string nazwa_pliku)
{
	Plik.open(nazwa_pliku, ios::in);
	wczytaj_z_pliku();
	Plik.close();
}

void Pula::wczytaj_z_pliku()
{
	Produkcja *pr_wsk;

	produkcje.delete_all(true);	//czyœcimy liste ¿eby nie by³o w niej œmieci
	int id;
	string tytul;
	int ocena;
	int TOP100;
	string buf; //jedno pole z pliku
	while (!Plik.eof())
	{
		
		getline(Plik, buf, '\t'); //pobiera identyfikator produkcji
		id = stoi(buf);
		getline(Plik, tytul, '\t'); //pobiera tytu³ produkcji
		getline(Plik, buf, '\t'); //pobiera ocenê produkcji
		ocena = stoi(buf);
		getline(Plik, buf, '\t'); //pobiera miejsce w rankingu produkcji
		TOP100 = stoi(buf);
		if (id == 0)
		{
			pr_wsk = new Film(tytul, ocena, TOP100);
			getline(Plik, buf, '\n');
			pr_wsk->set_d³ugoœæ(stoi(buf));
		}
		else if (id == 1)
		{
			pr_wsk = new Serial(tytul, ocena, TOP100);
			getline(Plik, buf, '\t');
			pr_wsk->set_czas_odcinka(stoi(buf));
			getline(Plik, buf, '\t');
			pr_wsk->set_day(stoi(buf));
			getline(Plik, buf, '\n');
			if (stoi(buf) == 1)
				pr_wsk->zacznij_œledziæ();
		}
		else //if (id == 2)
		{
			pr_wsk = new Live(tytul, ocena, TOP100);
			getline(Plik, buf, '\t');
			pr_wsk->set_day(stoi(buf));
			getline(Plik, buf, '\t');
			pr_wsk->set_hour(stoi(buf));
			getline(Plik, buf, '\n');
			pr_wsk->set_przypomnienie(stoi(buf));
		}

		produkcje.add(pr_wsk); //to samo co vector.push_back()
		
	}

	
}

/*void Pula::InsertSort() //int tab[], int size
{
	int j;
	Produkcja* tmp;
	
	for (int i = 1; i < produkcje.size(); i++)
	{
		tmp = produkcje[i];
		for (j = i - 1; (j >= 0) && (produkcje[j]->get_ocena() > tmp->get_ocena()); j--)
			produkcje[j+1] = produkcje[j];
		
		produkcje[j + 1] = tmp;
		
	}

}*/

void Pula::operator+=(Produkcja* x)
{
	produkcje.add(x);
}

void Pula::operator-=(Produkcja* x)
{
	for (int i = 0; i < produkcje.size(); i++)
	{
		if (produkcje[i] == x)  //gdy odnajdziemy w naszej liœcie element x (adres który jest przechowywany w liœcie )to go usuwamy
		{
			delete x; //usuwa obiekt, aby nie zostawiæ zombiaka
			produkcje.delete_custom(i); //usuwa wskaŸnik
		}
	}

}

int Pula::size()
{
	return produkcje.size();
}

Produkcja* Pula::operator[] (int INDEKS)
{
	return produkcje[INDEKS];
}

void Pula::wypisz_pule()
{
	cout << endl;
	for (int i = 0; i < produkcje.size(); i++)
	{
		cout << "Produkcja " << i + 1 << " :\n";
		produkcje[i]->wypisz_produkcje_na_ekran(); //polimorficznie wypisze za pomoc¹ metody danej klasy parametry obiektu
		cout << endl;
	}
}

void Pula::zapisz_pule(string nazwa_pliku)
{
	string ostania_linia;
	//Plik.open("BazaProdukcji.txt", ios::out);
	Plik.open(nazwa_pliku, ios::out);
	for (int i = 0; i < produkcje.size(); i++)
	{		
		if (i != (produkcje.size() - 1))
		{
			Plik << produkcje[i]->make_rekord_bazy_danych();
		}
		else
		{
			ostania_linia = produkcje[i]->make_rekord_bazy_danych();
			int rozmiar = ostania_linia.size();
			int x = 1;
			ostania_linia.erase((0 + rozmiar - x), x);
			Plik << ostania_linia;
		}
	}
	Plik.close();
}


void Pula::wyœwietl_statystyki()
{
	int tygodniowy_czas_na_seriale = 0;
	for (int i = 0; i < produkcje.size(); i++)
	{
		if (produkcje[i]->czy_jest_œledzony())
			tygodniowy_czas_na_seriale += produkcje[i]->get_czas_odcinka();
	}
	cout << "Tygodniowy czas potrzebny na ogladanie sledzonych seriali to w twoim wypadku: ";
	cout << tygodniowy_czas_na_seriale / 60 << "h " << tygodniowy_czas_na_seriale % 60 << "min\n";
}


void Pula::sortuj_wg_oceny()
{

}

void Pula::sortuj_wg_rankingu()
{

}


Pula::~Pula()
{
}
