// BazaSeriali.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Generic.h"
#include "Pula.h"
#include "Produkcja.h"
#include "Film.h"
#include "Live.h"
#include "Serial.h"
#include "Śledzony.h"
#include "Nieśledzony.h"

#include <string>
#include <vector>
using namespace std;

int main()
{
	ListaGeneryczna<int> wektorek;

	for (int i=0;i<10;i++)
		wektorek.add(i);
	
	wektorek.delete_last();

   return 0;
}

