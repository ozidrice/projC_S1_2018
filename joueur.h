typedef struct joueur Joueur;
Joueur *creerJoueur(char nom[], char couleur);
void afficherJoueur();
char get_joueur_couleur(Joueur *j);
char *get_joueur_nom(Joueur *j);