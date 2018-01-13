#include <stdio.h>
#include <stdlib.h>
#define PRINT_COLOR_RED "\x1B[31m"
#define PRINT_COLOR_BLUE "\x1B[34m"
#define PRINT_COLOR_NORMAL "\x1B[0m"


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
		printf("SER");
		break;
		case GUERRIER:
		printf("GUE");
		break; 
		default:
		printf(" ");
		break;
	}
}

void printCouleur(char couleur){
	switch(couleur){
		case RED:
		printf("%sB%s",PRINT_COLOR_RED,PRINT_COLOR_NORMAL);
		break;
		case BLUE:
		printf("%sB%s",PRINT_COLOR_BLUE,PRINT_COLOR_NORMAL);
		break;
		default:
		printf(" ");
		break;
	}
}


void printUnite(Unite *u){
	if(u == 0){
		printf("   ");
	}else{
		if(u->couleur == RED){
			printf("%s",PRINT_COLOR_RED);
		}else if(u->couleur == BLUE){
			printf("%s",PRINT_COLOR_BLUE);
		}
		printGenre(u->genre);
		printf("%s",PRINT_COLOR_NORMAL);
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