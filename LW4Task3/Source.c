#include <stdio.h>        
#include <stdlib.h>
#include <time.h>
#define max 50
int main() {
    srand(time(NULL));
    int N, choice, matr[50][50], maxodd;
    printf("input number of rows and columns\n");
    while (scanf_s("%d", &N) != 1 || N < 1 || N>50) {
        printf("Error\n");
        rewind(stdin);
    }

    printf("choose the way of input:1 for random, 2 for manual\n");
    while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Error\n");
        rewind(stdin);
    }
    if (choice == 2)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("input %d row %d column element ", i + 1, j + 1);
                while (scanf_s("%d", &matr[i][j]) != 1) {
                    printf("Error\n");
                    rewind(stdin);
                }
            }
        }
    else
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matr[i][j] = rand() % (2 * max + 1);
                printf("%4d ", matr[i][j]);
            }
            printf("\n");
        }
    maxodd = matr[0][0];
    for (int j = 0; j < N-N/2; j++) {
        for (int i = j; i < N-j; i++) {
            if (matr[i][j] > maxodd && matr[i][j] % 2 == 1)
                maxodd = matr[i][j];
        }
        printf("\n");
    }
    if (maxodd % 2 == 0)
        printf("no odd numbers in left quarter(area 4)");
    else
        printf("max odd in left quarter(area 4) is %d", maxodd);
    return 0;
}