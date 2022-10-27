void delete(int** a,int N,int* M,int k) {
	for (int i = 0; i < N; i++) {
		for (int j = k; j + 1 < *M; j++) {
			*(*(a + i) + j) = *(*(a + i) + j + 1);
		}
	}
	(*M)--;
}
int check(int** a, int N, int k) {
	for (int i = 0; i < N; i++)
		if (*(*(a + i) + k) > -1)
			return 0;
	return 1;
}
void show(int** a, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%4d", *(*(a + i) + j));
		}
		printf("\n");
	}
}