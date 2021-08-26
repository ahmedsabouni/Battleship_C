typedef struct joueurstruct
{
    char nom[15];
}Joueur;
typedef struct bateau
    {
        int taillebateau;
        char symbole;
        char nom[20];
    }Bateau;

//fonctions de redirection
void menu();
void nouvelle_partie();
void charger();
void visualiser();
void statistiques();
void themes();

//menus 
int menu1();
int menudifficulte();
int menunouvellepartie();

//fonctions de jeu
char initialiser_matrices(char matrice[10][10]);
void affichergrille(char matrice[10][10]);
void afficher_grille_double(char mat1[10][10],char mat2[10][10],char j1[15],char j2[15]);
char placer(char matr[10][10],Bateau bateau);
void placerordinateur(char mata[10][10],Bateau bateau);
void placervsordinateur(char mat[10][10],Bateau bateau,int s,int cord[s][2],char joueur[50]);
void tirer(char mat[10][10],char mata[10][10],char name[50],int g);

//fonctions principales 
void joueurvsordinateur();
void joueur1vsjoueur2();

//fonctions de memorisation
void sauvegarder(char matrice1[10][10],char matrice2[10][10],char matrice3[10][10],char matrice4[10][10],FILE *f,char name1[15],char name2[15]);
void sauvtoutepartie(char mat[10][10],char mata[10][10],FILE*f,char smiya[15],char smiya1[15]);
void statistiquesfinale(char matperdant[10][10],char matvainqueur[10][10],char jp[15],char jv[15]);
void charger1(char fichier[40],char nomjoueurcharger[15]);
void charger2(char fichier[40],char nomjoueur1charger[15],char nomjoueurcharger[15]);
void sauvgarderstatistiques(FILE *f,char joueur1[15],char joueur2[15],char matperdant[10][10],char matvainqueur[10][10],char jp[15],char jv[15],float secondes);
void affvisualiser(int n,FILE *f);

//fonctions du temps 
void affichertemps (int secondes); 
float tempspartie(clock_t debut,clock_t fin);
void delay(clock_t a);

//foctions de positionnement
void gauche();
void centre();

// pour quitter ou revenir au menu 
void findujeu();
