#include"bataillenavale_fonctions.h"

int main()
{
    
    system("color 1C");
    printf("\n\n\n\n");
    printf("\n\n\n\n");
    printf("\t\t\t\t**********             ***         ***************       ***           ***   ***         ***         **********\n");
    delay(100);
    printf("\t\t\t\t***********           ** **        ***************      ** **          ***   ***         ***         **********\n");
    delay(100);
    printf("\t\t\t\t**     *****         **   **             ***           **   **         ***   ***         ***         ***\n");
    delay(100);
    printf("\t\t\t\t**      ***         **     **            ***          **     **        ***   ***         ***         ***\n");
    delay(100);
    printf("\t\t\t\t**********         ***********           ***         ***********       ***   ***         ***         **********\n");
    delay(100);
    printf("\t\t\t\t**********        *************          ***        *************      ***   ***         ***         **********\n");
    delay(100);
    printf("\t\t\t\t**      ***      **           **         ***       **           **     ***   ***         ***         ***\n");
    delay(100);
    printf("\t\t\t\t**     *****    **             **        ***      **             **    ***   ***         ***         ***\n");
    delay(100);
    printf("\t\t\t\t***********    **               **       ***     **               **   ***   **********  **********  **********\n");
    delay(100);
    printf("\t\t\t\t**********    **                 **      ***    **                 **  ***   **********  **********  **********\n\n");



    printf("\t\t\t\t\t\t***        **          ***     **                **   ***           ***         **********\n");
    delay(100);
    printf("\t\t\t\t\t\t****       **         ** **     **              **   ** **          ***         **********\n");
    delay(100);
    printf("\t\t\t\t\t\t** **      **        **   **     **            **   **   **         ***         ***\n");
    delay(100);
    printf("\t\t\t\t\t\t**  **     **       **     **     **          **   **     **        ***         ***\n");
    delay(100);
    printf("\t\t\t\t\t\t**   **    **      ***********     **        **   ***********       ***         **********\n");
    delay(100);
    printf("\t\t\t\t\t\t**    **   **     *************     **      **   *************      ***         **********\n");
    delay(100);
    printf("\t\t\t\t\t\t**     **  **    **           **     **    **   **           **     ***         ***\n");
    delay(100);
    printf("\t\t\t\t\t\t**      ** **   **             **     **  **   **             **    ***         ***\n");
    delay(100);
    printf("\t\t\t\t\t\t**       ****  **               **     ****   **               **   **********  **********\n");
    delay(100);
    printf("\t\t\t\t\t\t**        *** **                 **     **   **                 **  **********  **********\n");
    delay(3000);
    system("color 0F");
    int i;
    char str[20] = "Bataille Navale", std[20] = "Bataille Navale", str1[100] = "Realise par: Mohamed HEJBANE, Abdellah KERBAL et Ahmed SABOUNI.";

    centre();
    for (i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
        delay(60);
    }
    
    printf("\n");

    for (i = 0; i < 20; i++)
    {
        printf(" ");
    }

    for (i = 0; str1[i] != '\0'; i++)
    {
        printf("%c", str1[i]);
        delay(60);
    }
    delay(2000);
    delay(200);
    system("cls");
    centre();
    delay(200);
    for (i = 0; std[i] != '\0'; i++)
    {
        printf("%c", std[i]);
        delay(60);
    }
    
    menu();
}






