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
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			printf(" |");
		}
		printf("\n");
	}
}