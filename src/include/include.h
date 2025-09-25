#ifndef INCLUDE_H
    #define INCLUDE_H

typedef struct Positions {
    int x;
    int y;
} Positions;

typedef enum BoatOrientation {
    BOAT_HORIZONTAL,
    BOAT_VERTICAL
} BoatOrientation;

typedef struct Boat {
    Positions *position;
    int lenght;
    int hit;
    char *name;
    int sunk;
} Boat;

void create(int x, int y);

#endif
