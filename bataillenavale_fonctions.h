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

void joueur1vsjoueur2()
{
    clock_t debut,fin;
    char matj1[10][10],mataj1[10][10],matj2[10][10],mataj2[10][10],orin[2];
    int gagner1;
    FILE*f;
    FILE*pt;

    

        centre();
        gauche();
        debut=clock();
        printf("joueur1 vs joueur2:\n");

        printf("Entrer Nom de joueur 1:\n");
        scanf("%s",&j1.nom);

        printf("Entrer Nom de joueur 2:\n");
        scanf("%s",&j2.nom);
        printf("%s vs %s \n",j1.nom,j2.nom);
        system("cls");

        initialiser_matrices(matj2);
        initialiser_matrices(matj1);
        initialiser_matrices(mataj1);
        initialiser_matrices(mataj2);

        printf("%s placez vos bateaux:\n",j1.nom);

        affichergrille(matj1);
        /****P:porte-avions***/

        placer(matj1,porte_avion);
        sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
        sauvtoutepartie(matj1,mataj2,pt,j1.nom,j2.nom);
        k=0;
        system("cls");
        affichergrille(matj1);
        /***C:CROISEUR***/

        placer(matj1,croiseur);
        sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
        sauvtoutepartie(matj1,mataj2,pt,j1.nom,j2.nom);
        k=0;
        system("cls");
        affichergrille(matj1);
        /******CT:Contre-Torpilleur******/
        placer(matj1,contre_torpilleur);
        sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
        sauvtoutepartie(matj1,mataj2,pt,j1.nom,j2.nom);
        k=0;
        system("cls");
        affichergrille(matj1);
        /******CT:Contre-Torpilleur2******/
        placer(matj1,contre_torpilleur);
        sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
        sauvtoutepartie(matj1,mataj2,pt,j1.nom,j2.nom);
        k=0;
        system("cls");
        affichergrille(matj1);
        /********T:Torpilleur******/

        placer(matj1,torpilleur);
        sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
        sauvtoutepartie(matj1,mataj2,pt,j1.nom,j2.nom);
        system("cls");
        affichergrille(matj1);
        printf("\n\n\nCliquer sur ENTER pour continuer!");
        fflush(stdin);
        gets(tempstr);
        srand(time(NULL));
        system("cls");
        printf("%s placez vos bateaux:\n",j2.nom);

        affichergrille(matj2);
        /*******porte-avions J2*******/
        /*******porte-avions*******/
        /*******porte-avions*******/
        /*******porte-avions*******/

        placer(matj2,porte_avion);
        sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
        sauvtoutepartie(mataj1,matj2,pt,j1.nom,j2.nom);
        k=0;
        system("cls");
        affichergrille(matj2);
        /********B:Croiseur********/
        /********B:Croiseur********/
        /********B:Croiseur********/
        /********B:Croiseur********/

        placer(matj2,croiseur);
        sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
        sauvtoutepartie(mataj1,matj2,pt,j1.nom,j2.nom);
        k=0;
        system("cls");
        affichergrille(matj2);
        /******Contre-Torpilleur********/
        /******Contre-Torpilleur********/
        /******Contre-Torpilleur********/
        /******Contre-Torpilleur********/
        /******Contre-Torpilleur********/
        placer(matj2,contre_torpilleur);
        sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
        sauvtoutepartie(mataj1,matj2,pt,j1.nom,j2.nom);
        k=0;
        system("cls");
        affichergrille(matj2);
        /******CT:Contre-Torpilleur2******/
        placer(matj2,contre_torpilleur);
        sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
        sauvtoutepartie(mataj1,matj2,pt,j1.nom,j2.nom);
        k=0;
        system("cls");
        affichergrille(matj2);
        /******Torpilleur*****/
        /******Torpilleur*****/
        /******Torpilleur*****/
        /******Torpilleur*****/
        placer(matj2,torpilleur);
        sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
        sauvtoutepartie(mataj1,matj2,pt,j1.nom,j2.nom);
        system("cls");
        affichergrille(matj2);
        printf("\n\n\nCliquer sur ENTER pour continuer!");
        fflush(stdin);
        gets(tempstr);
        srand(time(NULL));
        system("cls");



        for (;;)
        {
        
        /***joueur 1 frappe***/
            
        for (;;)
        {
        if(gagner!=17)
        {
                
                afficher_grille_double(mataj1,mataj2,j1.nom,j2.nom);
                printf("\n\nTour de %s ",j1.nom);
                printf("chosissez ou frapper x y : ");
                scanf("%d %d", &x,&y);
                if(x>9 || x<0 || y>9 || y<0 || matj2[x][y]=='X' || matj2[x][y]=='*')
                {
                    printf("tu ne peux pas tirer en ces coordonnees!!\n");
                    continue;
                }
                else
                {
                    if(matj2[x][y]=='P' || matj2[x][y]=='C'||matj2[x][y]=='T'||matj2[x][y]=='O')
                    {
                        if(mataj2[x][y]!='X')
                        {
                            mataj2[x][y]='X';
                            sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
                            sauvtoutepartie(matj1,mataj2,pt,j1.nom,j2.nom);
                            afficher_grille_double(mataj1,mataj2,j1.nom,j2.nom);
                            system("cls");
                            for(i=0;i<10;i++)
                                {
                                    for(j=0;j<10;j++)
                                    {
                                        if(mataj2[i][j]=='X')
                                            gagner++;
                                    }
                                }
                            gauche();
                            printf("\n************touche*******\n");
                            if (gagner == 17)
                            {
                                system("cls");
                                printf("\n%s a gagne !!!\n",j1.nom);
                                fin=clock();
                                tempspartie(debut,fin);
                                statistiquesfinale(mataj2,mataj1,j2.nom,j1.nom);
                                sauvgarderstatistiques(f,j1.nom,j2.nom,mataj2,mataj1,j2.nom,j1.nom,tempspartie(debut,fin));
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
                            mataj2[x][y]='*';
                            sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
                            sauvtoutepartie(matj1,mataj2,pt,j1.nom,j2.nom);
                            break;
                        }
                }
        }
        else
        {
            printf("\n%s a gagne!!!\n",j1.nom);
            fin=clock();
            tempspartie(debut,fin);
            statistiquesfinale(mataj2,mataj1,j2.nom,j1.nom);
            sauvgarderstatistiques(f,j1.nom,j2.nom,mataj2,mataj1,j2.nom,j1.nom,tempspartie(debut,fin));
            findujeu();
        }
    }
            system("cls");
        /***joueur 2 frappe***/
        
            for (;;)
        {
        if(gagner1!=17)
        {
                //affichergrille(mataj1);
                afficher_grille_double(mataj1,mataj2,j1.nom,j2.nom);
                printf("\n\nTour de %s ",j2.nom);
                printf("chosissez ou frapper x y : ");
                scanf("%d %d", &x,&y);
                if(x>9 || x<0 || y>9 || y<0 || matj1[x][y]=='X' || matj1[x][y]=='*')
                {
                    printf("tu ne peux pas tirer en ces coordonnees!!\n");
                    continue;
                }
                else
                {
                    if(matj1[x][y]=='P' || matj1[x][y]=='C'||matj1[x][y]=='T'||matj1[x][y]=='O')
                    {
                        if(mataj1[x][y]!='X')
                        {
                            mataj1[x][y]='X';
                            sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
                            sauvtoutepartie(mataj1,matj2,pt,j1.nom,j2.nom);
                            afficher_grille_double(mataj1,mataj2,j1.nom,j2.nom);
                            system("cls");
                            for(i=0;i<10;i++)
                                {
                                    for(j=0;j<10;j++)
                                    {
                                        if(mataj1[i][j]=='X')
                                            gagner1++;
                                    }
                                }
                            gauche();
                            printf("\n***********Touche*********\n");
                            if (gagner1 == 17)
                            {
                                system("cls");
                                printf("\n%s a gagne !!!\n",j2.nom);
                                fin=clock();
                                tempspartie(debut,fin);
                                statistiquesfinale(mataj1,mataj2,j1.nom,j2.nom);
                                sauvgarderstatistiques(f,j1.nom,j2.nom,mataj1,mataj2,j1.nom,j2.nom,tempspartie(debut,fin));
                                findujeu();
                                break;
                            }
                            gagner1 = 0;
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
                            mataj1[x][y]='*';
                            sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
                            sauvtoutepartie(mataj1,matj2,pt,j1.nom,j2.nom);
                            break;
                        }
                }
        }
        else
        {
            printf("\n%s a gagne!!!\n",j2.nom);
            fin=clock();
            tempspartie(debut,fin);
            statistiquesfinale(mataj1,mataj2,j1.nom,j2.nom);
            sauvgarderstatistiques(f,j1.nom,j2.nom,mataj1,mataj2,j1.nom,j2.nom,tempspartie(debut,fin));
            findujeu();
        }
    }
            system("cls");
        }

}
void tirer(char mat[10][10],char mata[10][10],char name[50],int g)
{
    for (;;)
    {
        if(g!=17)
        {
                affichergrille(mata);
                printf("\n\nTour de %s ",name);
                printf("chosissez ou frapper x y : ");
                scanf("%d %d", &x,&y);
                if(x>9 || x<0 || y>9 || y<0 || mata[x][y]=='X' || mata[x][y]=='*')
                {
                    printf("Vous ne pouvez pas tirer en ces coordonnees!!\n");
                    continue;
                }
                else
                {
                    if(mat[x][y]=='P' || mat[x][y]=='C'||mat[x][y]=='T'||mat[x][y]=='O')
                    {
                        if(mata[x][y]!='X')
                        {
                            mata[x][y]='X';
                            affichergrille(mata);
                            system("cls");
                            for(i=0;i<10;i++)
                                {
                                    for(j=0;j<10;j++)
                                    {
                                        if(mata[i][j]=='X')
                                            g++;
                                    }
                                }
                            gauche();
                            printf("\n***********Touche**********\n");
                            if (g == 17)
                            {
                                system("cls");
                                printf("\n%s a gagne !!!\n",name);
                                fin=clock();
                                tempspartie(debut,fin);
                                exit(1);
                                break;
                            }
                            g = 0;
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
                            mata[x][y]='*';
                            break;
                        }
                }
        }
        else
        {
            printf("\n%s a gagne!!!\n",name);
            fin=clock();
            tempspartie(debut,fin);
            exit(1);
        }
    }
}
void sauvegarder(char matrice1[10][10],char matrice2[10][10],char matrice3[10][10],char matrice4[10][10],FILE *f,char name1[15],char name2[15])
    {
        char nomfichier[150]="";

        strcat(nomfichier,name1);
        strcat(nomfichier,"vs");
        strcat(nomfichier,name2);
        strcat(nomfichier,".txt");
        f=fopen(nomfichier,"w+");
        int i,j;
        if(f==NULL)
        {
            printf("fichier inexistant!!");
            exit(1);
        }
        else
        {
            for(i=0;i<10;i++)
                {
                for(j=0;j<10;j++)
                    {
                        fprintf(f,"%c",matrice1[i][j]);
                        fprintf(f,"%s"," ");
                    }
                    fprintf(f,"%s","\n");
                }
                fprintf(f,"%s","\n\n");
            for(i=0;i<10;i++)
                {
                for(j=0;j<10;j++)
                    {
                        fprintf(f,"%c",matrice2[i][j]);
                        fprintf(f,"%s"," ");
                    }
                    fprintf(f,"%s","\n");
                }
                fprintf(f,"%s","\n\n");
            for(i=0;i<10;i++)
                {
                for(j=0;j<10;j++)
                    {
                        fprintf(f,"%c",matrice3[i][j]);
                        fprintf(f,"%s"," ");
                    }
                    fprintf(f,"%s","\n");
                }
                fprintf(f,"%s","\n\n");
            for(i=0;i<10;i++)
                {
                for(j=0;j<10;j++)
                    {
                        fprintf(f,"%c",matrice4[i][j]);
                        fprintf(f,"%s"," ");
                    }
                    fprintf(f,"%s","\n");
                }
        }
        fclose(f);
    }
void visualiser()
{   

    int s;
    centre();
    printf("Vous voulez Charger quelle partie:\n");
    gauche();
    printf("1:joueur vs ordinateur\n");
    gauche();
    printf("2:joueur1 vs joueur2\n");
    scanf("%d",&s);
    system("cls");
    if(s==2)
    {
        char nom1[50],nom2[50],nom[200],nom0[200];
        int n;
        FILE *f;
        centre();
        printf("Entrez le nom du joueur 1: ");
        scanf("%s",&nom1);
        gauche();
        printf("Entrez le nom du joueur 2: ");
        scanf("%s",&nom2);
        system("cls");
        strcat(nom,nom1);
        strcat(nom,"vs");
        strcat(nom,nom2);
        strcat(nom,"partie");
        strcat(nom,".txt");
        strcpy(nom0,nom);
        f=fopen(nom0,"r");
        if(f==NULL)
        {
            printf("partie inexistente");
            exit(1);
        }
        else{
        char tempstr[10];
        fseek(f,0,SEEK_SET);

        while(!feof(f))
        {
        affvisualiser(424,f);
        printf("Cliquez sur ENTRER pour continuer!");
        fflush(stdin);
        gets(tempstr);
        srand(time(NULL));
        system("cls");
        }
        }
    }

    else if (s==1)
    {

        char nomj[50],nom22[50],nom00[200];
        int n;
        FILE *f;
        centre();
        printf("Entrez le nom du joueur: ");
        scanf("%s",&nomj);
        system("cls");
        strcat(nom22,nomj);
        strcat(nom22,"vsordinateurpartie.txt");
        strcpy(nom00,nom22);
        f=fopen(nom00,"r");
        if(f==NULL)
            {
                printf("partie inexistente!!");
                exit(1);
            }
            else
            {
                char tempstr[10];
                fseek(f,0,SEEK_SET);
                while(!feof(f))
                {
                    affvisualiser(424,f);
                    printf("Cliquez sur ENTRER pour continuer!");
                    fflush(stdin);
                    gets(tempstr);
                    srand(time(NULL));
                    system("cls");
                }
            }
    }
}
void affvisualiser(int n,FILE *f)
{
    char z;
    for(i=0;i<n;i++)
    {
        fscanf(f,"%c",&z);
        printf("%c",z);
    }
}
float tempspartie(clock_t debut,clock_t fin)
{
    float temps_de_jeu;
    temps_de_jeu =(((float)(fin - debut))/(float)CLOCKS_PER_SEC);
    gauche();
    printf("votre partie a dure: ");
    affichertemps(temps_de_jeu);
    return temps_de_jeu;
}
void placervsordinateur(char mat[10][10],Bateau bateau,int t,int cord[t][2],char joueur[50])
{
    
    for (;;)
        {
            veri=0;
            centre();
            printf("%s (%d cases):\n",bateau.nom,t);
            gauche();
            printf("%s\n", joueur);
            gauche();
            printf("choisissez l'orientation du bateau\n");
            gauche();
            printf("Orientation(v/h): ");
            scanf("%s", &orin);
            gauche();
            printf("Entrez la ligne et la colonne : ");
            scanf("%d %d", &x, &y);
            if (strcmp(orin, "h") == 0)
            {
                if (y > 10-bateau.taillebateau || y < 0 || x > 9 || x < 0|| mat[x][y]=='P'||mat[x][y]=='C'||mat[x][y]=='O'||mat[x][y]=='T')
                {

                    system("cls");
                    system("cls");

                    gauche();

                    printf("Vous ne pouvez pas placer votre bateau ici!\n\n");
                    gauche();
                    printf("Essayez de nouveau!!\n\n\n");
                    affichergrille(mat);
                    continue;
                }
                else
                {
                    for(i=y;i<y+2;i++)
                    {
                        if(mat[x][i]!='.')
                        {
                            system("cls");
                            printf("Vous ne pouvez pas placer votre bateau ici\n");
                            affichergrille(mat);
                            veri=1;
                            break;
                        }
                    }
                    if(veri==1)
                        continue;
                    else{
                    for (i = y; i < y + bateau.taillebateau; i++)
                    {
                        mat[x][i] = bateau.symbole;
                        cord[k][0] = x;
                        cord[k][1] = i;
                        k++;
                    }
                    break;
                    }
                }
            }
            if (strcmp(orin, "v") == 0)
            {
                if (x > 10-bateau.taillebateau || x < 0 || y > 9 || y < 0|| mat[x][y]=='P'||mat[x][y]=='C'||mat[x][y]=='O'||mat[x][y]=='T')
                {

                    system("cls");
                    system("cls");
                    gauche();

                    printf("Vous ne pouvez pas placer votre bateau ici!\n\n");
                    gauche();
                    printf("Essayez de nouveau!!\n\n\n");

                    affichergrille(mat);
                    continue;
                }
                else
                {
                    for(i=x;i<x+2;i++)
                    {
                        if(mat[i][y]!='.')
                        {
                            system("cls");
                            printf("Vous ne pouvez pas placer votre bateau ici\n");
                            affichergrille(mat);
                            veri=1;
                            break;
                        }
                    }
                    if(veri==1)
                        continue;
                    else  
                    {   
                    for (i = x; i < x + bateau.taillebateau; i++)
                    {
                        mat[i][y] = bateau.symbole;
                        cord[k][0] = i;
                        cord[k][1] = y;
                        k++;
                    }
                    break;
                    }
                }
            }
        }
}
void placerordinateur(char mata[10][10],Bateau bateau)
{
    
    for (;;)
    {
        veri = 0;
        if (rand() % 2 == 1)
            strcpy(orin, "h");
        else
            strcpy(orin, "v");
        x = rand() % 10;
        y = rand() % 10;
        if (strcmp(orin, "h") == 0)
        {
            if (y > 10-bateau.taillebateau || y < 0 || x > 9 || x < 0)
            {
                continue;
            }
            else
            {
                for (i = y; i < y + bateau.taillebateau; i++)
                {
                    if (mata[x][i] != '.')
                    {
                        veri = 1;
                        break;
                    }
                }
                if (veri == 1)
                    continue;
                else
                {
                    for (i = y; i < y +bateau.taillebateau; i++)
                        mata[x][i] = bateau.symbole;
                    break;
                }
            }
        }
        if (strcmp(orin, "v") == 0)
        {
            if (x > 10-bateau.taillebateau || x < 0 || y > 9 || y < 0)
            {
                continue;
            }
            else
            {
                for (i = x; i < x + bateau.taillebateau; i++)
                {
                    if (mata[i][y] != '.')
                    {
                        veri = 1;
                        break;
                    }
                }
                if (veri == 1)
                    continue;
                else
                {
                    for (i = x; i < x + bateau.taillebateau; i++)
                        mata[i][y] = bateau.symbole;
                    break;
                }
            }
        }
    }
}
void sauvtoutepartie(char mat[10][10],char mata[10][10],FILE*f,char smiya[15],char smiya1[15])
{
    char nomfichier1[150]="";
        strcat(nomfichier1,smiya);
        strcat(nomfichier1,"vs");
        strcat(nomfichier1,smiya1);
        strcat(nomfichier1,"partie");
        strcat(nomfichier1,".txt");
        f=fopen(nomfichier1,"a+");
        int i,j;
        if(f==NULL)
        {
            printf("fichier inexistant!!");
            exit(1);
        }
        else
        {
            for(i=0;i<10;i++)
                {
                for(j=0;j<10;j++)
                    {
                        fprintf(f,"%c",mat[i][j]);
                        fprintf(f,"%s"," ");
                    }
                    fprintf(f,"%s","\n");
                }
                fprintf(f,"%s","\n\n");
            for(i=0;i<10;i++)
                {
                for(j=0;j<10;j++)
                    {
                        fprintf(f,"%c",mata[i][j]);
                        fprintf(f,"%s"," ");
                    }
                    fprintf(f,"%s","\n");
                }
                fprintf(f,"%s","\n\n");
            fclose(f); 
        }
}

void sauvgarderstatistiques(FILE *f,char joueur1[15],char joueur2[15],char matperdant[10][10],char matvainqueur[10][10],char jp[15],char jv[15],float secondes)
{
    char nomfichier[150]="";
    strcat(nomfichier,joueur1);
    strcat(nomfichier,"vs");
    strcat(nomfichier,joueur2);
    strcat(nomfichier,"stats");
    strcat(nomfichier,".txt");
    f=fopen(nomfichier,"w+");
    if(f==NULL)
        {
            printf("fichier inexistant!!");
            delay(2000);
            menu();
        }
    int heures = secondes /3600;
    secondes -= heures*3600;
    int minutes = secondes/60;
    secondes -= minutes*60;
    fprintf(f,"\n\tvotre partie a dure: ");
    fprintf(f,"%5s%dh:%s%dmin:%s%ds",heures > 9 ? "" : "0",heures,minutes > 9 ? "" : "0",minutes,secondes > 9 ? "" : "0",secondes);
    float precisionp;
    float touchep=0,ratep=0;
    for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (matvainqueur[i][j]=='*')
                {
                    ratep++;
                }
                if (matvainqueur[i][j]=='X')
                {
                    touchep++;
                }
            }
        }
    precisionp=(touchep*100)/(touchep+ratep);
    fprintf(f,"\n\n\t\t\t\t******score******\n");
    fprintf(f,"\n\t\t%s\n",jp);
    fprintf(f,"\tnombre de tirs rates; %.0lf\n",ratep);
    fprintf(f,"\tnombre de tirs reussis: %.0lf\n",touchep); 
    fprintf(f,"\tprecision : %.2lf/100\n",precisionp);
    float touchev=0,ratev=0;
    float precisionv=0;
    for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (matperdant[i][j]=='*')
                {
                    ratev++;
                }
                if (matperdant[i][j]=='X')
                {
                    touchev++;
                }
            }
        }
    fprintf(f,"\n\t\t %s \n",jv);
    precisionv=(touchev*100)/(17+ratev);
    fprintf(f,"\tnombre de tirs rates; %.2lf\n",ratev);
    fprintf(f,"\tprecision : %.2lf/100",precisionv);
}

