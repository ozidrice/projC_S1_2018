
#include "unite.h"
#include "monde.h"

#include "joueur.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static Monde *monde; //Static = variable accessibles à toutes les fonctions du fichier
static Joueur *liste_joueurs[2];
static Joueur *joueurCourant;

/*TEAM*/
#define RED 'r'
#define BLUE 'b'

void printDelimiteur(){
	printf("____________________\n");
}

void actionUnite(){
	int newX;
	char newY;
	Unite *u;
	int x;
	char y;
	int y_int;
	int newY_int;
	int erreur = 0;

	do{
		printf("Selectionnez une unité : \n");
		
		printf("Coordonnées x : ");
		scanf("%d",&x);
		printf("Coordonnées y : ");
		scanf(" %c",&y);
		printf("\n");

		y_int = y-'A';
		u = getUnite(monde, x, y_int);
		if(u==0){
			printf("[ERREUR] : Unité introuvable.\n");
			erreur = 1;
		}
		if(joueurCourant->couleur == u->couleur){
			printf("[ERREUR] : cette unité ne vous appartient pas.\n");
			erreur = 1;
		}

	 }while(erreur == 1);
	erreur = 0;
	 do{
		 printf("Nouvelles coordonnées x : ");
		 scanf("%d",&newX);
		 printf("\n");
		 printf("Nouvelles coordonnées y : ");
		 scanf(" %c",&newY);
		 newY_int = newY-'A';
		 if(newX+1 != x && newX-1 != x && newY+1 != y && newY-1 != y){
		 	erreur = 1;
		 	printf("[ERREUR] : vous pouvez vous déplacer que d'une case.\n");
		 }
	 }while(erreur == 1);
	 deplaceUnite(monde, x, y_int, newX, newY_int);
}


void menu(){
	int choice;
	printf("[0]: Quitter\n[1]: Afficher le monde\nVotre choix:");
	scanf("%d",&choice);


	switch(choice){
		case 0:
		exit(0);
		break;
		case 1: 
		afficherMonde(monde);
		break;
		case 2:
		actionUnite();
		default:
		printf("NOTHING HERE\n");
		break;
	}

}





Joueur *initialiserJoueur(char couleur){
	char nom[128];
	do{
		printf("Nom ? ");
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



void loop(){
	while(1){
		for (int i = 0; i < 2; ++i){
			joueurCourant = liste_joueurs[i];
			printDelimiteur();
			printf("C'est au tour de ");
			afficherJoueur(joueurCourant);
			menu();
		}
	}
}



void lancer(){
	monde = creerMonde();
	initialiserMonde(monde);

	initialiserListJoueurs();
	printDelimiteur();
	afficherListeJoueur();

	loop();
}
