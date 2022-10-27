#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100
int main()
{
    srand(time(NULL));
    int n, k,input, arr[50];//n-размер массива, к- номера элементов
    printf("input size\n");
    while (scanf_s("%d", &n) != 1 || n < 1 || n>100) {
        printf("Error\n");
        rewind(stdin);
    }
    printf("input k (interval)\n");
    while (scanf_s("%d", &k) != 1 || k>n) {
        printf("Error\n");
        rewind(stdin);
    }
    printf("choose way of input:1 for random, 2 for keyboard\n");
    while (scanf_s("%d", &input) != 1 || (input!=1 && input!= 2)) {
        printf("Error\n");
        rewind(stdin);
    }
    if(input==2)
        for (int i = 0; i < n; i++) {
            while (scanf_s("%d", &arr[i]) != 1) {
                printf("Error\n");
                rewind(stdin);
            }
        }
    else
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (max+1) - max/2;
            printf("%d ", arr[i]);
        }
    for (int i = 0; i < n;i++)
        if ((i+1) % k == 0) {
            n++;
            for (int p = n - 1; p > i; p--)
                arr[p] = arr[p - 1];
            arr[i] = 0;
            i++;
        }
    printf("\nresult:\n");
    for (int a = 0; a < n; a++) {
        printf("%d ", arr[a]);
    }
    return 0;
}