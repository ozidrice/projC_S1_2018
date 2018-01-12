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
	Unite *plateau[HEIGHT][WIDTH];
	int tour; /*num tour*/
	UListe rouge, bleu; /*Liste des deux joueurs*/
}Monde;


void clearPlateau(Monde *m){
	int i = 0;
	for(i; i<HEIGHT; ++i){
		int j = 0;
		for(j; j<WIDTH; ++j){
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
	m->plateau[0][1] = creerUnite(RED,SERF);
	m->plateau[0][2] = creerUnite(RED,GUERRIER);
	m->plateau[HEIGHT-1][WIDTH-1] = creerUnite(BLUE,SERF);
	m->plateau[HEIGHT-1][WIDTH-2] = creerUnite(BLUE,SERF);
	m->plateau[HEIGHT-1][WIDTH-3] = creerUnite(BLUE,GUERRIER);
}



void afficherMonde(Monde *m){
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			printUnite(m->plateau[i][j]);
			printf("	|");
		}
		printf("\n");
	}
}