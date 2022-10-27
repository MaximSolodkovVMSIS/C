#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100
int main()
{
    srand(time(NULL));
    int input,n, cnt = 0, maxc = 0, arr[100]; //cnt - счетчик количества элементов с данным значением
    float maxel = 0.5;//maxel - самый часто встречаемый элемент
    //maxc - сколько раз встретилс€ самый частый
    //n-размер массива
    printf("input size\n");
    while (scanf_s("%d", &n) != 1 || n < 1 || n>100)
    {
        printf("Error\n");
        rewind(stdin);
    }
    printf("choose the way of input:1 for random, 2 for manual\n");
    while (scanf_s("%d", &input) != 1 || (input != 1 && input != 2)) {
        printf("Error\n");
        rewind(stdin);
    }
    if (input == 2)
        for (int i = 0; i < n; i++) {
            printf("input %d element ", i + 1);
            while (scanf_s("%d", &arr[i]) != 1)
            {
                printf("Error\n");
                rewind(stdin);
            }
        }
    else
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (max + 1) - max / 2;
            printf("%d ", arr[i]);
        }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            for (int k = i; k < n; k++) {
                if (arr[i] == arr[k])
                    cnt += 1;
            }
            if (cnt > maxc) {
                maxc = cnt;
                maxel = arr[i];
            }
            cnt = 0;
        }
    }
    printf("\n");
    if(maxel==0.5)
        printf("no even numbers found");
    else
        printf("%.0f is the most frequently met even number", maxel);
    return 0;
}
