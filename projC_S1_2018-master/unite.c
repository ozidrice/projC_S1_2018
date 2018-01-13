#include <stdio.h>
#include <stdlib.h>

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

/*
*	Si attaquant gagne : return 1 
*	Si attaquant perd : return 0
*	Si attaque impossible : return -1
*/
int attaque(Unite *attaquant, Unite *cible) {
	if (attaquant->couleur == cible->couleur){
		return -1;
	}
	else if (attaquant->genre == cible->genre){
		return 1;
	}
	else if (attaquant->genre == GUERRIER){
		return 1;
	}
	else {
		return 0;
	}
}

//à retirer
// void test() {
// 	Unite *u1 = malloc(sizeof(Unite));
// 	u1->genre = SERF;
// 	u1->couleur = 'a';

// 	Unite *u2 = malloc(sizeof(Unite));
// 	u2->genre = GUERRIER;
// 	u2->couleur = 'b';

// 	printf("%d\n", attaque(u1, u2));
// }