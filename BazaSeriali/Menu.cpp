#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{
}

int Menu::decyzja_z_zakresu(int Od, int Do)
{
	std::cin.clear();
	//std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n'); //czy�� strumie� danych
	int decission;
	do
	{
		cin >> decission;
	} while (decission > Do || decission < Od);
	cout << endl;
	return decission;
}

void Menu::komunikat_powitalny()
{
	cout << "-------WITAJ W TWOJEJ PRYWATNEJ BAZIE FILMOWEJ-------" << endl;
	cout << "------------------BAZA CHEMIK WITA-------------------" << endl;
	cout << endl;
}

Pula* Menu::pytanie_o_nazw�_pliku_do_wczytywania_puli()
{
	cout << "Z jakiego pliku chcesz pobrac informacje o puli film�w i seriali?\n";
	cout << "[0] - Standarowy plik bez podawania nazwy\n";
	cout << "[1] - Wlasny plik. Trzeba podac nazwe \n";
	int decission;	
	do{
		cin.clear();
		cin >> decission;
	} while (decission != 0 && decission != 1);


	Pula* pula;
	if (decission == 0)
	{
		pula = new Pula();
		return pula;
	}
	else
	{

		fstream plik_testowy;
		string nazwa_pliku;
		cout << "Podaj nazw� pliku: ";
		cin >> nazwa_pliku;
		plik_testowy.open(nazwa_pliku, ios::in);
		if (plik_testowy.good())
			pula = new Pula(nazwa_pliku);
		else
		{
			plik_testowy.clear();
			plik_testowy.close();
			int licznik_z�ych_wpis�w = 0; //po ilu b��dach pojawi si� podpowied�
			do
			{
				if (licznik_z�ych_wpis�w == 3)
				{
					cout << "\nCzy chcesz wprowadzic pule ze standardowego pliku?\n";
					cout << "Jesli tak to wpisz cyfre 1 i zatwierdz.\n";
					cout << "Jesli nie to wpisz ponownie nazwe pliku wlasnego\n";
					cout << "Nazwa pliku lub 1: ";
					licznik_z�ych_wpis�w = 0;
					cin >> nazwa_pliku;
					if (nazwa_pliku[0] == '1')
						nazwa_pliku = "BazaProdukcji.txt";
				}
				else
				{
					cout << "\nPodaj nazwe prawidlowego pliku. \nPamietaj ze plik ma miec format xxxxx.txt \n";
					cout << "Nazwa pliku: ";
					cin >> nazwa_pliku;
				}
				
				
				plik_testowy.open(nazwa_pliku, ios::in);
				licznik_z�ych_wpis�w++;
			} while (!plik_testowy.good());

			plik_testowy.close();
			pula = new Pula(nazwa_pliku);
		}

		return pula;
	}
}

int  Menu::menu__g��wne()
{
	int decission;
	this->clear_console();
	this->komunikat_powitalny();
	cout << "--------MENU GLOWNE--------\n";
	cout << "Wybierz co chcesz zrobic:\n";
	cout << "[0] - Dodaj Produkcje\n";
	cout << "[1] - Usun Produkcje\n";
	cout << "[2] - Edytuj Produkcje\n";
	cout << "[3] - Wyswietl statystyki\n"; //w tym rekomendacja typu szacowanie czasu potrzebnego na ogl�danie seriali
	cout << "[4] - Wyswietl liste produkcji\n";
	cout << "[5] - Zamknij program\n";
	cout << "\nTwoj wybor: ";
	return decyzja_z_zakresu(0, 5);
		
}

