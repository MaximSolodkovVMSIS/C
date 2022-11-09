void printout(int** arr, int n,int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            printf("%3d", *(*(arr+i)+j));
        }
        printf("\n");
    }
}
int findmax(int**arr,int n,int m){
    int max = *(*arr + m);
    for (int i = 0; i < n; i++) {
        if (max < *(*(arr + i) + m))
            max = *(*(arr + i) + m);
    }
    return max;
}
void swap(int** arr, int n, int m1, int m2) {
    for (int i = 0; i < n; i++) {
        int tmp = arr[i][m1];
        arr[i][m1] = arr[i][m2];
        arr[i][m2] = tmp;
    }
}
void ShellSort(int** arr, int n,int m)
{
    int i, j, step;
    int tmp;
    for (step = m-m/2; m > 0; step = step - step / 2) {
        for (i = step; i < m; i++)
        {
            tmp = findmax(arr, n,i);
            for (j = i; j >= step; j -= step)
            {
                if (tmp > findmax(arr, n, j - step)) {
                    swap(arr, n, j, j - step);
                    
                    printout(arr,n,m);//проврка действий 
                    printf("\n");
                }
                    
                else
                    break;
            }
        }
        if (step == 1)
            break;
    }
}