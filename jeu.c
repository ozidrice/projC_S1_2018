#include "monde.h"
#include "unite.h"
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
		default:
		printf("NOTHING HERE\n");
		break;
	}

}

void loop(){
	while(1){
		menu();
	}

}




void lancer(){
	monde = creerMonde();
	loop();
}
