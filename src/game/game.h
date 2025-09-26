#include <stdio.h>
#include <stdlib.h>

#ifndef GAME_H
#define GAME_H

#include "../include/include.h"

typedef struct {
    int rows;
    int cols;
    char ** board;
    Boat ** boats;

} Map;


int attackAvailable();
Map * attack();
void printResultAttack();
int newGame();
void endGame();
void initBoats();



#endif