void statistiques()
{
    int s;
    centre();
    printf("Vous voulez les statistiques de quelle partie ?:\n");
    gauche();
    printf("1:joueur vs ordinateur\n");
    gauche();
    printf("2:joueur1 vs joueur2\n");
    scanf("%d",&s);
    system("cls");
    if (s==1)
    {
        char nom1[15],nom2[15],nom[100]="";
        int n;
        char j;
        FILE *f;
        centre();
        printf("Entrez le nom du joueur: ");
        scanf("%s",&nom1);
        system("cls");

        strcat(nom,nom1);
        strcat(nom,"vs");
        strcat(nom,"ordinateur");
        strcat(nom,"stats");
        strcat(nom,".txt");
        f=fopen(nom,"r");
        if(f==NULL)
        {
            printf("partie inexistente");
            exit(1);
        }
        fseek(f,0,SEEK_SET);
        while (!feof(f))
        {
            fscanf(f,"%c",&j);
            
            printf("%c",j);
        }
        findujeu();
        fclose(f);
    }
    else if (s==2)
    {
        char nom1[15],nom2[15],nom[100]="";
        int n;
        char j;
        FILE *f;
        centre();
        printf("Entrez le nom du joueur1: ");
        scanf("%s",&nom1);
        system("cls");
        printf("Entrez le nom du joueur2: ");
        scanf("%s",&nom2);
        system("cls");
        strcat(nom,nom1);
        strcat(nom,"vs");
        strcat(nom,nom2);
        strcat(nom,"stats");
        strcat(nom,".txt");

        f=fopen(nom,"r");
        if(f==NULL)
        {
            printf("partie inexistente");
            exit(1);
        }
        fseek(f,0,SEEK_SET);
        while (!feof(f))
        {
            fscanf(f,"%c",&j);
            printf("%c",j);
        }
        fclose(f);
        findujeu();
    }

}
void charger()
{
    int t;
    printf("Vous voulez charger quelle partie:\n");
    printf("1:joueur vs ordinateur\n");
    printf("2:joueur1 vs joueur2\n");
    scanf("%d",&t);
    if(t==1)
        {
        char nom1[15],nom3[40]="";
        char nom2[20]="vsordinateur.txt";
        printf("ENTREZ VOTRE NOM: ");
        scanf("%s",&nom1);
        strcat(nom3,nom1);
        strcat(nom3,nom2);
        charger1(nom3,nom1);
        } 
        if(t==2)
        {
        char nom1[15],nom3[40]="";
        char nom2[20];  
        printf("ENTREZ LE NOM DU JOUEUR1 : ");
        scanf("%s",&nom1);
        printf("ENTREZ LE NOM DU JOUEUR2: "); 
        scanf("%s",&nom2); 
        strcat(nom3,nom1);
        strcat(nom3,"vs");
        strcat(nom3,nom2);
        strcat(nom3,".txt");
        charger2(nom3,nom1,nom2);
        } 
}

