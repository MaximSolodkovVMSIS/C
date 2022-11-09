int foundOdd(int* arr, int s) {
    int a = -1;
    for (int i = 0;; i++) {
        if (arr[i] % 2 == -1 && arr[i] < 0)
            a++;
        if (arr[i] % 2 == -1 && arr[i] < 0 && a == s)
            return i;
    }
}
void bubbleSort(int* arr, int size)
{
    int odds=0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == -1 && *(arr + i) < 0)
            odds++;
    }
    for (int i = 0; i < odds; i++) {
        for (int j = (odds - 1); j > i; j--) { // для всех элементов после i-ого
            if (arr[foundOdd(arr,j - 1)] > arr[foundOdd(arr, j)]) { // если текущий элемент меньше предыдущего
                int temp = arr[foundOdd(arr, j - 1)]; // меняем их местами
                arr[foundOdd(arr, j - 1)] = arr[foundOdd(arr, j)];
                arr[foundOdd(arr, j)] = temp;
            }
        }
    }
}
void ShellSort(int* arr,int size)
{
    int odds = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == -1 && *(arr + i) < 0)
            odds++;
    }
    int i, j, step;
    int tmp;
    for (step = odds - odds / 2; step > 0; step = step - step / 2) {
        for (i = step; i < odds; i++)
        {
            tmp = arr[foundOdd(arr, i)];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < arr[foundOdd(arr,j - step)])
                    arr[foundOdd(arr, j)] = arr[foundOdd(arr, j - step)];
                else
                    break;
            }
            arr[foundOdd(arr, j)] = tmp;
        }
        if (step == 1)
            break;
    }
}
void printout(int* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
}