#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRINT_COLOR_RED "\x1B[31m"
#define PRINT_COLOR_BLUE "\x1B[34m"
#define PRINT_COLOR_NORMAL "\x1B[0m"

/*TEAM*/
#define RED 'r'
#define BLUE 'b'

typedef struct joueur{
	char nom[128];
	char couleur;
}Joueur;

Joueur *creerJoueur(char nom[], char couleur){
	Joueur *j = malloc(sizeof(Joueur));
	if(j == NULL){
		return 0;
	}
	strcpy(j->nom,nom);
	j->couleur = couleur;
	return j;
}

void afficherJoueur(Joueur *j){
	if(j->couleur == RED){
		printf("%s",PRINT_COLOR_RED);
	}else if(j->couleur == BLUE){
		printf("%s",PRINT_COLOR_BLUE);
	}
	printf("%s%s\n",j->nom,PRINT_COLOR_NORMAL);
}

char *get_joueur_nom(Joueur *j){
	return j->nom;
}

char get_joueur_couleur(Joueur *j){
	return j->couleur;
}