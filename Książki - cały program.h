#include <iostream>
#include <fstream>
#include <string>
#include "Parametry.h"
#include "Struktury.h"
#include "PrzetwarzaniePliku.h"
#include "DetectMemoryLeaks.h"

int main(int argc, char ** argv)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Parametry parametry;

	if(!Sprawdz_Parametry(argc, argv, parametry)) 
	{
		pokazPomoc();
		return 0;
	}

	Lista * glowa = nullptr;
	Lista * ogon = nullptr;
	
	Pobierz_Z_Pliku(parametry.wejscie, glowa, ogon);
	Rozpocznij_Zapis(glowa, parametry.wyjscie);
	Usun_Liste(glowa);
	
	return 0;
}