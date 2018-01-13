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
<<<<<<< HEAD
=======

>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
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