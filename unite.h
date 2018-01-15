typedef struct unite Unite;
typedef Unite* UListe;
void printGenre(char genre);
void printUnite(Unite *u);


int attaque(Unite *attaquant, Unite *cible);
// void test();

Unite *creerUnite();

char get_unite_couleur(Unite *u);
char get_unite_genre(Unite *u);
void MLV_printUnite(Unite *u, int x, int y);