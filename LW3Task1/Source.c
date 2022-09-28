#include <stdio.h>        
int main()
{
    int n = 0, sum = 0, am = 0;
    int arr[100];
    printf("input size of array and its elements\n");
    scanf_s("%d", &n);
    if (n < 1) {
        printf("Error");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
        if (arr[i] > 0)
            am = am + 1;
    }
    for (int j = n; j > 0; j--) {
        if (arr[j - 1] == 0) {
            break;
        }
        sum += arr[j - 1];
    }
    printf("%d of positive elements\nsum is %d", am, sum);
    return 0;
}