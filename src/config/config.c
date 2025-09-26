#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../board/board.h"
#include "../include/include.h"
#include "../game/game.h"

Position *** placeBoats(Map * map,Position *** boatsPos) {
    int cpt = 0;
    while (cpt!= 5) {
        Position begPos,endPos ;
        int isAbort = 0;

        printf("Veuillez entrer la position du debut de votre bateau(x, y): ");
        scanf("%d, %d",&begPos.x,&begPos.y);
        printf("Veuillez entrer la position de la fin de votre bateau(x, y): ");
        scanf("%d, %d",&endPos.x,&endPos.y);

        if (begPos.x >= map->cols || begPos.x < 0 || begPos.y >= map->rows || begPos.y < 0 || endPos.x >= map->cols || endPos.x < 0 || endPos.y >= map->rows || endPos.y < 0) {
            printf("Vous essayez de placer votre bateau en dehors de votre plateau !\n");
            isAbort = 1;
        }
        if (begPos.x == endPos.x && begPos.y == endPos.y) {
            printf("Vous ne pouvez pas placer votre bateau en diagonale !");
            isAbort = 1;
        }
        for (int i = begPos.y;i <=endPos.y;i++) {
            for (int j = begPos.x;j<=endPos.x;j++) {
                if (map->board[i][j] != '.') {
                    printf("Vous essayez de superposer vos bateaux !\n");
                    isAbort = 1;
                    break;
                }
            }
        }
        if (!isAbort) {
            if (begPos.x != endPos.x) {
                for (int i = 0;i < endPos.x - begPos.x; i++) {
                    boatsPos[cpt][i]->x = begPos.x + i;
                    boatsPos[cpt][i]->y = begPos.y;
                }
            }
            if (begPos.y != endPos.y) {
                for (int i = 0;i < endPos.y - begPos.y; i++) {
                    boatsPos[cpt][i]->y = begPos.y + i;
                    boatsPos[cpt][i]->x = begPos.x;
                }
            }
            cpt++;
        }
    }
    return boatsPos;
}

