#include <stdio.h>        
int main()
{
    int n, k, arr[100];
    scanf_s("%d%d", &n, &k);//n-размер массива, к- номера элементов
    printf("input size, k and elements\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    for (int j = 1; j < n; j++) {
        if (j % k == 0) {
            arr[j] += arr[0];
        }
    }
    for (int a = 0; a < n; a++) {
        printf("%d", arr[a]);
    }
    return 0;
}