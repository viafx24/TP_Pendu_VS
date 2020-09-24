#include "functions.h"

extern int Nbrcoups;
extern int LongueurMot;

extern char *Mot;
extern char *MotCache;
extern char *ChangeMotCache;

extern char Lettre;

char lireCaractere()
{
	char caractere = 0;

	caractere = getchar();          // On lit le premier caract�re
	caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas d�j�

	// On lit les autres caract�res m�moris�s un � un jusqu'au \n (pour les effacer)
	while (getchar() != '\n');
	return caractere; // On retourne le premier caract�re qu'on a lu
}

int CompterMotFichier()
{

	int NbrMots = 0;

	FILE *fichier = NULL;

	char chaine[TAILLE_MAX] = ""; // Cha�ne vide de taille TAILLE_MAX

	fichier = fopen("Dictionnaire_Pendu.txt", "r");

	if (fichier != NULL)
	{
		while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne re�oit pas d'erreur (NULL)
		{
			NbrMots++;
		}

		fclose(fichier);
	}

	return NbrMots;
}

int TirageAleatoire(int NbrMots)
{
	/* Intializes random number generator */
	time_t t; //for random function
	srand((unsigned)time(&t));
	int RandomChooseMot;
	RandomChooseMot = rand() % (NbrMots - 1) + 1; // (+1) to begin from 1 and not 0
	return RandomChooseMot;
}

void ChoisirMot(int RandomChooseMot)
{
	int NbrMots = 0;

	FILE *fichier = NULL;

	char chaine[TAILLE_MAX] = ""; // Cha�ne vide de taille TAILLE_MAX
								  //char chaine;

	fichier = fopen("Dictionnaire_Pendu.txt", "r");

	if (fichier != NULL)
	{
		while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne re�oit pas d'erreur (NULL)
		{
			NbrMots++;
			if (NbrMots == RandomChooseMot)
			{
				LongueurMot = strlen(chaine);
				Mot = malloc(LongueurMot * sizeof(char));            // On alloue de la m�moire pour le tableau
				MotCache = malloc(LongueurMot * sizeof(char));       // On alloue de la m�moire pour le tableau
				ChangeMotCache = malloc(LongueurMot * sizeof(char)); // On alloue de la m�moire pour le tableau

				if (Mot == NULL || MotCache == NULL || ChangeMotCache == NULL)
				{
					exit(0);
				}

				strncpy(Mot, chaine, LongueurMot - 1);
				Mot[LongueurMot - 1] = '\000'; // remplace le \n par un \000 

				for (int i = 0; i < LongueurMot; i++)
				{
					if (i < LongueurMot - 1)
					{
						MotCache[i] = '*';
						ChangeMotCache[i] = '*';
					}
					else
					{
						MotCache[i] = '\000';
						ChangeMotCache[i] = '\000';
					}
				}
			}
		}

		fclose(fichier);
	}
}