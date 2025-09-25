#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int newGame(int rows,int cols,char ** map1, char ** map2) {
    int winner = 0;
    int lap = 0;
    while (winner<1) {
        if (lap%2 == 0 || lap == 0) {

        }
    }
}
int attackAvailable(int width,int height,char ** board,Position attack,char ** errorMessages) {
    if ( attack.x >= width || attack.x <= 0 || attack.y <0 || attack.y >= height ) {
        errorMessages[0] = "Vous essayez d'attaquer en dehors du plateau !\0";
        //Vous essayez d'attaquer en dehors du plateau ! 46 + \0
        return 0;
    }
    if (board[height][width] == 'O' || board[height][width] == 'X') {
        errorMessages[0] = "Vous avez déjà attaqué cet endroit !\0";
        //Vous avez déjà attaqué cet endroit !
        return 0;
    }
    return 1;
}

char ** attack(int width, int height, char ** board,Position attack,int * succesfull, int * touch) {
    char ** errorMessages = malloc(sizeof(char *) * 2);
    for (int i = 0; i < 2; i++) {
        errorMessages[i] = malloc(sizeof(char ) * 47);
    }


    if (!attackAvailable(width,height,board,attack,errorMessages)) {
        *succesfull = 0;
        return errorMessages;
    }
    *succesfull = 1;

    if (board[attack.y][attack.x] == 'B') {
        *touch = 1;
        board[attack.y][attack.x] = 'X';
    }
    if (board[attack.y][attack.x] == '.') {
        *touch = 0;
        board[attack.y][attack.x] = 'O';
    }
}

void printResultAttack(int width,int height,char ** board,Position attack,int * successfull,int *touch,char ** errorMessages) {
    if (!successfull) {
        for (int i = 0; i < 2; i++) {
            printf("%s\n",errorMessages[i]);
            free(errorMessages[i]);
        }
        free(errorMessages);

    }
    if (*successfull) {
        if (*touch) {
            printf("Vous avez fait mouche !\n");
        }
        else {
            printf("Vous avez fait plouf !");
        }
    }
}