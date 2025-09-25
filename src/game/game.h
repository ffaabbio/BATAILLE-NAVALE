#include <stdio.h>
#include <stdlib.h>
#ifndef GAME_H
#define GAME_H

typedef struct Position {
    int x;
    int y;
} Position;

typedef struct Boat {
    Position begPosition;
    Position endPosition;
    int length;
    int hit;
    int sunk;
} Boat;

int attackAvailable();
char ** attack();
void printResultAttack();
int newGame();
void endGame();

#endif