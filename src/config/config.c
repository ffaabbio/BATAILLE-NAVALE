#include <stdlib.h>
#include <stdio.h>

void create(int x, int y)
{
    char **navy = malloc(sizeof(char *) * (x + 1));

    for (int i = 0; i < x; i++) {
        navy[i] = malloc(sizeof(char) * (y + 1));
        navy[i][y + 1] = '\0';
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            navy[i][j] = '.';
        }
    }

    for (int i = 0; i < x; i++) {
        printf("%s\n", navy[i]);
    }
}