void charger1(char fichier[40],char nomjoueurcharger[15])
{
    int er;
    FILE *myFile;
    FILE *fdiff;
    char jf[50]="";
    strcat(jf,nomjoueurcharger);
    strcat(jf,"diff.txt");
    fdiff=fopen(jf,"r");
    myFile = fopen(fichier, "r");
    fseek(fdiff,0,SEEK_SET);
    while (!feof(fdiff))
    {
      fscanf(fdiff,"%d",&er);  
    }
    
    
    
    char matj[10][10];
    char matordi[10][10];
    char mataj[10][10];
    char mataordi[10][10];
    
    
    int i,j;
    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }
    /***/

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
        fscanf(myFile, "%c ", &matj[i][j]);
        }

    }

    fseek(myFile, 0, SEEK_CUR);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
        fscanf(myFile, "%c ", &matordi[i][j]);
        }

    }
        fseek(myFile, 0, SEEK_CUR);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
        fscanf(myFile, "%c ", &mataj[i][j]);
        }

    }
        fseek(myFile, 0, SEEK_CUR);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
        fscanf(myFile, "%c ", &mataordi[i][j]);
        }

    }
    int s,z;

    for( s=0;s<10;s++)
    {
        for( z=0;z<10;z++)
        {
            printf("%c ",mataj[s][z]);
        }
        printf("\n");
    }
    printf("\n TAB 1 \n");
    
    for( s=0;s<10;s++)
    {
        for( z=0;z<10;z++)
        {
            printf("%c ", mataordi[s][z]);
        }
        printf("\n");
    }
    

    int a = 0, b = 0, c = 0, d = 0,k=0, probab, diff, ch;
    diff=er;
    fclose(fdiff);
    int cordP[5][2], cordC[4][2], cordCT[3][2],cord2CT[3][2], cordT[2][2];
     diff=3;
    FILE*f;
    FILE*fp;
    char ordi[15]="ordinateur";
    for (;;)
    {
        for (;;)
    {
            system("cls");
            afficher_grille_double(mataj,mataordi,nomjoueurcharger,ordi);
            
            for (;;)
        {
            if (gagner!=17)
            {
                printf("\nEntrez la ligne  et la colonne: ");
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
                            sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                            sauvtoutepartie(mataj,mataordi,fp,nomjoueurcharger,ordi);
                            system("cls");
                            afficher_grille_double(mataj,mataordi,nomjoueurcharger,ordi);
                            for (i = 0; i < 10; i++)
                            {
                                for (j = 0; j < 10; j++)
                                {
                                    if (mataordi[i][j] == 'X')
                                        gagner++;
                                }
                            }
                            gauche();
                            printf("\n*************Touche*********\n");

                            if (gagner == 17)
                            {
                                printf("\nvous avez gagne!!!\n");
                                fin=clock();
                                tempspartie(debut,fin);
                                statistiquesfinale(mataordi,mataj,nomjoueurcharger,ordi);
                                sauvgarderstatistiques(f,nomjoueurcharger,ordi,mataordi,mataj,ordi,nomjoueurcharger,tempspartie(debut,fin));
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
                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                        sauvtoutepartie(mataj,mataordi,fp,nomjoueurcharger,ordi);
                        printf("rate\n");
                        break;
                    }
                }
            }
            else{
                    printf("\n *********** vous avez perdu!!!***********\n");
                    fin=clock();
                    tempspartie(debut,fin);
                    statistiquesfinale(mataj,mataordi,nomjoueurcharger,ordi);
                    sauvgarderstatistiques(f,nomjoueurcharger,ordi,mataj,mataordi,ordi,nomjoueurcharger,tempspartie(debut,fin));
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
                            sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                            system("cls");
                            afficher_grille_double(mataj,mataordi,nomjoueurcharger,ordi);
                            delay(1000);
                            printf("\n***********touche*********\n");
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
                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                            sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                            system("cls");
                            afficher_grille_double(mataj,mataordi,nomjoueurcharger,ordi);
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
                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                            sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                            system("cls");
                            affichergrille(mataordi);
                            printf("\n");
                            affichergrille(mataj);
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
                                    sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                    system("cls");
                                    affichergrille(mataordi);
                                    printf("\n");
                                    affichergrille(mataj);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
                                delay(1000);


                                x=x+1;
                                y=y;



                                }
                                }
                                    else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
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
                                    sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                    system("cls");
                                    affichergrille(mataordi);
                                    printf("\n");
                                    affichergrille(mataj);
                                    delay(1000);
                                }
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                        break;
                                    }




                            }
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
                                delay(1000);


                                x=x;
                                y=y+1;

                                }
                                }
                                else
                            {
                                mataj[x][y] = '*';
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
                                delay(1000);


                                x=x;
                                y=y+1;
                                }
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
                                delay(1000);}
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                        break;
                                    }



                                }
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
                                delay(1000);


                                x=x-1;
                                y=y;



                                }
                                }
                                else
                            {
                                mataj[x][y] = '*';
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
                                delay(1000);


                                x=x-1;
                                y=y;



                                }
                                }
                                    else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
                                delay(1000);}
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                        break;
                                    }



                                }
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
                                delay(1000);


                                x=x;
                                y=y-1;



                                }
                                }
                                else
                            {
                                mataj[x][y] = '*';
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
                                delay(1000);


                                x=x;
                                y=y-1;



                                }
                                }
                                    else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
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
                                sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                system("cls");
                                affichergrille(mataordi);
                                printf("\n");
                                affichergrille(mataj);
                                delay(1000);}
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
                                        break;
                                    }

                            }
                                }
                                else
                                    {
                                        mataj[x][y] = '*';
                                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                        sauvegarder(matj,matordi,mataj,mataordi,f,nomjoueurcharger,ordi);
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
                statistiquesfinale(mataordi,mataj,nomjoueurcharger,ordi);
                sauvgarderstatistiques(f,nomjoueurcharger,ordi,mataordi,mataj,ordi,nomjoueurcharger,tempspartie(debut,fin));
                findujeu();
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
                statistiquesfinale(mataj,mataordi,nomjoueurcharger,ordi);
                sauvgarderstatistiques(f,nomjoueurcharger,ordi,mataj,mataordi,ordi,nomjoueurcharger,tempspartie(debut,fin));
                findujeu();
                break;
            }
            gagner = 0;
    }
    }

}

