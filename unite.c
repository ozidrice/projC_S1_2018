#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <MLV/MLV_color.h>
#include <MLV/MLV_shape.h>
#include <MLV/MLV_image.h>
#define PRINT_COLOR_RED "\x1B[31m"
#define PRINT_COLOR_BLUE "\x1B[34m"
#define PRINT_COLOR_NORMAL "\x1B[0m"

#define SQUARE_SIZE 60

/*UNITES*/
#define SERF 's'
#define GUERRIER 'g'

/*TEAM*/
#define RED 'r'
#define BLUE 'b'

typedef struct unite{
	char couleur;	/*team*/
	char genre;		/*type d'unite*/

}Unite;

typedef Unite* UListe;


Unite *creerUnite(char couleur, char genre){
	Unite *u = malloc(sizeof(Unite));
	if(u == NULL){
		return 0;
	} 
	u->couleur = couleur;
	u->genre = genre;
	return u;
}

void printGenre(char genre){
	switch(genre){
		case SERF:
		printf("SER");
		break;
		case GUERRIER:
		printf("GUE");
		break; 
		default:
		printf(" ");
		break;
	}
}

void printCouleur(char couleur){
	switch(couleur){
		case RED:
		printf("%sB%s",PRINT_COLOR_RED,PRINT_COLOR_NORMAL);
		break;
		case BLUE:
		printf("%sB%s",PRINT_COLOR_BLUE,PRINT_COLOR_NORMAL);
		break;
		default:
		printf(" ");
		break;
	}
}





/*
*	Si attaquant gagne : return 1 
*	Si attaquant perd : return 0
*	Si attaque impossible : return -1
*/
int attaque(Unite *attaquant, Unite *cible) {
	if (attaquant->couleur == cible->couleur){
		return -1;
	}
	else if (attaquant->genre == cible->genre){
		return 1;
	}
	else if (attaquant->genre == GUERRIER){
		return 1;
	}
	else {
		return 0;
	}
}

char get_unite_genre(Unite *u){
	return u->genre;
}

char get_unite_couleur(Unite *u){
	return u->couleur;
}

void printUnite(Unite *u){
	if(u == 0){
		printf("   ");
	}else{
		if(u->couleur == RED){
			printf("%s",PRINT_COLOR_RED);
		}else if(u->couleur == BLUE){
			printf("%s",PRINT_COLOR_BLUE);
		}
		printGenre(u->genre);
		printf("%s",PRINT_COLOR_NORMAL);
	}
}

void MLV_printUnite(Unite *u, int x, int y){
	if(u != 0){
		char img_SERF[64] = "img/serf.png";
		char img_GUERRIER[64] = "img/guerrier.png";
		MLV_Image * img; 

		if(get_unite_couleur(u) == RED){
			MLV_draw_filled_rectangle(x, y, SQUARE_SIZE, SQUARE_SIZE, MLV_COLOR_RED);
		}else if(get_unite_couleur(u) == BLUE){
			MLV_draw_filled_rectangle(x, y, SQUARE_SIZE, SQUARE_SIZE, MLV_COLOR_BLUE);
		}
		MLV_draw_rectangle(x, y, SQUARE_SIZE, SQUARE_SIZE, MLV_COLOR_WHITE);

		if(get_unite_genre(u) == SERF){
			img = MLV_load_image(img_SERF);
			
		}else{
			img = MLV_load_image(img_GUERRIER);
		}
		MLV_resize_image_with_proportions(img,SQUARE_SIZE-5,SQUARE_SIZE-5);
		MLV_draw_image(img,x,y);
	}
}