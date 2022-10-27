#include <stdio.h>        
#include <stdlib.h>
#include "arrays.h"
void main() {
	int** a;
	int N,M,flag=0;
	printf("input the number of rows in the matrix ");
	while (scanf_s("%d", &N) != 1 || N < 1 || getchar() != '\n') {
		printf("error\n");
		rewind(stdin);
	}
	printf("input the number of columns in the matrix ");
	while (scanf_s("%d", &M) != 1 || M < 1 || getchar() != '\n') {
		printf("error\n");
		rewind(stdin);
	}
	a = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		*(a + i) = (int*)malloc(M * sizeof(int));
		for (int j = 0; j < M; j++) {
			printf("a[%d][%d]= ", i, j);
			while (scanf_s("%d", *(a + i) + j) != 1 || getchar() != '\n') {
				printf("error\n");
				rewind(stdin);
			}
		}
	}
	show(a, N, M);
	printf("\n\n");
	for (int j = 0; j < M; j++) {
		if (check(a, N, j)) {
			delete (a, N, &M, j);
			for (int i = 0; i < N; i++)
				*(a + i) = (int*)realloc(*(a + i), M * sizeof(int*));
		}
	}
	show(a, N, M);
	free(a);
}
