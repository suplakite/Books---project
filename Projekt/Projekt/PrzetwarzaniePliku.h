#pragma once
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Struktury.h"
using std::cout;
using std::fstream;


/*
opis


paramety:
	
*/
bool Pobierz_Z_Pliku(string plik, Lista* &glowa, Lista* &ogon)
{
	fstream pliczek;
	pliczek.open(plik.c_str(), std::ios::in);
	if (!pliczek.good())
	{
		cout << "------------------------------------------------------------" << "\n";
		cout << "Nie znaleziono takiego pliku.\n";
		cout << "Poprawna nazwa pliku: Ksiazki.txt \n";
		cout << "------------------------------------------------------------" << "\n";
		pokazPomoc();
		return false;
	}

	while (!pliczek.eof())
	{
		string linia;

		getline(pliczek, linia);

		string autor, tytul;

		if (linia == "")
		{
			continue;
		}

		//cout << "Linia: " << linia << "\n";
		int x = linia.find(";");
		if (x != string::npos)
		{
			autor = linia.substr(0, x);
			linia = linia.erase(0, x + 2);
		}
		else
		{
			return false;
		}
		x = linia.find(";");
		if (x != string::npos)
		{
			tytul = linia.substr(0, x);
			linia = linia.erase(0, x + 2);
		}
		else
		{
			return false;
		}

		string etykieta;
		do {
			x = linia.find(",");

			if (x != string::npos)
			{
				etykieta = linia.substr(0, x);
				linia = linia.erase(0, x + 2);
			}
			else
			{
				etykieta = linia;
			}

			Drzewo* korzen_ptr = zwroc_Wskaznik_na_drzewo(glowa, etykieta);
			Drzewo* korzen_w_liscie = dodaj_Do_Drzewa(korzen_ptr, autor, tytul);
			Na_Poczatek(glowa, ogon,

				korzen_w_liscie,

				etykieta);

			//cout << "Autor: " << autor << "  |  " << "Tytul: " << tytul << "  |  " << "Etykieta: " << etykieta << "\n";
		} while (x != string::npos);
	}
	pliczek.close();
	return true;
}