/*

Binairo.cpp
Jeremy Belec
1 Octobre 2015
Definition des methodes pour la classe Binairo

*/

#include "Binairo.h"

void Binairo::LectureFichier(ifstream & FLecture, Matrice<int> & Tableau_, string & Ligne_)
{
   int Compteur_Ligne = 0;
   while (!FLecture.eof()) // Jusqua la fin du fichier
   {
      for (int i = 0; i < Ligne_.size(); i++)
      {
         int Nombre;
         // Il faut decoder le charactere ascii pour l'interpreter comme un int
         if (Ligne_[i] == '*')
         {
            Nombre = ESPACE_ASCII;
         }
         else
         {
            Nombre = Ligne_[i] - 48; // Le nombre -48 sera soit "1" ou "0" 
         }
         Tableau_[Compteur_Ligne][i] = Nombre;
      }
      Compteur_Ligne++;
      getline(FLecture, Ligne_, '\n');
   }

   // Entrez la derniere ligne /////////////////////////////////////
   for (int i = 0; i < Ligne_.size(); i++)
   {
      int Nombre;
      if (Ligne_[i] == '*')
      {
         Nombre = ESPACE_ASCII;
      }
      else
      {
         Nombre = Ligne_[i] - 48;
      }
      Tableau_[Compteur_Ligne][i] = Nombre;
   }

}
void Binairo::Solutioner(ifstream & FLecture, Matrice<int> & Tableau_)
{
	// Parcoure la matrice jusqua temps qu'il reste aucun espace vide
   while (CalculerEspaceVide(Tableau_) > 0)
   {
	   for (int i = 0; i < Tableau_.GetNbLignes(); i++)
	   {
		   for (int j = 0; j < Tableau_.GetNbColonnes(); j++)
		   {
			   if (Tableau_[i][j] == ESPACE_ASCII)
			   {
				   // Tester 2 case dans toute les direction
				   VerifierDroite(Tableau_, i, j);
				   VerifierGauche(Tableau_, i, j);
				   VerifierHaut(Tableau_, i, j);
				   VerifierBas(Tableau_, i, j);
				   // Tester une case de chaque cote
				   VerifierSandwhichVertical(Tableau_, i, j);
				   VerifierSandwhichHorizontale(Tableau_, i, j);
			   }
		   }
	   }
	   // Tester pour si une ligne a attein 5 "1" ou "0"
	   Calculer5Horizontale(Tableau_);
	   Calculer5Verticale(Tableau_);
   }
}
void Binairo::Calculer5Verticale(Matrice<int> & Tableau_)
{
	int NombreDe0 = 0;
	int NombreDe1 = 0;
	for (int i = 0; i < Tableau_.GetNbLignes() || NombreDe0 >= 5 || NombreDe1 >= 5; i++)
	{
		for (int j = 0; j < Tableau_.GetNbColonnes(); j++)
		{
			if (Tableau_[j][i] == 1)
			{
				NombreDe1++;
			}
			if (Tableau_[j][i] == 0)
			{
				NombreDe0++;
			}
			// Si une ligne a 5 "0"
			if (NombreDe0 >= 5)
			{
				// Remplace tout les espace vide par un "1"
				for (int k = 0; k < Tableau_.GetNbColonnes(); k++)
				{
					if (Tableau_[k][i] == ESPACE_ASCII)
					{
						Tableau_[k][i] = 1;
					}
				}
			}
			// Si une ligne a 5 "1"
			if (NombreDe1 >= 5)
			{
				// Remplace tout les espace vide par un "1"
				for (int k = 0; k < Tableau_.GetNbColonnes(); k++)
				{
					if (Tableau_[k][i] == ESPACE_ASCII)
					{
						Tableau_[k][i] = 0;
					}
				}
			}
		}
		NombreDe0 = 0;
		NombreDe1 = 0;
	}

}
void Binairo::Calculer5Horizontale(Matrice<int> & Tableau_)
{
	int NombreDe0 = 0;
	int NombreDe1 = 0;
	for (int i = 0; i < Tableau_.GetNbLignes() || NombreDe0 >= 5 || NombreDe1 >= 5; i++)
	{
		for (int j = 0; j < Tableau_.GetNbColonnes(); j++)
		{
			if (Tableau_[i][j] == 1)
			{
				NombreDe1++;
			}
			if (Tableau_[i][j] == 0)
			{
				NombreDe0++;
			}
			// Si une ligne a 5 "0"
			if (NombreDe0 == 5)
			{
				// Remplace tout les espace vide par un "1"
				for (int k = 0; k < Tableau_.GetNbColonnes(); k++)
				{
					if (Tableau_[i][k] == ESPACE_ASCII)
					{
						Tableau_[i][k] = 1;
					}
				}
			}
			// Si une ligne a 5 "1"
			if (NombreDe1 == 5)
			{
				// Remplace tout les espace vide par un "1"
				for (int k = 0; k < Tableau_.GetNbColonnes(); k++)
				{
					if (Tableau_[i][k] == ESPACE_ASCII)
					{
						Tableau_[i][k] = 0;
					}
				}
			}
		}
		NombreDe0 = 0;
		NombreDe1 = 0;
	}
}
void Binairo::VerifierDroite(Matrice<int> & Tableau_, int i, int j)
{
	// Si deux case a droite son deux "1" ou "0" alors la case presente est l'autre
   if (j < Tableau_.GetNbColonnes() - 2)
   {
      if (Tableau_[i][j + 1] == 1 && Tableau_[i][j + 2] == 1)
      {
         Tableau_[i][j] = 0;
      }
      if (Tableau_[i][j + 1] == 0 && Tableau_[i][j + 2] == 0)
      {
         Tableau_[i][j] = 1;
      }
   }
}
void Binairo::VerifierGauche(Matrice<int> & Tableau_, int i, int j)
{
	// Si deux case a gauche son deux "1" ou "0" alors la case presente est l'autre
   if (j > 1)
   {
      if (Tableau_[i][j - 1] == 1 && Tableau_[i][j - 2] == 1)
      {
         Tableau_[i][j] = 0;
      }
      if (Tableau_[i][j - 1] == 0 && Tableau_[i][j - 2] == 0)
      {
         Tableau_[i][j] = 1;
      }
   }
}
void Binairo::VerifierBas(Matrice<int> & Tableau_, int i, int j)
{
	// Si deux case en bas son deux "1" ou "0" alors la case presente est l'autre
   if (i < Tableau_.GetNbLignes() - 2)
   {
      if (Tableau_[i + 1][j] == 1 && Tableau_[i + 2][j] == 1)
      {
         Tableau_[i][j] = 0;
      }
      if (Tableau_[i + 1][j] == 0 && Tableau_[i + 2 ][j] == 0)
      {
         Tableau_[i][j] = 1;
      }
   }
}
void Binairo::VerifierHaut(Matrice<int> & Tableau_, int i, int j)
{
	// Si deux case en haut son deux "1" ou "0" alors la case presente est l'autre
   if (i > 1)
   {
      if (Tableau_[i - 1][j] == 1 && Tableau_[i - 2][j] == 1)
      {
         Tableau_[i][j] = 0;
      }
      if (Tableau_[i - 1][j] == 0 && Tableau_[i - 2][j] == 0)
      {
         Tableau_[i][j] = 1;
      }
   }
}
void Binairo::VerifierSandwhichHorizontale(Matrice<int> & Tableau_, int i, int j)
{
	// Si une case a gauche et a droite sont toute les deux "1" ou "0" alors alors la case presente est l'auture
	if (j < Tableau_.GetNbColonnes() - 1 && j > 0)
	{
		if (Tableau_[i][j + 1] == 1 && Tableau_[i][j - 1] == 1)
		{
			Tableau_[i][j] = 0;
		}
		if (Tableau_[i][j + 1] == 0 && Tableau_[i][j - 1] == 0)
		{
			Tableau_[i][j] = 1;
		}
	}
}
void Binairo::VerifierSandwhichVertical(Matrice<int> & Tableau_, int i, int j)
{
	// Si une case a gauche et a droite sont toute les deux "1" ou "0" alors alors la case presente est l'auture
	if (i < Tableau_.GetNbLignes() - 1 && i > 0)
	{
		if (Tableau_[i + 1][j] == 1 && Tableau_[i - 1][j] == 1)
		{
			Tableau_[i][j] = 0;
		}
		if (Tableau_[i + 1][j] == 0 && Tableau_[i - 1][j] == 0)
		{
			Tableau_[i][j] = 1;
		}
	}
}
int  Binairo::CalculerEspaceVide(Matrice<int> & Tableau_)
{
   int CaseVide = 0;
   for (int i = 0; i < Tableau_.GetNbLignes() - 1; i++)
   {
      for (int j = 0; j < Tableau_.GetNbColonnes() - 1; j++)
      {
         if (Tableau_[i][j] == ESPACE_ASCII)
         {
            CaseVide++;
         }
      }
   }
   return CaseVide;
}
void Binairo::SauvegarderResulta(Matrice<int> & Tableau_, string NomFichier)
{
	ofstream Output;
	Output.open("Solution - " + NomFichier);
	Output << Tableau_;
}
ostream & operator << (ostream & out, const Matrice<int> & MatriceDeJeu)
{

	out << "     0   1   2   3   4   5   6   7   8   9         verification" << endl << endl;
	for (int i = 0; i < MatriceDeJeu.GetNbLignes(); i++)
	{
		int TotalLigne = 0;
		out << " " << i << " | ";
		for (int j = 0; j < MatriceDeJeu.GetNbColonnes(); j++)
		{
			TotalLigne += pow((MatriceDeJeu[i][j] * 2),(MatriceDeJeu.GetNbColonnes() - j))/2;

			if (MatriceDeJeu[i][j] == 32)
			{
				out << " " << " | ";
			}
			else
			{
				out << MatriceDeJeu[i][j] << " | ";
			}
			if (j == MatriceDeJeu.GetNbColonnes() - 1)
			{
				out << "          " << TotalLigne;
			}
		}
		out << endl << "- - - - - - - - - - - - - - - - - - - - - -" << endl;
	}
	out << endl <<"    ";
	for (int i = 0; i < MatriceDeJeu.GetNbLignes(); i++)
	{
		int TotalLigne = 0;
		for (int j = 0; j < MatriceDeJeu.GetNbColonnes(); j++)
		{
			TotalLigne += pow((MatriceDeJeu[j][i] * 2), (MatriceDeJeu.GetNbColonnes() - j)) / 2;
		}
		out << TotalLigne << " ";
	}
	out << endl;
	return out;
}
ofstream & operator << (ofstream & out, const Matrice<int> & MatriceDeJeu)
{

	out << "     0   1   2   3   4   5   6   7   8   9         verification" << endl << endl;
	for (int i = 0; i < MatriceDeJeu.GetNbLignes(); i++)
	{
		int TotalLigne = 0;
		out << " " << i << " | ";
		for (int j = 0; j < MatriceDeJeu.GetNbColonnes(); j++)
		{
			TotalLigne += pow((MatriceDeJeu[i][j] * 2), (MatriceDeJeu.GetNbColonnes() - j)) / 2;

			if (MatriceDeJeu[i][j] == 32)
			{
				out << " " << " | ";
			}
			else
			{
				out << MatriceDeJeu[i][j] << " | ";
			}
			if (j == MatriceDeJeu.GetNbColonnes() - 1)
			{
				out << "          " << TotalLigne;
			}
		}
		out << endl << "- - - - - - - - - - - - - - - - - - - - - -" << endl;
	}
	out << endl << "    ";
	for (int i = 0; i < MatriceDeJeu.GetNbLignes(); i++)
	{
		int TotalLigne = 0;
		for (int j = 0; j < MatriceDeJeu.GetNbColonnes(); j++)
		{
			TotalLigne += pow((MatriceDeJeu[j][i] * 2), (MatriceDeJeu.GetNbColonnes() - j)) / 2;
		}
		out << TotalLigne << " ";
	}
	out << endl;
	return out;
}