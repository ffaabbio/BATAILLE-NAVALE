#include <stdio.h>
#include <stdlib.h>
#include "board.h"

char** createMap() {

    int rows;
    int cols;

    while (1) {
        printf("Enter the number of rows (1-20): ");
        if (scanf("%d", &rows) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter the number of cols (1-20): ");
        if (scanf("%d", &cols) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (rows >= 1 && rows <= 20 && cols >= 1 && cols <= 20) {
            break;
        }

        printf("Please enter numbers between 1 and 20.\n");
    }
    char **map= malloc(rows*sizeof(char*));
    for(int i=0;i<rows;i++) {
        map[i]= calloc(cols,sizeof(char));
    }

    char letter = 'A';
    int count = 1;

    printf("%4c ",letter);
    letter++;
    for (int i=1;i<cols;i++) {
        printf("%2c ",letter);
        letter++;
    }


    for (int j=0;j<cols;j++) {

      printf("\n");
        if (count < 10 ) {
            printf("%d  ",count);
        } else { printf("%d ",count);}

        count++;
        letter++;
        for (int k=0;k<rows;k++) {

            printf("%d  ",map[k][j]);



        }

    }


    return map;
}













int main(void) {

    createMap();

 return 0;
}