#ifndef INCLUDE_H
    #define INCLUDE_H

typedef struct Position {
    int x;
    int y;
} Position;

typedef enum BoatOrientation {
    BOAT_HORIZONTAL,
    BOAT_VERTICAL
} BoatOrientation;

typedef struct Boat {
    Position position;
    int length;
    int orientation;
    int hit;
    int sunk;
} Boat;

void create(int x, int y);

#endif
