/*

Binairo.h
Jeremy Belec
1 Octobre 2015
regroupement de methode pour le programme solutionaire de binairo

*/

#include "Matrice.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

class Binairo
{
	 const int ESPACE_ASCII = 32;
	 void VerifierDroite(Matrice<int> & Tableau_, int i, int j);
	 void VerifierGauche(Matrice<int> & Tableau_, int i, int j);
	 void VerifierBas(Matrice<int> & Tableau_, int i, int j);
	 void VerifierHaut(Matrice<int> & Tableau_, int i, int j);
	 void VerifierSandwhichHorizontale(Matrice<int> & Tableau_, int i, int j);
	 void VerifierSandwhichVertical(Matrice<int> & Tableau_, int i, int j);
	 void Calculer5Horizontale(Matrice<int> & Tableau_);
	 void Calculer5Verticale(Matrice<int> & Tableau_);
	 int  CalculerEspaceVide(Matrice<int> & Tableau_);
	public:
	 void LectureFichier(ifstream & FLecture, Matrice<int> & Tableau_, string & Ligne_);
	 void Solutioner(ifstream & FLecture, Matrice<int> & Tableau_);
	 void SauvegarderResulta(Matrice<int> & Tableau_, string NomFichier);
};