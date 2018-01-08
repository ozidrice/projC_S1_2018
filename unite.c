#include <stdio.h>

/*UNITES*/
#define SERF 's'
#define GUERRIER 'g'

typedef struct unite{
	int posX, posY; /*position sur le monde*/
	char couleur;	/*team*/
	char genre;		/*type d'unite*/
	struct unite *suiv;	
}Unite;

typedef Unite* UListe;


void printGenre(char genre){
	switch(genre){
		case SERF:
			printf("Serf\n");
			break;
		case GUERRIER:
			printf("GUERRIER\n");
			break; 
	}
}


void printUnite(Unite *u){
	printGenre(u->genre);
}
