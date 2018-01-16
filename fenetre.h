typedef struct joueur Joueur;
void setupWindows();
void selectCase(int *positionX, int *positionY);
void createSquares();
void getMouse(int *x, int *y);
void convert_from_px_to_square(int x, int y, int *positionX, int *positionY);
void MLV_affiche_message(char str[]);
void MLV_affiche_joueur(Joueur *j);
void MLV_affiche_err(char str[]);