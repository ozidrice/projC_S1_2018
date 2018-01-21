hellomake: main.c fenetre.c jeu.c monde.c unite.c joueur.c 
	gcc `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` fenetre.c `pkg-config --libs-only-l MLV` -Wall -o executable main.c jeu.c joueur.c monde.c unite.c 
