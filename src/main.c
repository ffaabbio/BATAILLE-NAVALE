#include "include/include.h"
#include <stdio.h>
#include <stdlib.h>
#include "board/board.h"
#include "game/game.h"


int main(void) {
    int rows,cols;
    while (1) {
        printf("Entrez le nombre de lignes (1-20): ");
        if (scanf("%d", &rows) != 1) {
            printf("Entrée invalide !  Veuillez entrer un nombre entier.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Entrez le nombre de colonnes (1-20): ");
        if (scanf("%d", &cols) != 1) {
            printf("Entrée invalide !  Veuillez entrer un nombre entier.\n");
            while (getchar() != '\n');
            continue;
        }

        if (rows >= 5 && rows <= 20 && cols >= 5 && cols <= 20) {
            break;
        }

        printf("Veuillez entrer un nombre entre 1 et 20.\n");
    }
    FILE * f = fopen("config/config.txt","w");
    fprintf(f,"%d %d",rows,cols);
    fclose(f);

    f = fopen("config/config.txt","r");

    int height,width;
    fscanf(f,"%d %d",&height,&width);
    printf("Veuillez rentrer la taille des plateaux\n");
    char ** board1 = createMap(height,width);
    display_map(board1, rows, cols);
    printf("\n");
    char ** board2 = createMap(height,width);
    display_map(board2, rows, cols);
    Boat *boat1 = malloc(sizeof(Boat) * 3);
    Boat *boat2 = malloc(sizeof(Boat) * 3);
    get_position_of_cheap(board1, board2, rows, cols, boat1, boat2);


    while(1) {


        printf("PLAYER 1 >>>>>>>>");
        test(board2,rows,cols);
        printf("PLAYER 2 >>>>>>>>");
        test(board1,rows,cols);


    }


    return 0;
}