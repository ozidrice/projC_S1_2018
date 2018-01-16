#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MLV/MLV_all.h>
#include <MLV/MLV_color.h>
#include <MLV/MLV_shape.h>
#include <MLV/MLV_image.h>
#include "fenetre.h"
#include "unite.h"
#include "joueur.h"
#include "jeu.h"


/*SIZE OF THE WORLD*/
#define HEIGHT 12
#define WIDTH 18
#define SQUARE_SIZE 60

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
	int nbVivant_RED;
	int nbVivant_BLUE;
}Monde;

int partieFinie(Monde *m){
	if(m->nbVivant_BLUE == 0 || m->nbVivant_RED == 0)
		return 1;
	return 0;
}

int get_nb_vivant(Monde *m, char couleur){
	if(couleur == RED){
		return m->nbVivant_RED;
	}
	if(couleur == BLUE){
		return m->nbVivant_BLUE;
	}
	return -1;
}

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


/*
*	récupère Unite dans une case donnée
*	return 0 si vide
*/
Unite *getUnite(Monde *m, int x, int y) {
	if (x>=0 && x<=WIDTH-1 && y>=0 && y<=HEIGHT-1) {
		return m->plateau[x][y];
	}
	return 0;
}

Unite *MLV_getUnite_from_mouse(Monde *m, int *x, int *y) {
	getMouse(x,y);
	int squareX, squareY;
	convert_from_px_to_square(*x,*y, &squareX, &squareY);
	return getUnite(m,squareX,squareY);
}

/*
*	demande de positionner unité
*/
void getPosition(int *x, char *y, int *y_int){
	int erreur;
	do{
		erreur = 0;
		printf("Coordonnées x : ");
		scanf("%d", x);
		printf("Coordonnées y : ");
		scanf(" %c", y);
		*y_int = *y-'A';
		if (*x<0 || *x>WIDTH-1 || *y_int<0 || *y_int>HEIGHT-1){
			printf("[ERREUR] : entrez des coordonnées valides.\n");
			erreur = 1;
		}
	}while (erreur == 1);
}


void positionneUnite(Monde *m, char couleur){
	int nbGuerrier = 1, nbSerf = 2;
	int i, x, y_int;
	char y;
	for (i=0 ; i<nbSerf ; i++){
		Unite *u;
		do{
			printf("Placez le SERF n°%d :\n", i+1);
			getPosition(&x, &y, &y_int);
			u = getUnite(m, x, y_int);
			if(u != 0){
				printf("[ERREUR] : Impossible de placer une unité à cette position.\n");
			}
		}while(u != 0);
		m->plateau[x][y_int] = creerUnite(couleur,SERF);
		printf("\n");
	}
	for (i=0 ; i<nbGuerrier ; i++){
		Unite *u;
		do{
			printf("Placez le GUERRIER n°%d :\n", i+1);
			getPosition(&x, &y, &y_int);
			u = getUnite(m, x, y_int);
			if(u != 0){
				printf("[ERREUR] : Impossible de placer une unité à cette position.\n");
			}
		}while(u != 0);
		m->plateau[x][y_int] = creerUnite(couleur,GUERRIER);
		printf("\n");
	}
}

/*
* 	CaseX & CaseY : coordonnées de la case
* 	x & y : coordonnées de la case sur la fenetre
*/
void get_x_y_from_case(int caseX, int caseY, int *x, int *y){
	*x = caseX*SQUARE_SIZE;
	*y = caseY*SQUARE_SIZE;  
}

void MLV_afficherMonde(Monde *m){
	createSquares();
	int i;
	for (i = 0; i < HEIGHT; ++i)
	{
		int j;
		for (j = 0; j < WIDTH; ++j)
		{
			int x, y;
			get_x_y_from_case(j,i,&x,&y);
			MLV_printUnite(m->plateau[j][i],x,y);
		}
	}
	MLV_actualise_window();
}



void MLV_positionneUnite(Monde *m, char couleur){
	int nbGuerrier = 1, nbSerf = 2;
	int i, x, y, x_final, y_final;

	for (i=0 ; i<nbSerf ; i++){
		Unite *u;
		do{
			MLV_affiche_message("Placez un SERF");
			getMouse(&x, &y);
			convert_from_px_to_square(x, y, &x_final, &y_final);
			u = getUnite(m, x_final, y_final);
			if(u != 0){
				MLV_affiche_message("[ERREUR] : Impossible de placer une unité à cette position.\n");
			}
		}while(u != 0);
		m->plateau[x_final][y_final] = creerUnite(couleur,SERF);
		printf("\n");
		MLV_afficherMonde(m);
	}
	for (i=0 ; i<nbGuerrier ; i++){
		Unite *u;
		do{
			MLV_affiche_message("Placez le GUERRIER");
			getMouse(&x, &y);
			convert_from_px_to_square(x, y, &x_final, &y_final);
			u = getUnite(m, x_final, y_final);
			if(u != 0){
				MLV_affiche_message("[ERREUR] : Impossible de placer une unité à cette position.\n");
			}
		}while(u != 0);
		m->plateau[x_final][y_final] = creerUnite(couleur,GUERRIER);
		printf("\n");
		MLV_afficherMonde(m);
	}
}




/*Créé 1 guerrier & 2 serfs pour chaque équipe*/
void initialiserMonde(Monde *m){
<<<<<<< HEAD
	
	printf("C'est au tour de ");
	//afficherJoueur(get_joueur(RED));
=======
	MLV_affiche_joueur(get_joueur(RED));
>>>>>>> master
	MLV_positionneUnite(m, RED);

	printDelimiteur();

<<<<<<< HEAD
	printf("C'est au tour de ");
	//afficherJoueur(get_joueur(BLUE));
=======
	MLV_affiche_joueur(get_joueur(BLUE));
>>>>>>> master
	MLV_positionneUnite(m, BLUE);

	m->nbVivant_RED = 3;
	m->nbVivant_BLUE = 3;
}


void ligneMonde(){
	int k;
	printf("-+");
	for (k=0;k<WIDTH;k++){
		printf("---+");
	}
	printf("\n");
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
	ligneMonde();
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
		ligneMonde();
	}
}



int tuerUnite(Monde *m, int posX, int posY){
	Unite *u = getUnite(m,posX,posY);
	if(u != 0){
		if(get_unite_couleur(u) == RED){
			m->nbVivant_RED--;
		}else if(get_unite_couleur(u) == BLUE){
			m->nbVivant_BLUE--;
		}
		m->plateau[posX][posY] = 0;
		return 1;
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
			tuerUnite(m,x,y);
		}else{
			//Si mm team
			if(attaque(m->plateau[x][y], m->plateau[newX][newY]) == -1) {
				return 0;
			}else{
				tuerUnite(m,newX,newY);
				m->plateau[newX][newY] = m->plateau[x][y];
				m->plateau[x][y] = 0;
			}
		}
	}
	return 1;
}