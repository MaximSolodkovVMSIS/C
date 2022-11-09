#include <stdio.h>        
#include <stdlib.h>
#include "Header.h"
void main() {
    int** a;
    int i, n,m;
    printf("input amount of rows ");
    while (scanf_s("%d", &n) != 1 || n < 1 || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
    }
    a = (int**)malloc(n * sizeof(int*));
    printf("input amount of columns ");
    while (scanf_s("%d", &m) != 1 || m < 1 || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
    }
    for (int i = 0; i < n; i++)
        *(a + i) = (int*)malloc(m * sizeof(int));
    // ¬водим значени€ элементов массива
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i + 1,j+1);
            while (scanf_s("%d", *(a + i)+j) != 1 || getchar() != '\n') {
                printf("Error\n");
                rewind(stdin);
                printf("Repeat a[%d][%d] = ", i + 1,j+1);
            }
        }
    }
    printout(a, n,m);
    printf("\n");
    ShellSort(a, n,m);
    printout(a, n,m);
}