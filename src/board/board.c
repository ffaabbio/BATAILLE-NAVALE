#include <stdio.h>
#include <stdlib.h>
#include "board.h"

char** createMap(int rows,int cols) {
    char **map= malloc(rows*sizeof(char*));
    for(int i=0;i<rows;i++) {
        map[i]= malloc(cols * sizeof(char));
    }

    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
          map[i][j]='.';
        }
    }

    return map;
}

void display_map(char** map,int rows,int cols) {
  char letter = 'A';
    int count = 1;

    printf("%4c ",letter);
    letter++;
    for (int i=1;i<rows;i++) {
        printf("%2c ",letter);
        letter++;
    }

    for (int j=0;j<cols;j++) {

        printf("\n");
        if (count < 10 ) {
            printf("%d  ",count);
        } else {
            printf("%d ",count);
        }

        count++;
        letter++;
        for (int k=0;k<rows;k++) {
            printf("%c  ",map[k][j]);
        }
    }
    printf("\n");
}
