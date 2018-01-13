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
