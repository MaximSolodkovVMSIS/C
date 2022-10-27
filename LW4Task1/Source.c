#include <stdio.h>        
#include <stdlib.h>
#include <time.h>
#define max 50
int main(){
    srand(time(NULL));
    int size,choice,prod,matr[50][50],flag=0,maxsum=0,sum;
    printf("input number of rows and columns\n");
    while (scanf_s("%d", &size) != 1 || size < 1 || size>50) {
        printf("Error\n");
        rewind(stdin);
    }
    printf("choose the way of input:1 for random, 2 for manual\n");
    while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Error\n");
        rewind(stdin);
    }
    if (choice == 2) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("input %d row %d column element ", i + 1, j + 1);
                while (scanf_s("%d", &matr[i][j]) != 1) {
                    printf("Error\n");
                    rewind(stdin);
                }
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%4d ", matr[i][j]);
            }
            printf("\n");
        }
    }
    else
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matr[i][j] = rand() % (2*max + 1)-max;
                printf("%4d ", matr[i][j]);
            }
            printf("\n");
        }
    for (int i = 0; i < size; i++) {
        prod = 1;
        for (int j = 0; j < size; j++) {
            prod *= matr[i][j];
            if (matr[i][j] < 0)
                flag = 1;
        }
        if (flag == 0)
            printf("product of %d row is %d\n",i+1,prod);
    }
    maxsum = matr[size - 1][0];
    for (int k = size - 1; k > 0; k--) {
        sum = 0;
        for (int i = 0; i < size - k; i++) {
            int j = i + k;
            sum += matr[i][j];
        }
        if (sum > maxsum)
            maxsum = sum;
    }
    for (int k = size - 2; k >= 0; k--) {
        sum = 0;
        for (int i = size - 1; i >size-k-1 ; i--) {
            int j = k;
            sum += matr[i][j];
        }
        if (sum > maxsum)
            maxsum = sum;
    }
    printf("max diagonal sum is %d", maxsum);
    return 0;
}