#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"


//boats est un tableau de tableau de positions, chaque tableau de positions doit finir par une position qui vaut -1 -1
void initBoats(Map * map,Position ** boats) {
    //Toujous 5 bateaux au debut du jeu
     for (int i = 0; i < 5; i++) {
         int len = 0;
         for (int j = 0; boats[i][j].x != -1; j++) {
             map->boats[i].positions[j] = boats[i][j];
             len++;
         }
         map->boats[i].length = len;
     }
}
int newGame(Map *map1, Map *map2) {
    int winner = 0;
    int lap = 0;
    while (winner<1) {
        Position pos;
        int a = 0,b = 0;
        int * succesfull = &a;
        int * touch = &b;
        char ** errorMessages;
        strcpy(errorMessages[0]," ");
        strcpy(errorMessages[1]," ");
        if (lap%2 != 0 || lap != 0) {
            printf("Joueur 1, veuillez rentrer la position de votre attaque :(x, y)\n");
            scanf("(%d, %d)",&pos.x,&pos.y);
            map2  = attack(map2,pos,succesfull,touch,errorMessages);
            printResultAttack(successfull,touch,errorMessages);
            if (*successfull) {
                lap++;
            }
        }
        else if (lap%2 == 0 || lap == 0) {
            printf("Joueur 2, veuillez rentrer la position de votre attaque :(x, y)\n");
            scanf("(%d, %d)",&pos.x,&pos.y);
            map1.board  = attack(map1,pos,succesfull,touch,errorMessages);
            printResultAttack(successfull,touch,errorMessages);
            if (*successfull) {
                lap++;
            }
        }
    }

    //!!!! PENSER A FREE !!!!
}
int attackAvailable(Map *map,Position attack,char ** errorMessages) {
    if ( attack.x >= rows || attack.x <= 0 || attack.y <0 || attack.y >= cols ) {
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

Map * attack(Map *map,Position attack,int * succesfull, int * touch, char ** errorMessages) {
    if (!attackAvailable(map,attack,errorMessages)) {
        *succesfull = 0;
        return map;
    }
    *succesfull = 1;

    if (map->board[attack.y][attack.x] == 'A' || map->board[attack.y][attack.x] =='B' || map->board[attack.y][attack.x] == 'C' || map->board[attack.y][attack.x] == 'D') {
        *touch = 1;
        map->board[attack.y][attack.x] = 'X';
    }
    if (map->board[attack.y][attack.x] == '.') {
        *touch = 0;
        map->board[attack.y][attack.x] = 'O';
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