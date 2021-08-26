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