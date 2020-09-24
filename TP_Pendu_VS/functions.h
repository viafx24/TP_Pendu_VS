#pragma once
#ifndef DEF_FUNCTIONS // Si la constante n'a pas �t� d�finie le fichier n'a jamais �t� inclus
#define DEF_FUNCTIONS // On d�finit la constante pour que la prochaine fois le fichier ne soit plus inclus

/* Contenu de votre fichier .h (autres include, prototypes, define...) */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define TAILLE_MAX 100 // Tableau de taille 1000

char lireCaractere();
int CompterMotFichier();
int TirageAleatoire(int NbrMots);
void ChoisirMot(int RandomChooseMot);

#endif



