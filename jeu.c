

#include "unite.h"
#include "monde.h"

#include "monde.h"
#include "unite.h"


#include "monde.h"
#include "unite.h"

#include "joueur.h"



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static Monde *monde; //Static = variable accessibles à toutes les fonctions du fichier
static Joueur *liste_joueurs[2];

/*TEAM*/
#define RED 'r'
#define BLUE 'b'

void printDelimiteur(){
	printf("____________________\n");
}

void menu(){
	int choice;

	printf("[0]: Quitter\n[1]: Afficher le monde\n");
	printf("Votre choix: ");




	printf("Choix : ");
	scanf("%d",&choice);



	printf("[0]: Quitter\n[1]: Afficher le monde\nVotre choix:");

	scanf("%d",&choice);



	printf("[0]: Quitter\n[1]: Afficher le monde\nVotre choix:");
	scanf("%d",&choice);


	switch(choice){
		case 0:
		exit(0);
		break;
		case 1: 
		afficherMonde(monde);

		break;



		break;





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

void selectionnerCase(){
	printf("Selectionnez une unité : \n");
	// do{
	int x,y;
	printf("x ? ");
	scanf("%d",&x);
	printf("y ? ");
	scanf("%d",&y);

	// }while();
}



void loop(){
	while(1){
		for (int i = 0; i < 2; ++i){
			Joueur *joueurCourant = liste_joueurs[i];
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
