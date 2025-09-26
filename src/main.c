#include "include/include.h"
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

    Map *map1 = malloc(sizeof(Map));
    Map *map2 = malloc(sizeof(Map));
    map1->board = createMap(rows,cols);
    map1->rows = rows;
    map1->cols = cols;
    map2->board = createMap(rows,cols);
    map2->rows = rows;
    map2->cols = cols;

    char ** board2 = createMap(rows,cols);
    map1->boats = malloc(sizeof(Boat *) * 3);
    map2->boats = malloc(sizeof(Boat *) * 3);
    get_position_of_cheap(map1->board, map2->board, rows, cols, map1->boats[0], map2->boats[0]);


    return 0;
}