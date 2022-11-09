#include <stdio.h>        
#include <stdlib.h>
#include <time.h>
#include "Header.h"
#define elMax 1000
void main() {
    srand(time(NULL));
    int* a;
    int i, n,start,end;
    printf("input the size of array ");
    while (scanf_s("%d", &n) != 1 || n < 1 || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
    }
    a = (int*)malloc(n * sizeof(int));
    // Вводим значения элементов массива
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i + 1);
        while (scanf_s("%d", a + i) != 1 || getchar() != '\n') {
            printf("Error\n");
            rewind(stdin);
            printf("Repeat a[%d] = ", i + 1);
        }
    }
    //for (int i = 0; i < n; i++) {
    //    *(a + i) = (rand() % (2 * elMax + 1) - elMax);  //   <--РАНДОМ
    //}
    printout(a, n);
    start = clock();
    bubbleSort(a, n);
    //ShellSort(a,n);
    end = clock();
    printf("Time of sort(ms): %d\n", end - start);
    printout(a, n);
}