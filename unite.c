#include <stdio.h>
#include <stdlib.h>

/*UNITES*/
#define SERF 's'
#define GUERRIER 'g'

/*TEAM*/
#define RED 'r'
#define BLUE 'b'

typedef struct unite{
	char couleur;	/*team*/
	char genre;		/*type d'unite*/

}Unite;

typedef Unite* UListe;


Unite *creerUnite(char couleur, char genre){
	Unite *u = malloc(sizeof(Unite));
	if(u == NULL){
		return 0;
	} 
	u->couleur = couleur;
	u->genre = genre;
	return u;
}

void printGenre(char genre){
	switch(genre){
		case SERF:
		printf("S");
		break;
		case GUERRIER:
		printf("G");
		break; 
		default:
		printf(" ");
		break;
	}
}

void printCouleur(char couleur){
	switch(couleur){
		case RED:
		printf("\x1B[31mR\x1B[0m");
		break;
		case BLUE:
		printf("\x1B[34mB\x1B[0m");
		break;
		default:
		printf(" ");
		break;
	}
}


void printUnite(Unite *u){
	if(u == 0){
		printf("  ");
	}else{
		printCouleur(u->couleur);
		printGenre(u->genre);
	}

}
