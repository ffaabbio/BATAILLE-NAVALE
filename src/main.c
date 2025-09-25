#include <stdio.h>
#include <stdlib.h>
#include "board/board.h"
#include "game/game.h"

int main(void) {
    int rows,cols;
    while (1) {
        printf("Enter the number of rows (1-99): ");
        if (scanf("%d", &rows) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter the number of cols (1-99): ");
        if (scanf("%d", &cols) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (rows >= 1 && rows <= 20 && cols >= 1 && cols <= 20) {
            break;
        }

        printf("Please enter numbers between 1 and 99.\n");
    }
    printf("Veuillez rentrer la taille des plateaux\n");
    char ** board1 = createMap(rows,cols);
    char ** board2 = createMap(rows,cols);

    return 0;
}