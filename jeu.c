<<<<<<< HEAD
#include "unite.h"
#include "monde.h"
=======
#include "monde.h"
#include "unite.h"
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
#include <stdio.h>
#include <stdlib.h>
static Monde *monde; //Static = variable accessibles à toutes les fonctions du fichier

void menu(){
	int choice;
<<<<<<< HEAD
	printf("Choix : ");
	scanf("%d",&choice);


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
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
		default:
		printf("NOTHING HERE\n");
		break;
	}

}

void loop(){
	while(1){
		menu();
<<<<<<< HEAD
		// test(); //penser à retirer
=======
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
	}

}


<<<<<<< HEAD
void lancer(){
	monde = creerMonde();
=======


void lancer(){
	monde = creerMonde();
	initialiserMonde(monde);
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
	loop();
}
