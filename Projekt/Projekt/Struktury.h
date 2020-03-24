#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::fstream;
using std::cout;

struct Drzewo
{
	string autor;
	string tytul;

	Drzewo* lewy;
	Drzewo* prawy;
};

struct Lista
{
	string etykieta;
	Drzewo* korzen;
	Lista* nast;
	Lista* poprz;
};


bool Sprawdz_Czy_Etykieta_Istnieje(Lista* glowa, string etykieta) {

	bool ret = false;
	while (glowa) {
		
		if (glowa->etykieta == etykieta) {
			ret = true;
		}
		glowa = glowa->nast;
	}

	return ret;

}

bool Na_Poczatek(Lista* &glowa, Lista* &ogon, Drzewo* korzen, string etykieta) {

	if (Sprawdz_Czy_Etykieta_Istnieje(glowa, etykieta))
		return false;

	glowa = new Lista{
		etykieta,
		korzen,
		glowa,
		nullptr
	};
	if (glowa->nast != nullptr)
		glowa->nast->poprz = glowa;
	else
		ogon = glowa;

	return true;
}

bool Na_Koniec(Lista* &glowa, Lista* &ogon, Drzewo* korzen, string etykieta) {

	if (Sprawdz_Czy_Etykieta_Istnieje(glowa, etykieta))
		return false;

	ogon = new Lista{
		etykieta,
		korzen,
		nullptr,
		ogon
	};
	if (ogon->nast != nullptr)
		ogon->poprz->nast = ogon;
	else
		glowa = ogon;

	return true;
}

Drzewo* zwroc_Wskaznik_na_drzewo(Lista* glowa, string etykieta) {

	while (glowa) {
		if (glowa->etykieta == etykieta) {
			//cout << "\twsk: " << glowa->etykieta << " == " << etykieta << " | " << glowa->korzen << "\n";
			return glowa->korzen;
		}
		glowa = glowa->nast;
	}

	return nullptr;
}

Drzewo* dodaj_Do_Drzewa(Drzewo* &korzen, string autor, string tytul) {
	//cout << "Add tree: " << autor << " " << tytul << "\n";
	if (!korzen)
		korzen = new Drzewo{ autor, tytul, nullptr, nullptr };
	else if (korzen->autor < autor)
		dodaj_Do_Drzewa(korzen->lewy, autor, tytul);
	else
		dodaj_Do_Drzewa(korzen->prawy, autor, tytul);

	return korzen;
}

//void PrintNice(Drzewo* korzen, int indent = 0)
//{
//	if (korzen)
//	{
//		PrintNice(korzen->prawy, indent + 3);
//		//for (int i = 0; i < indent; ++i)
//			//cout << " ";
//		cout << korzen->autor << " | " << korzen->tytul << "\n";
//		PrintNice(korzen->lewy, indent + 3);
//	}
//}
//
//
//void wyswietlListe(Lista* glowa) {
//
//	while (glowa) {
//		cout << glowa->etykieta << "\n";
//		PrintNice(glowa->korzen);
//		cout << "\n\n";
//		glowa = glowa->nast;
//
//	}
//
//}


void Zapisz_Autorow(fstream &file, Drzewo* korzen) {

	if (korzen)
	{
		Zapisz_Autorow(file, korzen->prawy);
		file << korzen->autor << "; " << korzen->tytul << "\n";
		Zapisz_Autorow(file, korzen->lewy);
	}
}

bool Rozpocznij_Zapis(Lista* glowa, string nazwa_pliku) 
{
	remove("output.txt");
	fstream file;
	file.open(nazwa_pliku.c_str(), std::ios::app);

	if (!file.good())
		return false;

	while (glowa) {
		file << glowa->etykieta << ":\n";
		Zapisz_Autorow(file, glowa->korzen);
		file << "\n";
		glowa = glowa->nast;
	}
	return true;
}

void Usun_Liste(Lista* &glowa)
{
	while (glowa)
	{
		Lista* pom = glowa;
		glowa = glowa->nast;
		delete pom;
	}
}

void Wyswietlanie_Do_Usuniecia(Drzewo* korzen)
{
	if (korzen != nullptr)
	{
		Wyswietlanie_Do_Usuniecia(korzen->lewy);
	//	cout << korzen->autor << " ";
		Wyswietlanie_Do_Usuniecia(korzen->prawy);
	}
}


void Usun_Drzewo(Drzewo* &korzen)
{
	if (korzen != nullptr)
	{
		Wyswietlanie_Do_Usuniecia(korzen->lewy);
		Wyswietlanie_Do_Usuniecia(korzen->prawy);
		delete korzen;
		korzen = nullptr;
	}
}