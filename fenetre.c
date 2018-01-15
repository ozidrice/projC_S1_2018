#include <MLV/MLV_all.h>
#include <MLV/MLV_color.h>
#include <MLV/MLV_shape.h>
#include <MLV/MLV_image.h>
#include <MLV/MLV_text.h>
#include "unite.h"
#include "monde.h"

/*SIZE OF THE WORLD*/
#define HEIGHT 12
#define WIDTH 18
#define SQUARE_SIZE 60
#define MARGE_BOTTOM 200

/*UNITES*/
#define SERF 's'
#define GUERRIER 'g'

/*TEAM*/
#define RED 'r'
#define BLUE 'b'


void openWindow(){
	MLV_create_window( "TEST", "TEST", WIDTH*SQUARE_SIZE, HEIGHT*SQUARE_SIZE+MARGE_BOTTOM ); 
}

void createSquares(){
	MLV_draw_filled_rectangle(0, 0, WIDTH*SQUARE_SIZE, HEIGHT*SQUARE_SIZE, MLV_COLOR_BLACK);
	int i;
	for(i=0; i<HEIGHT; ++i){
		int j;
		for(j=0; j<WIDTH; ++j){
			MLV_draw_rectangle(SQUARE_SIZE*j,SQUARE_SIZE*i,SQUARE_SIZE,SQUARE_SIZE,MLV_COLOR_WHITE);
		}
	}
}

void selectCase(int *positionX, int *positionY){
	int x,y;
	MLV_wait_mouse(&x, &y);
	
	*positionX = x/SQUARE_SIZE;
	*positionY = y/SQUARE_SIZE;
}

void affiche_score(){
}

void affiche_message(char str[]){
	MLV_draw_filled_rectangle(0, HEIGHT*SQUARE_SIZE, WIDTH*SQUARE_SIZE, MARGE_BOTTOM, MLV_COLOR_BLACK);
	MLV_Font* font = MLV_load_font( "font/Roboto-Light.ttf" , 20 );
	MLV_draw_text_with_font(10, HEIGHT*SQUARE_SIZE,
                str, 
                font, MLV_COLOR_WHITE
        );
	affiche_score();
}

void setupWindows(){
	openWindow();
	createSquares();
	affiche_message("Bonjour");
	MLV_actualise_window();
}

