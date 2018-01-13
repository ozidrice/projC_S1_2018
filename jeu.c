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
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
#include <stdio.h>
#include <stdlib.h>
static Monde *monde; //Static = variable accessibles à toutes les fonctions du fichier

void menu(){
	int choice;
<<<<<<< HEAD
<<<<<<< HEAD
	printf("Choix : ");
	scanf("%d",&choice);


=======
	printf("[0]: Quitter\n[1]: Afficher le monde\nVotre choix:");
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
<<<<<<< HEAD
		break;
=======
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
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
<<<<<<< HEAD
		// test(); //penser à retirer
=======
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
=======
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
	}

}


<<<<<<< HEAD
<<<<<<< HEAD
void lancer(){
	monde = creerMonde();
=======
=======
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e


void lancer(){
	monde = creerMonde();
	initialiserMonde(monde);
<<<<<<< HEAD
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
=======
>>>>>>> 88fad3fa8ae578fe7ce4af1a16ee382d8ecb956e
	loop();
}
