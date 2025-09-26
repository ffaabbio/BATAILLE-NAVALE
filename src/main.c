#include "include/include.h"
#include <stdio.h>
#include <stdlib.h>
#include "board/board.h"
#include "game/game.h"


int main(void) {
    int rows,cols;
    while (1) {
        printf("Enter the number of rows (5-20): ");
        if (scanf("%d", &rows) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter the number of cols (5-20): ");
        if (scanf("%d", &cols) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (rows >= 5 && rows <= 20 && cols >= 5 && cols <= 20) {
            break;
        }

        printf("Please enter numbers between 5 and 20.\n");
    }
    printf("Veuillez rentrer la taille des plateaux\n");
    char ** board1 = createMap(rows,cols);
    display_map(board1, rows, cols);
    printf("\n");
    char ** board2 = createMap(rows,cols);
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