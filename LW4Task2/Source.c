#include <stdio.h>        
#include <stdlib.h>
#include <time.h>
#define max 50
int main() {
    srand(time(NULL));
    int row,column, choice, matr[50][50], flag;
    printf("input number of rows\n");
    while (scanf_s("%d", &row) != 1 || row < 1 || row>50) {
        printf("Error\n");
        rewind(stdin);
    }
    printf("input number of columns\n");
    while (scanf_s("%d", &column) != 1 || column < 1 || column>50) {
        printf("Error\n");
        rewind(stdin);
    }
    printf("choose the way of input:1 for random, 2 for manual\n");
    while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Error\n");
        rewind(stdin);
    }
    if (choice == 2)
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                printf("input %d row %d column element ", i + 1, j + 1);
                while (scanf_s("%d", &matr[i][j]) != 1) {
                    printf("Error\n");
                    rewind(stdin);
                }
            }
        }
    else
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                matr[i][j] = rand() % (2 * max + 1) - max;
                printf("%4d ", matr[i][j]);
            }
            printf("\n");
        }
    for (int i = 0; i < row; i++) {
        flag = 0;
        for (int j = 0; j < column; j++) {
            if (matr[i][j] != 0)
                flag = 1;
        }
        if (flag == 0) {
            for (int j = 0; j < row; j++) {
                matr[j][i] = matr[j][i]/2;
            }
            break;
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%4d ", matr[i][j]);
        }
        printf("\n");
    }
    return 0;
}