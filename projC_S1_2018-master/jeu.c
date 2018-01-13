#include "unite.h"
#include "monde.h"
#include <stdio.h>
#include <stdlib.h>
static Monde *monde; //Static = variable accessibles à toutes les fonctions du fichier

void menu(){
	int choice;
	printf("Choix : ");
	scanf("%d",&choice);


	switch(choice){
		case 0:
		exit(0);
		break;
		case 1: 
		afficherMonde(monde);
		break;
		default:
		printf("NOTHING HERE\n");
		break;
	}

}

void loop(){
	while(1){
		menu();
		// test(); //penser à retirer
	}

}


void lancer(){
	monde = creerMonde();
	loop();
}
