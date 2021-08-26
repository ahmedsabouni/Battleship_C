#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include"bataillenavale.h"


clock_t debut, fin;
int x,y,i,j,gagner=0,veri=0,k=0;
char tempstr[10],orin[2];

Bateau porte_avion={5,'P',"porte avion"};
Bateau torpilleur={2,'O',"Torpilleur"};
Bateau contre_torpilleur={3,'T',"Contre-torpilleur"};
Bateau croiseur={4,'C',"croiseur"};
Joueur joueur,j1,j2;

char placer(char matr[10][10],Bateau bateau)
{
    int veri ,i ,j,x,y;
    char orin[2];
    for(;;)
        {
            veri=0;
            printf("%s:\n",bateau.nom);
            printf("Orientation(v/h): ");
            scanf("%s",&orin);
            printf("Entrez la ligne et la colonne:\n");
            scanf("%d %d",&x,&y);
            if(strcmp(orin,"h")==0)
            {
                if(y>10-bateau.taillebateau || y<0 || x>9 || x<0 || matr[x][y]=='P'||matr[x][y]=='C'||matr[x][y]=='O'||matr[x][y]=='T')
                {
                    printf("Vous ne pouvez pas placer votre bateau ici\n");
                    continue;
                }
                else
                {
                    for(i=y;i<y+2;i++)
                    {
                        if(matr[x][i]!='.')
                        {
                            printf("Vous ne pouvez pas placer votre bateau ici\n");
                            veri=1;
                            break;
                        }
                    }
                    if(veri==1)
                        continue;
                    else
                    {
                        for(i=y;i<y+bateau.taillebateau;i++)
                        {
                            matr[x][i]=bateau.symbole;

                        }
                        break;
                    }
                }
            }
            if(strcmp(orin,"v")==0)
            {
                if(x>10-bateau.taillebateau || x<0 || y>9 || y<0||matr[x][y]=='P'||matr[x][y]=='C'||matr[x][y]=='O'||matr[x][y]=='T')
                {
                    printf("Vous ne pouvez pas placer votre bateau ici\n");
                    continue;
                }
                else
                {
                    for(i=x;i<x+2;i++)
                    {
                        if(matr[i][y]!='.')
                        {
                            printf("Vous ne pouvez pas placer votre bateau ici\n");
                            veri=1;
                            break;
                        }
                    }
                    if(veri==1)
                        continue;
                    else
                    {
                        for(i=x;i<x+bateau.taillebateau;i++)
                        {
                            matr[i][y]=bateau.symbole;

                        }
                        break;
                    }
                }
            }
        }
        return matr[10][10];
}

char  initialiser_matrices(char matrice[10][10])
{
    for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                matrice[i][j] = '.';
            }
        }
    return matrice[10][10];
}

void affichergrille(char matrice[10][10])
{
    for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 30; j++)
                printf(" ");
            if (i == 0)
            {
                printf("    ");
                for (j = 0; j < 10; j++)
                    printf("%d   ", j);
                printf("\n\n");
                for (j = 0; j < 30; j++)
                    printf(" ");
            }
            printf("%d   ", i);
            for (j = 0; j < 10; j++)
            printf("%c   ", matrice[i][j]);
            printf("\n\n");
        }
}

int menudifficulte()
{
    int ch;
    centre();
    delay(200);
    printf("1: facile\n");
    gauche();
    delay(200);
    printf("2: moyen\n");
    gauche();
    delay(200);
    printf("3: difficile\n");
    gauche();
    delay(200);
    printf("0: retour au menu\n\n");
    gauche();
    printf("choisissez la difficulte: ");
    scanf("%d", &ch);
    system("cls");  
    return ch;
}
void gauche()
{
    for (int i = 0; i < 30; i++)
    {
        printf(" ");
    }
}

