#include <stdio.h>
#include <stdlib.h>
#include "monde.h"


int main(int argc, char argv[]){
	Monde *monde = creerMonde();
	afficherMonde(monde);
}