/*void display_map2(char **map, int x, int y)
{
    printf("   ");
    for (int i = 0; i < y; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < x; i++) {
        if (i < 9)
            printf("%d  %s\n", i + 1, map[i]);
        else
            printf("%d %s\n", i + 1, map[i]);
    }
}

int check_if_number(char *a, char *b) {
    for (int i = 0; i < strlen(a); i++) {
        if (!isdigit(a[i]))
            return 0;
    }
    for (int i = 0; i < strlen(b); i++) {
        if (!isdigit(b[i]))
            return 0;
    }
    return 1;
}

void add_boat_to_map(char **navy1, int posx1, int posx2, int posy1, int posy2, int x, int y, char a, Boat **boat1, int z)
{
    int size_of_boat = 0;
    int index = 0;

    if (posx1 == posx2) {
        if (posy1 > posy2) {
            size_of_boat = posy1 - posy2;
        } else {
            size_of_boat = posy2 - posy1;
        }
    }

    if (posy1 == posy2) {
        if (posx1 > posx2) {
            size_of_boat = posx1 - posx2;
        } else {
            size_of_boat = posx2 - posx1;
        }
    }
    boat1[z]->positions = malloc(sizeof(Positions*) * size_of_boat + 1);
    for (int k = 0; k < size_of_boat + 1; k++) {
        boat1[z]->positions[k] = malloc(sizeof(Positions));
    }
    boat1[z]->length = size_of_boat + 1;
    if (posx1 == posx2) {
        if (posy1 > posy2) {
            for (int i = posy1; i >= posy2; i--) {
                boat1[z]->positions[index]->x = posx1;
                boat1[z]->positions[index]->y = i;
                index++;
                navy1[posx1][i] = a;
            }
        } else {
            for (int i = posy1; i <= posy2; i++) {
                boat1[z]->positions[index]->x = posx1;
                boat1[z]->positions[index]->y = i;
                index++;
                navy1[posx1][i] = a;
            }
        }
    }
    if (posy1 == posy2) {
        if (posx1 > posx2) {
            for (int i = posx1; i >= posx2; i--) {
                boat1[z]->positions[index]->x = i;
                boat1[z]->positions[index]->y = posy1;
                index++;
                navy1[i][posy1] = a;
            }
        } else {
            for (int i = posx1; i <= posx2; i++) {
                boat1[z]->positions[index]->x = i;
                boat1[z]->positions[index]->y = posy1;
                index++;
                navy1[i][posy1] = a;
            }
        }
    }
    display_map(navy1, x, y);

}

int check_if_already_boat(char **navy1, int posx1, int posx2, int posy1, int posy2) {
    if (posx1 == posx2) {
        if (posy1 > posy2) {
            for (int i = posy1; i >= posy2; i--) {
                if (navy1[posx1][i] != '.')
                    return 0;
            }
        } else {
            for (int i = posy1; i <= posy2; i++) {
                if (navy1[posx1][i] != '.')
                    return 0;
            }
        }
    }
    if (posy1 == posy2) {
        if (posx1 > posx2) {
            for (int i = posx1; i >= posx2; i--) {
                if (navy1[i][posy1] != '.')
                    return 0;
            }
        } else {
            for (int i = posx1; i <= posx2; i++) {
                if (navy1[i][posy1] != '.')
                    return 0;
            }
        }
    }
    return 1;
}

void get_position_of_cheap(char **navy1, char **navy2, int x, int y, Boat **boat1, Boat **boat2)
{
    int position_finded = 0;
    char new_position[20];
    char *a;
    char *b;
    char déco[3][20] = {"Premier", "Deuxiéme", "Troisiéme"};
    int posx1;
    int posy1;
    int posx2;
    int posy2;
    char name_of_boat = 'a';

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            navy1[i][j] = '.';
            navy2[i][j] = '.';
        }
    }
    // tour de boucle pour créer les bateaux des deux joueurs
    for (int navy = 0; navy < 2; navy++) {
        if (navy == 0)
            printf("PLAYER 1 >>\n");
        else
            printf("PLAYER 2 >>\n");
        // créer les 3 bateaux par joueurs
        for (int i = 0; i < 3; i++) {
            printf("Entrez la premiere positions du %s bateau sous la form (ligne, colon) : ", déco[i]);
            while (!position_finded) {
                fgets(new_position, sizeof(new_position), stdin);
                size_t len = strlen(new_position);
                if (len > 0 && new_position[len - 1] == '\n') {
                    new_position[len - 1] = '\0';
                }
                a = strtok(new_position, "(,)    \t\n\0");
                b = strtok(NULL, "(,)    \t\n\0");
                if (a == NULL && b == NULL) {
                    printf("Entrer une positions : ");
                    continue;
                }
                if (check_if_number(a, b) == 1) {
                    posx1 = atoi(a) - 1;
                    posy1 = atoi(b) - 1;
                    if ((posx1 >= 0 && posx1 < x) && (posy1 >= 0 && posy1 < y))
                        position_finded = 1;
                    else
                        printf("Entrer une positions dans l'interval : ");
                } else{
                    printf("Entrer une positions : ");
                }
            }
            position_finded = 0;
            printf("Entrez la deuxiéme positions du %s bateau sous la form (ligne, colon) : ", déco[i]);
            while (!position_finded) {
                fgets(new_position, sizeof(new_position), stdin);
                size_t len = strlen(new_position);
                if (len > 0 && new_position[len - 1] == '\n') {
                    new_position[len - 1] = '\0';
                }
                a = strtok(new_position, "(,)    \t\n\0");
                b = strtok(NULL, "(,)    \t\n\0");
                if (a != NULL && b != NULL && check_if_number(a, b) == 1) {
                    posx2 = atoi(a) - 1;
                    posy2 = atoi(b) - 1;
                    printf("Une pomme ");
                    if ((posx2 >= 0 && posx2 < x) && (posy2 >= 0 && posy2 < y))
                        if ((posx1 == posx2 || posy1 == posy2)) {
                            if (navy == 0 && check_if_already_boat(navy1, posx1, posx2, posy1, posy2) == 1 || navy == 1 && check_if_already_boat(navy2, posx1, posx2, posy1, posy2) == 1) {
                                position_finded = 1;
                            } else {
                                printf("Il touche un autre bateau : ");
                            }
                        } else
                            printf("Le bateau ne peut pas etre en diagonal : ");
                        else
                            printf("Entrer unr positions dans l'interval : ");
                } else {
                    printf("Entrer une positions : ");
                }
            }
            if (navy == 0)
                add_boat_to_map(navy1, posx1, posx2, posy1, posy2, x, y, name_of_boat, boat1, i);
            if (navy == 1)
                add_boat_to_map(navy2, posx1, posx2, posy1, posy2, x, y, name_of_boat, boat2, i);
            position_finded = 0;
            name_of_boat++;
        }
    }
}*/

