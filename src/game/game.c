#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "../include/include.h"


//boats est un tableau de tableau de positions, chaque tableau de positions doit finir par une position qui vaut -1 -1
void initBoats(Map * map,Position *** boatsPositions) {
    //Toujous 5 bateaux au debut du jeu
     for (int i = 0; i < 5; i++) {
         int len = 0;
         for (int j = 0; boatsPositions[i][j]->x != -1; j++) {
             map->boats[i]->positions[j] = malloc(sizeof(Position *));
             map->boats[i]->positions[j]->x = boatsPositions[i][j]->x;
             map->boats[i]->positions[j]->y = boatsPositions[i][j]->y;
             len++;
         }
         map->boats[i]->lenght = len;
         map->boats[i]->hit = 0;
         map->boats[i]->sunk = 0;
         if (len == 5) {
             strcpy(map->boats[i]->name,"Carrier");
         }
         if (len == 4) {
             strcpy(map->boats[i]->name,"Battleship");
         }
         if (len == 3) {
             strcpy(map->boats[i]->name,"Cruser");
         }
         if (len == 2) {
             strcpy(map->boats[i]->name,"Destroyer");
         }
     }
}
int newGame(Map *map1, Map *map2) {
    int winner = 0;
    int lap = 0;
    while (winner<1) {
        Position pos;
        int a = 0,b = 0;
        int * successfull = &a;
        int * touch = &b;
        char ** errorMessages;
        strcpy(errorMessages[0]," ");
        strcpy(errorMessages[1]," ");
        if (lap%2 != 0 || lap != 0) {
            printf("Joueur 1, veuillez rentrer la position de votre attaque :(x, y)\n");
            scanf("(%d, %d)",&pos.x,&pos.y);
            map2  = attack(map2,pos,successfull,touch,errorMessages);
            printResultAttack(successfull,touch,errorMessages);
            if (*successfull) {
                lap++;
            }
        }
        else if (lap%2 == 0 || lap == 0) {
            printf("Joueur 2, veuillez rentrer la position de votre attaque :(x, y)\n");
            scanf("(%d, %d)",&pos.x,&pos.y);
            map1  = attack(map1,pos,successfull,touch,errorMessages);
            printResultAttack(successfull,touch,errorMessages);
            if (*successfull) {
                lap++;
            }
        }
    }

    //!!!! PENSER A FREE !!!!
}
int attackAvailable(Map *map,Position attack,char ** errorMessages) {
    if ( attack.x >= map->rows || attack.x <= 0 || attack.y <0 || attack.y >= map->cols ) {
        errorMessages[0] = "Vous essayez d'attaquer en dehors du plateau !\0";
        //Vous essayez d'attaquer en dehors du plateau ! 46 + \0
        return 0;
    }
    if (map->board[map->rows][map->cols] == 'O' || map->board[map->rows][map->cols] == 'X') {
        errorMessages[1] = "Vous avez déjà attaqué cet endroit !\0";
        //Vous avez déjà attaqué cet endroit !
        return 0;
    }
    return 1;
}

Map * attack(Map *map,Position  positionAttack,int * succesfull, int * touch, char ** errorMessages) {
    if (!attackAvailable(map,positionAttack,errorMessages)) {
        *succesfull = 0;
        return map;
    }
    *succesfull = 1;

    if (map->board[positionAttack.y][positionAttack.x] == 'A' || map->board[positionAttack.y][positionAttack.x] =='B' || map->board[positionAttack.y][positionAttack.x] == 'C' || map->board[positionAttack.y][positionAttack.x] == 'D') {
        *touch = 1;
        map->board[positionAttack.y][positionAttack.x] = 'X';
    }
    if (map->board[positionAttack.y][positionAttack.x] == '.') {
        *touch = 0;
        map->board[positionAttack.y][positionAttack.x] = 'O';
    }
    return map;
}

void printResultAttack(int * successfull,int *touch,char ** errorMessages) {
    if (!successfull) {
        for (int i = 0; i < 2; i++) {
            printf("%s\n",errorMessages[i]);
            errorMessages[i] = " ";
        }

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