void centre()
{

    for (int i = 0; i < 10; i++)
    {
        printf("\n");
    }

    for (int i = 0; i < 30; i++)
    {
        printf(" ");
    }
}
void delay(clock_t a)
{
    clock_t debut;
    debut = clock();
    while (clock() - debut < a)
    {
    }
}
int menu1()
{
    int choix1;
    delay(200);
    printf("\n\n");
    gauche();
    delay(200);
    printf("1:Nouvelle partie\n");
    gauche();
    delay(200);
    printf("2:Charger une partie\n");
    gauche();
    delay(200);
    printf("3:Visualiser une partie\n");
    gauche();
    delay(200);
    printf("4:statistiques\n");
    gauche();
    delay(200);
    printf("5:Themes\n");
    gauche();
    delay(200);
    printf("0:Quitter le jeu \n");
    gauche();
    printf("\n");
    gauche();
    delay(200);
    printf("Choisissez une option:  ");
    scanf("%d", &choix1);
    system("cls");
    return choix1;
}
int menunouvellepartie()
{
    int choix2;
    centre();
    delay(200);
    printf("1: joueur vs l'ordinateur\n");
    gauche();
    delay(200);
    printf("2: joueur1 vs joueur2\n");
    gauche();
    delay(200);
    printf("3: retour au menu\n");
    gauche();
    delay(200);
    printf("0: pour quitter le jeu\n\n");
    gauche();
    delay(200);
    printf("choississez une option: ");
    scanf("%d", &choix2);
    system("cls");
    system("cls");
    return choix2;
}
void menu()
{


    int i, choix1;
    choix1=menu1();
    switch (choix1)
    {
    case 1:
        nouvelle_partie();
        break;
    case 2:
        charger();
        break;
    case 3:
        visualiser();
        break;
    case 4:
        statistiques();
        break;
    case 5:
        themes();
        break;
    case 0:
        exit(-1);
        break;
    default:
        printf("erreur!!\n\nchoisissez une option de 1 a 4\n");
        menu();
        break;
    }
}
void themes()
{
    int d;
    printf("\t\t\t\tchoisissez un theme:\n\t\t1)sombre\n\t\t2)claire\n\t\t3)oceon\n");
    scanf("%d",&d);
    system("cls");
    switch (d)
    {
    case 1:
        system("color 0F");
        menu();
        break;
    case 2:
        system("color 7C");
        menu();
        break;
    case 3:
        system("color 3F");
        menu();
    default:
        printf("erreur");
        delay(2000);
        themes();
        break;
    }

}
void nouvelle_partie()
{

    int choix2;
    choix2=menunouvellepartie();

    if (choix2 == 1)
    {
        joueurvsordinateur();
    }

    else if (choix2==2)
    {
        joueur1vsjoueur2();
    }
    else if (choix2==3)
    {
        menu();
    }

}
void joueurvsordinateur()
{
    clock_t debut,fin;
    char matj[10][10], mataj[10][10], matordi[10][10], mataordi[10][10], joueur[15];
    int a = 0, b = 0, c = 0, d = 0,k=0, probab, diff, ch;
    int cordP[5][2], cordC[4][2], cordCT[3][2],cord2CT[3][2], cordT[2][2];
    FILE*f;
    FILE*fp;
    char ordi[15]="ordinateur";
    ch=menudifficulte();
        if (ch == 1)
            diff = 1;
        if (ch == 2)
            diff = 2;
        if (ch == 3)
            diff = 3;
        if (ch==0)  
            menu();  
        system("cls");
        centre();
        delay(200);
        getchar();
        debut=clock();
        printf("Entrez votre Nom: ");

        /*********ici il faut crrer le dossier sauvegard.h  on lui demande apres le nom de la partie */
        gets(joueur);
        char jo[50]="";
        strcat(jo,joueur);
        strcat(jo,"diff.txt");
        FILE *fdiff;
        fdiff=fopen(jo,"w+");
        fprintf(fdiff,"%d",diff);
        fclose(fdiff);
        system("cls");

        initialiser_matrices(matordi);
        initialiser_matrices(matj);
        initialiser_matrices(mataordi);
        initialiser_matrices(mataj);
        affichergrille(matj);


        /*Porte avion*/
        placervsordinateur(matj,porte_avion,5,cordP,joueur);
        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
        sauvtoutepartie(matj,mataordi,fp,joueur,ordi);
        k = 0;
        system("cls");
        affichergrille(matj);
        /*C:croiseur*/
        placervsordinateur(matj,croiseur,4,cordC,joueur);
        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
        sauvtoutepartie(matj,mataordi,fp,joueur,ordi);
        k = 0;
        system("cls");
        affichergrille(matj);
        /*Contre torpilleurs*/
        placervsordinateur(matj,contre_torpilleur,3,cordCT,joueur);
        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
        sauvtoutepartie(matj,mataordi,fp,joueur,ordi);
        k = 0;
        system("cls");
        affichergrille(matj);
        /*CONTRE Torpilleur 2 */
        placervsordinateur(matj,contre_torpilleur,3,cord2CT,joueur);
        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
        sauvtoutepartie(matj,mataordi,fp,joueur,ordi);
        k = 0;
        system("cls");
        affichergrille(matj);
        /**********Torpilleurs**********/
        placervsordinateur(matj,torpilleur,2,cordT,joueur);
        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
        sauvtoutepartie(matj,mataordi,fp,joueur,ordi);
        system("cls");
        affichergrille(matj);
        printf("Cliquer sur ENTER pour continuer!");
        /*Placement de l'ordinateur*/
        fflush(stdin);
        gets(tempstr);
        srand(time(NULL));
        //Porte avion
        placerordinateur(matordi,porte_avion);
        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
        /* Croiseur*/
        placerordinateur(matordi,croiseur);
        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
        /* Contre-torpilleurs*/
        placerordinateur(matordi,contre_torpilleur);
        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
        /*************Contre-torpilleurs 2 ordinateur*******/
        placerordinateur(matordi,contre_torpilleur);
        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
        /***Torpilleur***/
        placerordinateur(matordi,torpilleur);
        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
        
        /****debut du match ****/
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
                mataj[i][j] = matj[i][j];
        }
        for (;;)
        {
            system("cls");
            afficher_grille_double(mataj,mataordi,joueur,ordi);
            
            for (;;)
        {
                if (gagner!=17)
            {
                printf("\n\tEntrez la ligne  et la colonne: ");
                scanf("%d %d", &x, &y);
                if (x > 9 || x < 0 || y > 9 || y < 0 || mataordi[x][y] == 'X' || mataordi[x][y] == '*')
                {
                    printf("tu ne peux pas tirer en ces coordonnees!!\n");
                    continue;
                }
                else
                {
                    if (matordi[x][y] == 'P' || matordi[x][y] == 'C' || matordi[x][y] == 'T' || matordi[x][y] == 'O')
                    {
                        if (mataordi[x][y] != 'X')
                        {
                            mataordi[x][y] = 'X';
                            sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                            sauvtoutepartie(mataj,mataordi,fp,joueur,ordi);
                            system("cls");
                            afficher_grille_double(mataj,mataordi,joueur,ordi);
                            for (i = 0; i < 10; i++)
                            {
                                for (j = 0; j < 10; j++)
                                {
                                    if (mataordi[i][j] == 'X')
                                        gagner++;
                                }
                            }
                            gauche();
                            printf("\n******Touche******\n");

                            if (gagner == 17)
                            {
                                printf("\nvous avez gagne!!!\n");
                                fin=clock();
                                tempspartie(debut,fin);
                                statistiquesfinale(mataordi,mataj,ordi,joueur);
                                sauvgarderstatistiques(f,joueur,ordi,mataordi,mataj,ordi,joueur,tempspartie(debut,fin));
                                findujeu();
                                break;
                            }
                            gagner = 0;

                            continue;
                        }
                        else
                        {
                            printf("vous ne peuvez pas tirer en ces coordonnees!!\n");
                            continue;
                        }
                    }
                    else
                    {
                        mataordi[x][y] = '*';
                        printf("rate\n");
                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                        sauvtoutepartie(mataj,mataordi,fp,joueur,ordi);
                        break;
                    }
                }
            }
            else{
                    printf("\n *********** vous avez perdu!!!***********\n");
                    fin=clock();
                    tempspartie(debut,fin);
                    statistiquesfinale(mataj,mataordi,joueur,ordi);
                    sauvgarderstatistiques(f,joueur,ordi,mataj,mataordi,joueur,ordi,tempspartie(debut,fin));
                    findujeu();
                }
        }
            for (;;)
{
    ///facile///
                if(diff==1)
            {
                x=rand()%10;
                y=rand()%10;

                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                {
                    continue;
                }
                else
                {
                    if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                    {
                        if (mataj[x][y] != 'X')
                        {
                            mataj[x][y] = 'X';
                            sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                            system("cls");
                            afficher_grille_double(mataj,mataordi,joueur,ordi);
                            delay(1000);
                            printf("\n*******touche*******\n");
                            continue;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else
                    {
                        mataj[x][y] = '*';
                        printf("rate\n");
                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                        break;
                    }
                }
        }
          ////////////moyen///////////

            if(diff==2)
            {
                probab = rand() % 20;
                if (probab == 6 && a < 5)
                {
                    x = cordP[a][0];
                    y = cordP[a][1];
                    a++;
                }
                else if (probab == 7&& b < 4)
                {
                    x = cordC[b][0];
                    y = cordC[b][1];
                    b++;
                }
                else if (probab == 4 && d < 3)
                {
                i=rand()%2;
                    if(i==1){
                    x = cordCT[d][0];
                    y = cordCT[d][1];
                    d++;
                    }
                    else
                    {
                        x = cord2CT[d][0];
                        y = cord2CT[d][1];
                        d++;
                    }
                }
                else if (probab == 3 && c < 2)
                {
                    x = cordT[c][0];
                    y = cordT[c][1];
                    c++;
                }
                else
                {
                    x = rand() % 10;
                    y = rand() % 10;
                }
                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                {
                    continue;
                }
                else
                {
                    if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                    {
                        if (mataj[x][y] != 'X')
                        {
                            mataj[x][y] = 'X';
                            sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                            system("cls");
                            afficher_grille_double(mataj,mataordi,joueur,ordi);
                            delay(1000);
                            continue;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else
                    {
                        mataj[x][y] = '*';
                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                        break;
                    }
                }
        }
          ///////////dificilee//////////////////////

if(diff==3)

            {
                int w;

                x=rand()%10;
                y=rand()%10;


                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                {
                    continue;
                }
                else
                {

                    if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                    {
                        if (mataj[x][y] != 'X')
                        {
                            mataj[x][y] = 'X';
                            sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                            system("cls");
                            afficher_grille_double(mataj,mataordi,joueur,ordi);
                            delay(1000);
                            w=rand()%4;

                            if(w==1)
                            {
                                x=x+1;
                                y=y;


                            if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                    mataj[x][y] = 'X';
                                    sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                    system("cls");
                                    afficher_grille_double(mataj,mataordi,joueur,ordi);
                                    delay(1000);
                                    x=x+1;
                                    y=y;
                                }
                                }
                                else
                                { 
                                mataj[x][y] = '*';
                                break;
                                }
                                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);


                                x=x+1;
                                y=y;



                                }
                                }
                                    else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                        break;
                                    }
                                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);


                                x=x+1;
                                y=y;
                                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                    mataj[x][y] = 'X';
                                    sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                    system("cls");
                                    afficher_grille_double(mataj,mataordi,joueur,ordi);
                                    delay(1000);
                                }
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                        break;
                                    }




                            }
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                        break;
                                    }

                            }
                                    if(w==2)
                            {
                            x=x;
                            y=y+1;


                            if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);


                                x=x;
                                y=y+1;

                                }
                                }
                                else
                            {
                                mataj[x][y] = '*';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                break;
                            }
                                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);


                                x=x;
                                y=y+1;
                                }
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                        break;
                                    }
                                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);


                                x=x;
                                y=y+1;
                                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);}
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                        break;
                                    }



                                }
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                        break;
                                    }

                            }
                                    if(w==3)
                            {
                            x=x-1;
                            y=y;


                            if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);


                                x=x-1;
                                y=y;



                                }
                                }
                                else
                            {
                                mataj[x][y] = '*';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                break;
                            }
                                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);


                                x=x-1;
                                y=y;



                                }
                                }
                                    else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                        break;
                                    }
                                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);


                                x=x-1;
                                y=y;
                                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);}
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                        break;
                                    }



                                }
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                        break;
                                    }

                                    }
                            else
                            {
                            x=x;
                            y=y-1;


                            if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);


                                x=x;
                                y=y-1;



                                }
                                }
                                else
                            {
                                mataj[x][y] = '*';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                break;
                            }
                                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);


                                x=x;
                                y=y-1;



                                }
                                }
                                    else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                        break;
                                    }
                                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);


                                x=x;
                                y=y-1;
                                if (x > 9 || x < 0 || y > 9 || y < 0 || mataj[x][y] == 'X' || mataj[x][y] == '*')
                                {
                                    continue;
                                }
                            if (matj[x][y] == 'P' || matj[x][y] == 'C' || matj[x][y] == 'T' || matj[x][y] == 'O')
                                {
                                    if (mataj[x][y] != 'X')
                                {
                                mataj[x][y] = 'X';
                                sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                system("cls");
                                afficher_grille_double(mataj,mataordi,joueur,ordi);
                                delay(1000);}
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                        break;
                                    }

                            }
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                                        break;
                                    }
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else
                    {
                        mataj[x][y] = '*';
                        sauvegarder(matj,matordi,mataj,mataordi,f,joueur,ordi);
                        break;
                    }
                }
    }
}
            for (i = 0; i < 10; i++)
            {
                for (j = 0; j < 10; j++)
                {
                    if (mataordi[i][j] == 'X')
                        gagner++;
                }
            }

            if (gagner == 17)
            {
                printf("\n ************vous avez  gagne!*************\n");
                fin=clock();
                tempspartie(debut,fin);
                statistiquesfinale(mataordi,mataj,ordi,joueur);
                sauvgarderstatistiques(f,joueur,ordi,mataordi,mataj,ordi,joueur,tempspartie(debut,fin));
                break;
            }
            gagner = 0;

            for (i = 0; i < 10; i++)
            {
                for (j = 0; j < 10; j++)
                {
                    if (mataj[i][j] == 'X')
                        gagner++;
                }
            }

            if (gagner == 17)
            {
                printf("\n *********** vous avez perdu!!!***********\n");
                fin=clock();
                tempspartie(debut,fin);
                statistiquesfinale(mataj,mataordi,joueur,ordi);
                sauvgarderstatistiques(f,joueur,ordi,mataj,mataordi,joueur,ordi,tempspartie(debut,fin));
                findujeu();
                break;
            }
            gagner = 0;
        }
}