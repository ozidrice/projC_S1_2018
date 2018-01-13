#include <stdio.h>
#include <stdlib.h>
#include "unite.h"

/*SIZE OF THE WORLD*/
#define HEIGHT 12
#define WIDTH 18

/*UNITES*/
#define SERF 's'
#define GUERRIER 'g'

/*TEAM*/
#define RED 'r'
#define BLUE 'b'

typedef struct monde{
	Unite *plateau[WIDTH][HEIGHT];
	int tour; /*num tour*/
	// UListe rouge, bleu; Liste des deux joueurs
}Monde;


void clearPlateau(Monde *m){
	int i;
	for(i = 0; i<HEIGHT; ++i){
		int j;
		for(j = 0; j<WIDTH; ++j){
			m->plateau[i][j] = 0;
		}
	}
}

Monde *creerMonde(){
	Monde *m = malloc(sizeof(Monde));
	if(m == NULL){
		return 0;
	} 
	clearPlateau(m);
	return m;
}



/*Créé 1 guerrier & 2 serfs pour chaque équipe*/
void initialiserMonde(Monde *m){;
	m->plateau[0][0] = creerUnite(RED,SERF);
	m->plateau[1][0] = creerUnite(RED,SERF);
	m->plateau[2][0] = creerUnite(RED,GUERRIER);
	m->plateau[WIDTH-1][HEIGHT-1] = creerUnite(BLUE,SERF);
	m->plateau[WIDTH-1][HEIGHT-2] = creerUnite(BLUE,SERF);
	m->plateau[WIDTH-1][HEIGHT-3] = creerUnite(BLUE,GUERRIER);
}


void afficherLigneHaut(){
	printf(" ");
	int i;
	for (i = 0; i < WIDTH; ++i){
		printf("|");
		printf(" %d", i);
		if(i<10)
			printf(" ");
	}
	printf("|\n");
	for (int i = 0; i < WIDTH; ++i)
	{
		printf("----");
	}
	printf("-\n");
}

void afficherMonde(Monde *m){

	afficherLigneHaut();
	int i;
	for (i = 0; i < HEIGHT; ++i)
	{
		printf("%c",'A'+i);
		int j;
		for (j = 0; j < WIDTH; ++j)
		{
			printf("|");
			printUnite(m->plateau[j][i]);

		}
		printf("|\n");

	}
}

/*
*	récupère Unite dans une case donnée
*	return 0 si vide
*/
Unite *getUnite(Monde *m, int x, int y) {
	printUnite(m->plateau[0][1]);
	if (x>=0 && x<=WIDTH-1 && y>=0 && y<HEIGHT-1) {
		return m->plateau[x][y];
	}
	return 0;
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
		m->plateau[newX][newY] = m->plateau[x][y];
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