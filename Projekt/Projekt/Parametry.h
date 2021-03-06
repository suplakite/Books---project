﻿#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;

struct Parametry
{
	string wejscie;
	string wyjscie;

	bool wejscie_podane = false;
	bool wyjscie_podane = false;
	bool pomoc_podane = false;
};

void pokazPomoc()
{
	cout << "------------------------------------------------------------" << "\n";
	cout << "Program: Ksiazki" << " | " << "Wersja: 1.00" << "\n";
	cout << "Twórca: Tomasz Migala" << "\n";
	cout << "------------------------------------------------------------" << "\n";
	cout << "Program pobiera dane z pliku, przetwarza je w odpowiedni sposób," << "\n";
	cout << "a następnie sortuje według nazwisk autorów, przyporządkowanych, " << "\n";
	cout << "do odpowiednich dzialow." << "\n";
	cout << "------------------------------------------------------------" << "\n";
	cout << "Prawdopodobnie podales bledne parametry!!" << "\n";
	cout << "------------------------------------------------------------" << "\n";
	cout << "Poprawne parametry: -i Ksiazki.txt -o output.txt" << "\n";
	cout << "------------------------------------------------------------" << "\n";
}
/*Zwraca fałsz*/
bool Sprawdz_Parametry(int argc, char *argv[], Parametry &parametry) {
	string arg;
	if (argc == 2) {
		arg = argv[1];
		if (arg == "-h")
		{
			parametry.pomoc_podane = true;
			return false;
		}
	}
	

	for (int i = 0; i < argc - 1; i++)
	{
		arg = argv[i];
		
		if (arg == "-o") // Plik wyjściowy
		{
			parametry.wyjscie = argv[i + 1];
			parametry.wyjscie_podane = true;
		}
		
		if (arg == "-i") // Plik wejściowy
		{
			parametry.wejscie = argv[i + 1];
			parametry.wejscie_podane = true;
		}
	}

	if (parametry.wejscie_podane && parametry.wyjscie_podane) 
	{
		return true;
	}
	else
	{
		return false;
	}

}