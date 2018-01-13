#include <stdio.h>
#include <stdlib.h>
#include "unite.h"

/*SIZE OF THE WORLD*/
#define HEIGHT 12
#define WIDTH 18


/*TEAM*/
#define RED 'r'
#define BLUE 'b'

typedef struct monde{
	Unite *plateau[HEIGHT][WIDTH];
	int tour; /*num tour*/
	UListe rouge, bleu; /*Liste des deux joueurs*/
}Monde;

Monde *creerMonde(){
	Monde *m = malloc(sizeof(Monde));
	if(m == NULL){
		return 0;
	} 
	return m;
}

void afficherMonde(Monde *m){
	int i;
	for (i = 0; i < HEIGHT; ++i)
	{
		int j;
		for (j = 0; j < WIDTH; ++j)
		{
			printf(" |");
		}
		printf("\n");
	}
}

/*
*	récupère Unite dans une case donnée
*	return 0 si vide
*/
Unite *getUnite(Monde *m, int x, int y) {
	return m->plateau[x][y];
}

/*
*	recoit nouvelles coordonnées pour déplacer Unite
*	attaque si case occupée
*/
int deplaceUnite(Monde *m, int x, int y, int newX, int newY) {
	//Si mm position
	if(x == newX && y == newY) {
		return 0;
	}

	//Si vide
	if (getUnite(m, newX, newY) == 0){
		m->plateau[x][y] = m->plateau[newX][newY];
		m->plateau[x][y] = 0;
	}else{
		if(attaque(m->plateau[x][y], m->plateau[newX][newY]) == 0) {
			m->plateau[x][y] = 0;
		}else{
			//Si mm team
			if(attaque(m->plateau[x][y], m->plateau[newX][newY]) == -1) {
				return 0;
			}

			m->plateau[x][y] = m->plateau[newX][newY];
			m->plateau[x][y] = 0;
		}
	}
	return 1;
}