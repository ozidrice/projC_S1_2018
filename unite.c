#include <stdio.h>

/*UNITES*/
#define SERF 's'
#define GUERRIER 'g'

typedef struct unite{
	char couleur;	/*team*/
	char genre;		/*type d'unite*/
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
