/*

Source.cpp
Programme qui a pour but de solutioner le jeu Binairo et retourner la solution dans un fichier
Jeremy Belec
26 September 2015

*/

#include "Matrice.h"
#include "Binairo.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	Binairo Binairo_;
	string Nom_Fichier;
	cout << "Veuillez entrez un nom de fichier a lire : ";
	getline(cin, Nom_Fichier);
	system("cls");

	if (Nom_Fichier != "")
	{
		ifstream FLecture(Nom_Fichier);
		if (FLecture.is_open())
		{
			string Ligne;
			getline(FLecture, Ligne);
			Matrice<int> Tableau_(Ligne.size(), Ligne.size());
			Binairo_.LectureFichier(FLecture, Tableau_, Ligne);
			Binairo_.Solutioner(FLecture, Tableau_);
			Binairo_.SauvegarderResulta(Tableau_, Nom_Fichier);
			cout << Tableau_;
		}
		else
		{
			cout << "Impossible de lire le fichier" << endl;
		}
		// Fermeture du fichier
		FLecture.close();
	}
}