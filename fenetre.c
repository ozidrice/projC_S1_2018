#include <MLV/MLV_all.h>

void openWindow(){
	MLV_create_window( "TEST", "TEST", 600, 600 );
	MLV_actualise_window();
	MLV_wait_seconds(10);
}