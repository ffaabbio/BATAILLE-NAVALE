#ifndef INCLUDE_H
#define INCLUDE_H

typedef struct {
    int x;
    int y;
} Position;
typedef struct Boat {
    Position **positions;
    int length;
    int hit;
    char *name;
    int sunk;
} Boat;

Position *** placeBoats();

#endif
