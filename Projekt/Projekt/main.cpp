#include <iostream>
#include <fstream>
#include <string>
//#include <cmath>
//#include <algorithm>
#include "Parametry.h"
#include "Struktury.h"
#include "PrzetwarzaniePliku.h"

//using namespace std;


int main(int argc, char ** argv)
{
	setlocale(LC_ALL, "Polish");

	Parametry parametry;

	if(!Sprawdz_Parametry(argc, argv, parametry)) 
	{
		pokazPomoc();
		return 0;
	}

	Lista * glowa = nullptr;
	Lista * ogon = nullptr;
	Drzewo* korzen = nullptr;

	Pobierz_Z_Pliku(parametry.wejscie, glowa, ogon);
	//cout << "------\n";
	//wyswietlListe(glowa);
	Rozpocznij_Zapis(glowa, parametry.wyjscie);
	
	Usun_Drzewo(korzen);
	Usun_Liste(glowa);
	return 0;
}