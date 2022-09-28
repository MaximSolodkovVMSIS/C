#include <stdio.h>        
int main()
{
    int n, cnt = 0, maxc = 0, maxel, arr[100]; //cnt - счетчик количества элементов с данным значением
    //maxel - самый часто встречаемый элемент
    //maxc - сколько раз встретилс€ самый частый
    printf("input size and elements\n");
    scanf_s("%d", &n);//n-размер массива
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
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
    printf("%d is the most frequently met even number", maxel);
    return 0;
}