void Menu::menu_0_dodaj_produkcje(Pula* pula)
{
	int typ_produkcji;
	this->clear_console();
	this->komunikat_powitalny();
	cout << "--------MENU DODAWANIA PRODUKCJI--------\n";
	cout << "Jaki typ produkcji chcesz dodac?\n";
	cout << "[0] - Film\n";
	cout << "[1] - Serial\n";
	cout << "[2] - Wydarzenie na zywo\n";
	int menu_typu_produkcji = decyzja_z_zakresu(0, 2);

	string tytul, tmp;
	//char* tytul = new char;
	int ocena, ranking;
	cout << "Podaj tytul produkcji: ";
	cin >> tytul;
	getline(cin, tmp);
	tytul += tmp;
//	delete[] tytul;
	
	cout << "Podaj ocene produkcji (od 1 do 10)\n";
	cout << "(Wpisz 0 jesli nie chcesz dodawac oceny): ";
	ocena = decyzja_z_zakresu(0, 10);

	cout << "Podaj miejsce w rankingu TOP100\n";
	cout << "(Wpisz 0 jesli nie chcesz dodawac miejsca w TOP100): ";
	ranking = decyzja_z_zakresu(0, 100);

	Produkcja * wsk;
	switch (menu_typu_produkcji)
	{
	case 0:
		
		cout << "Podaj dlugosc filmu (w minutach)\n";
		cout << "(Wpisz 0 jesli nie chcesz dodawac czasu trwania): ";
		int dlugosc;
		cin >> dlugosc;
		wsk = new Film(tytul, ocena, ranking,dlugosc);
		break;

	case 1:

		wsk = new Serial(tytul, ocena, ranking);

		cout << "Podaj czas trwania odcinka (w minutach)\n";
		cout << "(Wpisz 0 jesli nie chcesz dodawac czasu trwania): ";
		int wejscie;
		cin >> wejscie;
		wsk->set_czas_odcinka(wejscie);
		cout << endl;

		cout << "Podaj dzien emisji\n";
		cout << "[1] - Poniedzialek, [2] - Wtorek itd.\n";
		cout << "(Wpisz 0 jesli nie chcesz dodawac czasu trwania): ";
		wejscie = decyzja_z_zakresu(0, 7);
		wsk->set_day(wejscie);
		cout << endl;

		cout << "Czy chcesz sledzic ten serial?\n";
		cout << "[0] - NIE\n";
		cout << "[1] - TAK\n";		
		wejscie = decyzja_z_zakresu(0, 1);
		if (wejscie == 1)
			wsk->zacznij_�ledzi�();
		cout << endl;


		break;

	default: //case 2 - nie chce przpus�i� potncjalnie niezainicjowanej zmiennej wsk

		wsk = new Live(tytul, ocena, ranking);

		cout << "Podaj dzien emisji\n";
		cout << "[1] - Poniedzialek, [2] - Wtorek itd.\n";
		cout << "(Wpisz 0 jesli nie chcesz dodawac czasu trwania): ";
		wejscie = decyzja_z_zakresu(0, 7);
		wsk->set_day(wejscie - 1);
		cout << endl;

		cout << "Podaj godzine emisji\n";
		cout << "(Zakres od 0 do 23 - nie wpisuj 24!!! (to to samo co godzina 0 nastepnego dnia)n";
		cout << "(Wpisz -1 jesli nie chcesz dodawac czasu trwania): ";
		wejscie = decyzja_z_zakresu(-1, 23);
		wsk->set_hour(wejscie);
		cout << endl;

		cout << "Na ile godzin przed wydarzeniem usatwic przypomnienie?\n";
		cout << "(Wpisz 0 jesli nie chcesz dodawac czasu trwania): ";
		cin >> wejscie;
		wsk->set_przypomnienie(wejscie);
		cout << endl;

		
		break;
	}

	pula->operator+=(wsk); //dodaje nasz eleement do puli
}

