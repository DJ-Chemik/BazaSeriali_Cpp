#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <class T>
class ListaGeneryczna
{

private:

	vector<T> lista;

public:

	T add(T obj)
	{
		lista.push_back(obj);
		return obj;

	};


	T operator[] (int INDEKS)
	{		
		int size = lista.size();
				
		try
		{
			
			if ((INDEKS < size) && (INDEKS >= 0))
				return lista[INDEKS];


			//RZUCANIE B£ÊDAMI
			{
				
				if (INDEKS >= size) //B³¹d przekroczenia zakresu
					throw string("Przekroczono zakres\n");


				if ( (INDEKS <= 0) ) //B³¹d - niewpisanie liczby naturalnej
					throw string("Podaj liczbe naturalna jako parametr\n");
			}

			
		}
		catch (string error_info)
		{
			cout << error_info;
			cout << "Zwracam wartosc dla parametru 0: ";
			return lista[0];
		}

	};

	int size()
	{
		return lista.size();
	};

	void delete_last()
	{
		int decision;
		cout << "Czy jestes pewien ¿e chcesz usunac ostatni element?\n";
		cout << "[1] - TAK\n";
		cout << "[2] - NIE\n";

		cin >> decision;
		while ((decision != 1) && (decision != 2))
		{
			cout << "Wpisz 1 lub 2 i kliknij ENTER\n";
			cin >> decision;
		}

		if (decision == 1)
		{
			lista.pop_back();
			cout << "Usunieto ostatni element\n";
		}
		else cout << "Osttani element nie zostal\n";
		
	};

	void delete_custom(int n)
	{
		//delete lista[n];
		lista.erase(lista.begin() + n);
	}

	//Pyta o decyzjê czy aby na pewno chcemy usun¹æ ca³oœæ
	void delete_all()
	{
		int decision;
		cout << "Czy jestes pewien ¿e chcesz usunac cala liste?\n";
		cout << "[1] - TAK\n";
		cout << "[2] - NIE\n";

		cin >> decision;
		while ((decision != 1) && (decision != 2))
		{
			cout << "Wpisz 1 lub 2 i kliknij ENTER\n";
			cin >> decision;
		}

		if (decision == 1)
		{
			lista.clear();
			cout << "Usunieto cala liste\n";
		}
		else cout << "Lista nie zostala usunieta\n";

	};
			
	void delete_all(bool force_deleting)
	{
		if (force_deleting)
			lista.clear();
		else delete_all();

	}
};



