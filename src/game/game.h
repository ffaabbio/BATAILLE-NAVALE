#include <stdio.h>
#include <stdlib.h>
#ifndef GAME_H
#define GAME_H

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int rows;
    int cols;
    char ** board;
    Boat * boats;

} Map;


int attackAvailable();
char ** attack();
void printResultAttack();
int newGame();
void endGame();



#endif