void Menu::menu_1_usun_produkcje(Pula* pula)
{
	this->clear_console();
	this->komunikat_powitalny();
	cout << "--------MENU USUWANIA PRODUKCJI--------\n";

	//Menu obrotowe do przewijania
	int ilosc_produkcji = pula->size();
	bool czy_konczyc = 1;
	int i=0;
	while (czy_konczyc==1)
	{
		this->clear_console();		
		cout << "Ilosc produkcji w bazie: " << ilosc_produkcji << "\n\n"; //mo�na w przysz�o�ci doda� wyb�r konkretnego numeru - skakanie do okre�lonej produkcji zamiast przewijania
		cout << "Wybierz opcje:\n";
		cout << "[0] - Wroc do menu glownego \n";
		cout << "[1] - Wyswietl nastepna produkcje\n";
		cout << "[2] - Wyswietl poprzednia produkcje\n";
		cout << "[3] - Usun produkcje ktora jest obecnie wyswietlona\n\n";
	
		cout << "Produkcja " << i + 1 << " :\n";
		(*pula)[i]->wypisz_produkcje_na_ekran();
		cout << endl<<endl;

		cout << "TWOJA DECYZJA: ";
		int decission = decyzja_z_zakresu(0, 3);

		switch (decission)
		{
		case 0:
			czy_konczyc = 0;
			break;

		case 1:
			if (i < (ilosc_produkcji - 1))
				i++;
			else
				i = 0;
			break;

		case 2:
			if (i > 1)
				i--;
			else
				i = (ilosc_produkcji-1);
			break;

		case 3:
			(*pula) -= (*pula)[i];
			pula->zapisz_pule("BazaProdukcji.txt");
			ilosc_produkcji = pula->size();
			i--; //prosty i tandentny trik �eby nie przekroczy�o zakresu jak usuniemy ostatni� produkcje - do poprawy jak sie ma czas
			break;
		}
	}
	

}

