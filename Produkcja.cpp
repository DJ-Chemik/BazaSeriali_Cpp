#include "stdafx.h"
#include "Produkcja.h"


Produkcja::Produkcja(string TYTU�) :
	tytu�(TYTU�)
{
}

Produkcja::Produkcja(string TYTU�, int OCENA) : 
	tytu�(TYTU�),
	ocena(OCENA)
{
}

Produkcja::Produkcja(string TYTU�, int OCENA, int TOP100) :
	tytu�(TYTU�),
	ocena(OCENA),
	miejsce_w_TOP100(TOP100)
{
}


void Produkcja::set_tytu�(string TYTU�)
{
	tytu� = TYTU�;
}

string Produkcja::get_tytu�()
{
	
	return tytu�;
}

void Produkcja::set_ocena(int OCENA)
{
	ocena = OCENA;
}

int Produkcja::get_ocena()
{
	return ocena;
}

void Produkcja::set_ranking(int RANK)
{
	if (RANK>0 && RANK<=100)
		miejsce_w_TOP100 = RANK;
	else cout << "Podana liczba nie mie�ci si� w zakresie TOP100\n";
}

int Produkcja::get_ranking()
{
	if (miejsce_w_TOP100 != 0)
		return miejsce_w_TOP100;
	else
	{
		cout << "Podana produkcja nie znajduje sie w TOP100";
		return 0;
	}
}

void Produkcja::wypisz_produkcje_na_ekran()
{
	cout << "\tTytul: \"" << this->tytu� << "\"\n";
	cout << "\tOcena: " << this->ocena << "/10\n";
	cout << "\tMiejsce w rankingu TOP100: ";
	if (this->miejsce_w_TOP100)
		cout << this->miejsce_w_TOP100 << "\n";
	else cout << "---\n";
	

}

bool Produkcja::operator==(Produkcja x)
{
	int size1 = this->tytu�.size();
	int size2 = x.tytu�.size();
	int r�nica = size1 - size2; //0: r�wne |||  <0: str2 wi�kszy ||| >0 str1 wi�kszy:

	if (r�nica != 0)
		return false;
			
	for (int i = 0; i < size1;)
	{
		if (this->tytu�[i] == x.tytu�[0])
		{
			i++;
		}
		else return false;
	}

	return true; //je�li przejdzie przez p�tle to znaczy �e wszystkie znaki si� zgadza�y -BRAWO, TO TEN SAM TYTU� :-)
	
}

string Produkcja::make_rekord_bazy_danych() //tworzy 1 lijnijk� w kt�rej s� wszytskie informacje o danym obiekcie i ona b�dzie zapisywana do pliku
{
	
	string wynikowy,tmp;
	wynikowy = tytu� + "\t" + IntToStr(ocena) + "\t" + IntToStr(miejsce_w_TOP100) + "\t";

	return wynikowy;
}

string Produkcja::IntToStr(int n)
{
	string tmp;
	if (n < 0) {
		tmp = "-";
		n = -n;
	}
	if (n > 9)
		tmp += IntToStr(n / 10);
	tmp += n % 10 + 48;
	return tmp;
}

Produkcja::~Produkcja()
{
}
