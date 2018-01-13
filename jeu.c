<<<<<<< HEAD
<<<<<<< HEAD
#include "unite.h"
#include "monde.h"
=======
#include "monde.h"
#include "unite.h"
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
=======
#include "monde.h"
#include "unite.h"
<<<<<<< HEAD
#include "joueur.h"
=======
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
>>>>>>> 6d454319c10e12fba454cc537b45ff9feaae2cd7
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
<<<<<<< HEAD
	printf("[0]: Quitter\n[1]: Afficher le monde\n");
	printf("Votre choix: ");

=======
<<<<<<< HEAD
<<<<<<< HEAD
	printf("Choix : ");
	scanf("%d",&choice);


=======
	printf("[0]: Quitter\n[1]: Afficher le monde\nVotre choix:");
>>>>>>> 6d454319c10e12fba454cc537b45ff9feaae2cd7
	scanf("%d",&choice);

>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
=======
	printf("[0]: Quitter\n[1]: Afficher le monde\nVotre choix:");
	scanf("%d",&choice);

>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
	switch(choice){
		case 0:
		exit(0);
		break;
		case 1: 
		afficherMonde(monde);
<<<<<<< HEAD
		break;
=======
<<<<<<< HEAD
<<<<<<< HEAD
		break;
=======
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
=======
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
>>>>>>> 6d454319c10e12fba454cc537b45ff9feaae2cd7
		default:
		printf("NOTHING HERE\n");
		break;
	}

}

<<<<<<< HEAD



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
=======
void loop(){
	while(1){
		menu();
<<<<<<< HEAD
<<<<<<< HEAD
		// test(); //penser à retirer
=======
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
=======
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
>>>>>>> 6d454319c10e12fba454cc537b45ff9feaae2cd7
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


<<<<<<< HEAD
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

=======
<<<<<<< HEAD
<<<<<<< HEAD
void lancer(){
	monde = creerMonde();
=======
=======
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
>>>>>>> 6d454319c10e12fba454cc537b45ff9feaae2cd7


void lancer(){
	monde = creerMonde();
	initialiserMonde(monde);
<<<<<<< HEAD
	initialiserListJoueurs();
	printDelimiteur();
	afficherListeJoueur();
=======
<<<<<<< HEAD
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
=======
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
>>>>>>> 6d454319c10e12fba454cc537b45ff9feaae2cd7
	loop();
}
