#include <MLV/MLV_all.h>

#include "fenetre.h"
#include "joueur.h"
#include "unite.h"
#include "monde.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static Monde *monde; //Static = variable accessibles à toutes les fonctions du fichier
static Joueur *liste_joueurs[2];
static Joueur *joueurCourant;

/*TEAM*/
#define RED 'r'
#define BLUE 'b'

void lancer();

void printDelimiteur(){
	printf("____________________\n");
}

void actionUnite(){
	int newX;
	char newY;
	Unite *u;
	int x;
	char y;
	int y_int = 0;
	int newY_int;
	int erreur;

	int err_deplacement;
	do{
		err_deplacement = 0;
		do{
			erreur =0;
			u=0;
			printf("Selectionnez une unité : \n");
			
			printf("Coordonnées x : ");
			scanf("%d",&x);
			printf("Coordonnées y : ");
			scanf(" %c",&y);
			printf("\n");
			u = getUnite(monde, x, y_int);
			if(u==0){
				printf("[ERREUR] : Unité introuvable.\n");
				erreur = 1;
			}
			if(u!=0 && get_joueur_couleur(joueurCourant) != get_unite_couleur(u)){
				printf("[ERREUR] : cette unité ne vous appartient pas.\n");
				erreur = 1;
			}

		}while(erreur == 1);
		
			do{
				erreur = 0;
				printf("Nouvelles coordonnées x : ");
				scanf("%d",&newX);
				printf("Nouvelles coordonnées y : ");
				scanf(" %c",&newY);
				newY_int = newY-'A';
				if(newX+1 != x && newX-1 != x && newY+1 != y && newY-1 != y){
					erreur = 1;
					printf("[ERREUR] : vous pouvez vous déplacer que d'une case.\n");
				}
			}while(erreur == 1);

			if(deplaceUnite(monde, x, y_int, newX, newY_int) != 1){
				err_deplacement=1;
				printf("[ERREUR] : Déplacement à cette case impossible.\n");
			}
	}while(err_deplacement == 1);
	

}

void MLV_actionUnite() {
	int x, y;
	int x_select, y_select;
	int x_depl, y_depl;
	Unite *u;
	int erreur;

	do{
		erreur =0;
		u=0;
		printf("Selectionnez une unité : \n");
	
		getMouse(&x, &y);
		convert_from_px_to_square(x, y, &x_select, &y_select);
		
		u = getUnite(monde, x_select, y_select);
		if(u==0){
			printf("[ERREUR] : Unité introuvable.\n");
			erreur = 1;
		}
		if(u!=0 && get_joueur_couleur(joueurCourant) != get_unite_couleur(u)){
			printf("[ERREUR] : cette unité ne vous appartient pas.\n");
			erreur = 1;
		}
	}while(erreur == 1);
	
	printf("______________\nTROUVE\n");
	printf("x:%d \ty:%d\n",x_select,y_select);
	printUnite(u);
	printf("______________\n");
	
	do{
		erreur = 0;
		getMouse(&x, &y);
		convert_from_px_to_square(x, y, &x_depl, &y_depl);
		printf("x:%d \ty:%d\n",x_depl,y_depl);
		if(y_depl+1 != y_select && y_depl-1 != y_select && x_depl+1 != x_select && x_depl-1 != x_select){
			erreur = 1;
			printf("[ERREUR] : vous pouvez vous déplacer que d'une case.\n");
		}
	}while(erreur == 1);
	deplaceUnite(monde, x_select, y_select, x_depl, y_depl);
}

void menu(){
	MLV_actionUnite();
}



Joueur *initialiserJoueur(char couleur){
	char nom[128];
	do{
		printf("Nom : ");
		scanf("%s",nom);
	}while(strlen(nom) <= 0);
	return creerJoueur(nom, couleur);
}


void initialiserListJoueurs(){
	printf("Entrez le nom du joueur 1 : \n");
	liste_joueurs[0] = initialiserJoueur(RED);
	printf("Entrez le nom du joueur 2 : \n");
	liste_joueurs[1] = initialiserJoueur(BLUE);
}

void afficherListeJoueur(){
	int i;
	for(i = 0; i<2; ++i){
		printf("Joueur %d: ",i+1);
		afficherJoueur(liste_joueurs[i]);
	}
}

Joueur *get_joueur(char color){
	for (int i = 0; i < 2; ++i)
	{
		Joueur *j = liste_joueurs[i];
		if(get_joueur_couleur(j) == color){
			return j;
		}
	}
	return 0;
}



void loop(){
	while(1){
		while(partieFinie(monde) == 0){
			for (int i = 0; i < 2; ++i){
				afficherMonde(monde);
				MLV_afficherMonde(monde);
				joueurCourant = liste_joueurs[i];
				printDelimiteur();
				//affiche_message(strcat("C'est au tour de ",get_joueur_nom(joueurCourant)));
				menu();
			}
		}
		printDelimiteur();
		printf("La partie est finie\n");
		if(get_nb_vivant(monde,RED) == 0){
			afficherJoueur(get_joueur(RED));
		}else if(get_nb_vivant(monde,BLUE)){
			afficherJoueur(get_joueur(BLUE));
		}
		printf(" a gagné\n");
	}
}



void lancer(){
	monde = creerMonde();

	initialiserListJoueurs();
	printDelimiteur();
	afficherListeJoueur();

	afficherMonde(monde);
	setupWindows();
	MLV_afficherMonde(monde);
	initialiserMonde(monde);

	loop();
}