void charger2(char fichier[40],char nomjoueur1charger[15],char nomjoueur2charger[15])
{
    FILE *myFile;
    
    myFile = fopen(fichier, "r");
;
char matj1[10][10],mataj1[10][10],matj2[10][10],mataj2[10][10],orin[2];
int gagner1;
FILE*f;
FILE*pt;

    
    int i,j;
    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }
    /***/

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
        fscanf(myFile, "%c ", &matj1[i][j]);
        }

    }

    fseek(myFile, 0, SEEK_CUR);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
        fscanf(myFile, "%c ", &matj2[i][j]);
        }

    }
        fseek(myFile, 0, SEEK_CUR);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
        fscanf(myFile, "%c ", &mataj1[i][j]);
        }

    }
        fseek(myFile, 0, SEEK_CUR);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
        fscanf(myFile, "%c ", &mataj2[i][j]);
        }

    }
    int s,z;

    for( s=0;s<10;s++)
    {
        for( z=0;z<10;z++)
        {
            printf("%c ",mataj1[s][z]);
        }
        printf("\n");
    }
    printf("\n TAB 1 \n");
    
    for( s=0;s<10;s++)
    {
        for( z=0;z<10;z++)
        {
            printf("%c ", mataj2[s][z]);
        }
        printf("\n");
    }
    for (;;)
        {
        
        /***joueur 1 frappe***/
            
        for (;;)
        {
        if(gagner!=17)
        {
                afficher_grille_double(mataj1,mataj2,nomjoueur1charger,nomjoueur2charger);
                printf("\n\nTour de %s ",nomjoueur1charger);
                printf("chosissez ou frapper x y : ");
                scanf("%d %d", &x,&y);
                if(x>9 || x<0 || y>9 || y<0 || matj2[x][y]=='X' || matj2[x][y]=='*')
                {
                    printf("tu ne peux pas tirer en ces coordonnees!!\n");
                    continue;
                }
                else
                {
                    if(matj2[x][y]=='P' || matj2[x][y]=='C'||matj2[x][y]=='T'||matj2[x][y]=='O')
                    {
                        if(mataj2[x][y]!='X')
                        {
                            mataj2[x][y]='X';
                            sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
                            sauvtoutepartie(matj1,mataj2,pt,j1.nom,j2.nom);
                            afficher_grille_double(mataj1,mataj2,nomjoueur1charger,nomjoueur2charger);
                            system("cls");
                            for(i=0;i<10;i++)
                                {
                                    for(j=0;j<10;j++)
                                    {
                                        if(mataj2[i][j]=='X')
                                            gagner++;
                                    }
                                }
                            gauche();
                            printf("\n************Touche*********\n");
                            if (gagner == 17)
                            {
                                system("cls");
                                printf("\n%s a gagne !!!\n",j1.nom);
                                fin=clock();
                                tempspartie(debut,fin);
                                statistiquesfinale(mataj2,mataj1,j2.nom,j1.nom);
                                sauvgarderstatistiques(f,j1.nom,j2.nom,mataj2,mataj1,j2.nom,j1.nom,tempspartie(debut,fin));
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
                            mataj2[x][y]='*';
                            sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
                            sauvtoutepartie(matj1,mataj2,pt,j1.nom,j2.nom);
                            break;
                        }
                }
        }
        else
        {
            printf("\n%s a gagne!!!\n",j1.nom);
            fin=clock();
            tempspartie(debut,fin);
            statistiquesfinale(mataj2,mataj1,j2.nom,j1.nom);
            sauvgarderstatistiques(f,j1.nom,j2.nom,mataj2,mataj1,j2.nom,j1.nom,tempspartie(debut,fin));
            findujeu();
        }
    }
            system("cls");
        /***joueur 2 frappe***/
        
            for (;;)
        {
        if(gagner1!=17)
        {
                afficher_grille_double(mataj1,mataj2,nomjoueur1charger,nomjoueur2charger);
                printf("\n\nTour de %s ",nomjoueur2charger);
                printf("chosissez ou frapper x y : ");
                scanf("%d %d", &x,&y);
                if(x>9 || x<0 || y>9 || y<0 || matj1[x][y]=='X' || matj1[x][y]=='*')
                {
                    printf("tu ne peux pas tirer en ces coordonnees!!\n");
                    continue;
                }
                else
                {
                    if(matj1[x][y]=='P' || matj1[x][y]=='C'||matj1[x][y]=='T'||matj1[x][y]=='O')
                    {
                        if(mataj1[x][y]!='X')
                        {
                            mataj1[x][y]='X';
                            sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
                            sauvtoutepartie(mataj1,matj2,pt,j1.nom,j2.nom);
                            afficher_grille_double(mataj1,mataj2,nomjoueur1charger,nomjoueur2charger);
                            system("cls");
                            for(i=0;i<10;i++)
                                {
                                    for(j=0;j<10;j++)
                                    {
                                        if(mataj1[i][j]=='X')
                                            gagner1++;
                                    }
                                }
                            gauche();
                            printf("\n********Touche*********\n");
                            if (gagner1 == 17)
                            {
                                system("cls");
                                printf("\n%s a gagne !!!\n",j2.nom);
                                fin=clock();
                                tempspartie(debut,fin);
                                statistiquesfinale(mataj1,mataj2,j1.nom,j2.nom);
                                sauvgarderstatistiques(f,j1.nom,j2.nom,mataj1,mataj2,j1.nom,j2.nom,tempspartie(debut,fin));
                                findujeu();
                                break;
                            }
                            gagner1 = 0;
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
                            mataj1[x][y]='*';
                            sauvegarder(matj1,matj2,mataj1,mataj2,f,j1.nom,j2.nom);
                            sauvtoutepartie(mataj1,matj2,pt,j1.nom,j2.nom);
                            break;
                        }
                }
        }
        else
        {
            printf("\n%s a gagne!!!\n",j2.nom);
            fin=clock();
            tempspartie(debut,fin);
            statistiquesfinale(mataj1,mataj2,j1.nom,j2.nom);
            sauvgarderstatistiques(f,j1.nom,j2.nom,mataj1,mataj2,j1.nom,j2.nom,tempspartie(debut,fin));
            findujeu();
        }
    }
            system("cls");
        }
}
void statistiquesfinale(char matperdant[10][10],char matvainqueur[10][10],char jp[15],char jv[15])
{
    float precisionp;
    float touchep=0,ratep=0;
    for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (matvainqueur[i][j]=='*')
                {
                    ratep++;
                }
                if (matvainqueur[i][j]=='X')
                {
                    touchep++;
                }
            }
        }
    precisionp=(touchep*100)/(touchep+ratep);
    printf("\n\n\t\t\t\t******score******\n");
    printf("\n\t\t%s\n",jp);
    printf("\tnombre de tirs rates; %.0lf\n",ratep);
    printf("\tnombre de tirs reussis: %.0lf\n",touchep); 
    printf("\tprecision : %.2lf %\n",precisionp);
    float touchev=0,ratev=0;
    float precisionv=0;
    for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (matperdant[i][j]=='*')
                {
                    ratev++;
                }
                if (matperdant[i][j]=='X')
                {
                    touchev++;
                }
            }
        }
    printf("\n\t\t %s \n",jv);
    precisionv=(touchev*100)/(17+ratev);
    printf("\tnombre de tirs rates; %.2lf/100\n",ratev);
    printf("\tprecision : %.2lf/100",precisionv);
    


}
void afficher_grille_double(char mat1[10][10],char mat2[10][10],char j1[15],char j2[15])
{
    printf("\n\n\n\n\n");   
    printf("    ");
    gauche();
    for ( i = 0; i < 10; i++)
        printf("%d   ",i);
    printf("\t\t");    
    printf("    ");
    for ( i = 0; i < 10; i++)
        printf("%d   ",i);
    printf("\n    ");
    gauche();
    for ( i = 0; i < 10; i++)
        printf("_   ");
    printf("\t\t");    
    printf("    ");
    for ( i = 0; i < 10; i++)
        printf("_   ");    
    
    printf("\n");    
    
    for (int i = 0; i < 10; i++)
    {
        gauche();
        printf("%d|  ",i);
        for (int j = 0; j < 10; j++)
        {
            printf("%c   ",mat1[i][j]);
        }
        printf("\t\t");
        printf("%d|  ",i);
        for (int j = 0; j < 10; j++)
        {
            
            printf("%c   ",mat2[i][j]);         
        }
        printf("\n\n");
        
    }
    printf("\n");
    gauche();
    printf("    ***************%s****************\t\t\t***************%s***************",j1,j2);
}

void findujeu()
{
    int z;
    printf("\n\nla partie est termine\n\t1)retour au menu\n\t2)quitter le jeu");
    printf("\ntapez votre choix: ");
    scanf("%d",&z);
    if (z==1)
    {
        menu();
    }
    else
    {
        exit(1);
    }
}
void affichertemps (int secondes)
    
{
    int heures = secondes /3600;
    secondes -= heures*3600;
    int minutes = secondes/60;
    secondes -= minutes*60;
    printf("%5s%dh:%s%dmin:%s%ds",heures > 9 ? "" : "0",heures,minutes > 9 ? "" : "0",minutes,secondes > 9 ? "" : "0",secondes);
}