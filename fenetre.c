#include <MLV/MLV_all.h>
#include <MLV/MLV_color.h>
#include <MLV/MLV_shape.h>
#include <MLV/MLV_image.h>
#include "unite.h"
#include "monde.h"

/*SIZE OF THE WORLD*/
#define HEIGHT 12
#define WIDTH 18
#define SQUARE_SIZE 60

/*UNITES*/
#define SERF 's'
#define GUERRIER 'g'

/*TEAM*/
#define RED 'r'
#define BLUE 'b'


void openWindow(){
	MLV_create_window( "TEST", "TEST", WIDTH*SQUARE_SIZE, HEIGHT*SQUARE_SIZE ); 
}

void createSquares(){
	int i;
	for(i=0; i<HEIGHT; ++i){
		int j;
		for(j=0; j<WIDTH; ++j){
			MLV_draw_rectangle(SQUARE_SIZE*j,SQUARE_SIZE*i,SQUARE_SIZE,SQUARE_SIZE,MLV_COLOR_WHITE);
		}
	}
}

void convert_from_px_to_square(int x, int y, int *positionX, int *positionY){
	*positionX = x/SQUARE_SIZE;
	*positionY = y/SQUARE_SIZE;
}

void getMouse(int *x, int *y){
	MLV_wait_mouse(x, y);
}

void setupWindows(){
	openWindow();
	createSquares();
	
	MLV_actualise_window();
}

