#include "include/include.h"
#include <stdio.h>
#include <stdlib.h>
#include "board/board.h"
#include "game/game.h"


int main(void) {
    int rows,cols;
    while (1) {
        printf("Enter the number of rows (1-20): ");
        if (scanf("%d", &rows) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter the number of cols (1-20): ");
        if (scanf("%d", &cols) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (rows >= 1 && rows <= 20 && cols >= 1 && cols <= 20) {
            break;
        }

        printf("Please enter numbers between 1 and 20.\n");
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
    map1->boats = malloc(sizeof(Boat *) * 5);
    map2->boats = malloc(sizeof(Boat *) * 5);

    Position *** boatsPos1 = malloc(sizeof(Position **) * 5);
    for (int i = 0; i <6;i++) {
        boatsPos1[i] = malloc(sizeof(Position *) * 6);
    }
    Position *** boatsPos2 = malloc(sizeof(Position **) * 5);
    for (int i = 0; i <6;i++) {
        boatsPos2[i] = malloc(sizeof(Position *) * 6);
    }
    initBoats(map1,placeBoats(map1,boatsPos1));
    initBoats(map2,placeBoats(map2,boatsPos2));

    printf("Bateaux créés avec succès !");



    return 0;
}