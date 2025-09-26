#ifndef INCLUDE_H
#define INCLUDE_H

typedef struct Positions {
    int x;
    int y;
} Positions;

typedef struct Boat {
    Positions **positions;
    int lenght;
    int hit;
    char *name;
    int sunk;
} Boat;

void get_position_of_cheap(char **navy1, char **navy2, int x, int y, Boat *boat1, Boat *boat2);

#endif