void Menu::menu_2_edytuj_produkcje(Pula* pula)
{
	this->clear_console();
	this->komunikat_powitalny();
	cout << "--------MENU EDYCJI PRODUKCJI--------\n";

	//Menu obrotowe do przewijania
	int ilosc_produkcji = pula->size();
	bool czy_konczyc = 1;
	string rekord;
	string styp_produkcji;
	int typ_produkcji;
	int i = 0;
	while (czy_konczyc == 1)
	{
		rekord = (*pula)[i]->make_rekord_bazy_danych();
		styp_produkcji = rekord[0];
		istringstream iss(styp_produkcji);
		iss >> typ_produkcji;

		this->clear_console();
		cout << "Ilosc produkcji w bazie: " << ilosc_produkcji << "\n\n"; //mo�na w przysz�o�ci doda� wyb�r konkretnego numeru - skakanie do okre�lonej produkcji zamiast przewijania
		cout << "Wybierz opcje:\n";
		cout << "[0] - Wroc do menu glownego \n";
		cout << "[1] - Edytuj tytul\n";
		cout << "[2] - Edytuj ocene\n";
		cout << "[3] - Edytuj miejsce w rankingu\n";

		switch (typ_produkcji)
		{
		case 0: //film
			cout << "[4] - Edytuj czas trwania filmu\n\n";
			break;

		case 1: //serial
			cout << "[4] - Edytuj czas trwania odcinka\n";
			cout << "[5] - Edytuj dzien emisji\n";
			if ((*pula)[i]->czy_jest_�ledzony())
				cout << "[6] - Przestan sledzic\n\n";
			else
				cout << "[6] - Zacznij sledzic\n\n";

			break;

		case 2: //live			
			cout << "[4] - Edytuj dzien emisji\n";
			cout << "[5] - Edytuj godzine emisji\n";
			cout << "[6] - Ustaw przypomnienie\n";
			cout << "[7] - Na kiedy ustawione jest przypomnienie?\n\n";
			break;
		}

		cout << "Produkcja " << i + 1 << " :\n";
		(*pula)[i]->wypisz_produkcje_na_ekran();
		cout << endl << endl;

		cout << "TWOJA DECYZJA: ";
		int decission = decyzja_z_zakresu(0, 3);
		cout << endl;

		string nowy_tytu�;
		int nowa_warto��;
		switch (decission)
		{
		case 0:
			czy_konczyc = 0;
			break;

		case 1:
			cout << "\nPodaj nowy tytul: ";
			cin >> nowy_tytu�;
			(*pula)[i]->set_tytu�(nowy_tytu�);
			break;

		case 2:
			cout << "\nOcena moze miec zakres od 1 do 10\n0 oznacza brak oceny\nPodaj nowa ocene: ";
			nowa_warto�� = decyzja_z_zakresu(0, 10);
			(*pula)[i]->set_ocena(nowa_warto��);
			break;

		case 3:
			cout << "\nRanking moze miec zakres od 1 do 100\n0 oznacza brak klasyfikacji w rankingu\n";
			cout<<"Podaj nowe miejsce w TOP100: ";
			decyzja_z_zakresu(0, 100);
			(*pula)[i]->set_ranking(nowa_warto��);
			break;

		case 4:
			if (typ_produkcji == 0)
			{
				cout << "Podaj nowa dlugosc filmu (w minutach): ";
				cin >> nowa_warto��;
				(*pula)[i]->set_d�ugo��(nowa_warto��);
			}
			else if (typ_produkcji == 1)
			{
				cout << "Podaj nowa dlugosc odcinka (w minutach): ";
				cin >> nowa_warto��;
				(*pula)[i]->set_czas_odcinka(nowa_warto��);
			}
			else //if (typ_produkcji==2)
			{
				cout << "Podaj nowy dzien emisji\n";
				cout << "[1] - Poniedzialek, [2] - Wtorek itd.\n";
				cout << "(Wpisz 0 jesli nie chcesz dodawac czasu trwania): ";
				nowa_warto�� = decyzja_z_zakresu(0, 7);
				(*pula)[i]->set_day(nowa_warto��-1);
				
			}
			break;

		case 5:
			if (typ_produkcji == 0)
			{
				//nic
			}
			else if (typ_produkcji == 1)
			{
				cout << "Podaj nowy dzien emisji\n";
				cout << "[1] - Poniedzialek, [2] - Wtorek itd.\n";
				cout << "(Wpisz 0 jesli nie chcesz dodawac czasu trwania): ";
				nowa_warto�� = decyzja_z_zakresu(0, 7);
				(*pula)[i]->set_day(nowa_warto�� - 1);
			}
			else //if (typ_produkcji==2)
			{
				cout << "Podaj nowa godzine emisji\n";
				cout << "(Zakres od 0 do 23 - nie wpisuj 24!!! (to to samo co godzina 0 nastepnego dnia)n";
				cout << "(Wpisz -1 jesli nie chcesz dodawac czasu trwania): ";
				nowa_warto�� = decyzja_z_zakresu(-1, 23);
				(*pula)[i]->set_hour(nowa_warto��);
			}
			break;

		case 6:
			if (typ_produkcji == 0)
			{
				//nic
			}
			else if (typ_produkcji == 1)
			{
				if ((*pula)[i]->czy_jest_�ledzony())
				{
					(*pula)[i]->przesta�_�ledzic();
					cout << "Przestano sledzic\n";
				}					
				else
				{
					(*pula)[i]->zacznij_�ledzi�();
					cout << "Zaczeto sledzic\n\n";
				}
					
			}
			else //if (typ_produkcji==2)
			{
				cout << "Na ile godzin przed wydarzeniem usatwic przypomnienie?\n";
				cout << "(Wpisz 0 jesli nie chcesz dodawac czasu trwania): ";
				cin >> nowa_warto��;
				(*pula)[i]->set_przypomnienie(nowa_warto��);
			}
			break;

		case 7:
			if (typ_produkcji == 0)
			{
				//nic
			}
			else if (typ_produkcji == 1)
			{
				//nic
			}
			else //if (typ_produkcji==2)
			{
				(*pula)[i]->przypomnij_o_wydarzeniu();
			}
			break;
		
		}

		
	}

	}



void Menu::menu_3_wy�wietl_statystyki(Pula* pula)
{
	this->clear_console();
	this->komunikat_powitalny();
	cout << "--------MENU STATYSTYK--------\n";
	pula->wy�wietl_statystyki();
	cout << endl << "Jesli chcesz opuscic to menu i przejsc do menu glownego to kliknij 0 a nastepnie ENTER\n";
	bool a;
	while (true)
	{
		cin.clear();
		cin >> a;
		if (a == false)
			break;
	}
}

void Menu::menu_4_wyswietl_liste_produkcji(Pula* pula)
{
	this->clear_console();
	this->komunikat_powitalny();
	cout << "--------MENU WYSWIETLANIA LISTY PRODUKCJI--------\n";
	pula->wypisz_pule();
	cout << endl << "Jesli chcesz opuscic to menu i przejsc do menu glownego to kliknij 0 a nastepnie ENTER\n";
	bool a;
	while (true)
	{
		cin.clear();
		cin >> a;
		if (a == false)
			break;
	}
	
}


void Menu::clear_console()
{
	system("cls");
}

Menu::~Menu()
{
}
