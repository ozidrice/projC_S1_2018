typedef struct monde Monde;
void afficherMonde(Monde *m);
Monde *creerMonde();
Unite* getUnite(Monde *m, int x, int y);
int deplaceUnite(Monde *m, int x, int y, int newX, int newY);