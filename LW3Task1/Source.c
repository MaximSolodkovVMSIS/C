#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 101
int main()
{
    srand(time(NULL));
    int input, n = 0, sum = 0, am = 0, flag =0;
    int arr[100];
    printf("input size of array\n");
    while (scanf_s("%d", &n) != 1 || n < 1 || n>100 || getchar()!='\n') {

        printf("Error\n");
        rewind(stdin);
    }
    printf("choose the way of input:1 for random, 2 for manual\n");
    while (scanf_s("%d", &input) != 1 || (input!=1 && input!=2)){
        printf("Error\n");
        rewind(stdin);
    }
    if(input==2)
        for (int i = 0; i < n; i++) {
            printf("input %d element ", i + 1);
            while (scanf_s("%d", &arr[i]) != 1)
            {
                printf("Error\n");
                rewind(stdin);
            }
            if (arr[i] > 0)// проверка на положительное
            am = am + 1;
        }
    else
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % max - 50;
            printf("%4d",arr[i]);
            if (arr[i] > 0) // проверка на положительное
                am = am + 1;
        }
    for (int j = n; j > 0; j--) {
        if (arr[j - 1] == 0) {
            flag++;
            break;
            
        }
        sum += arr[j - 1];
    }
   if (flag > 0)
    printf("\n%d of positive elements\nsum is %d", am, sum);
   else
       printf("\n%d of positive elements\nno zero sum = 0", am);
    return 0;
}