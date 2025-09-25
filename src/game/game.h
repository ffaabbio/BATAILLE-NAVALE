#include <stdio.h>
#include <stdlib.h>
#ifndef GAME_H
#define GAME_H

typedef struct Position {
    int x;
    int y;
} Position;


int attackAvailable();
char ** attack();
void printResultAttack();
int newGame();
void endGame();

#endif