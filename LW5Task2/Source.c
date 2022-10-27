#include <stdio.h>        
#include <stdlib.h>
#include "arrays.h"
void main() {
	int** a;
	int n;
	printf("input the number of rows in the matrix ");
	while (scanf_s("%d", &n) != 1 || n < 1 || getchar() != '\n') {
		printf("error\n");
		rewind(stdin);
	}
	a = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		int s;
		printf("input amount of numbers in %d row(including -1)\n", i + 1);
		while (scanf_s("%d", &s) != 1 || s < 1 || getchar() != '\n') {
			printf("error\n");
			rewind(stdin);
		}
		*(a + i) = (int*)malloc(s * sizeof(int));
		for (int j = 0;j<s-1; j++) {
			printf("a[%d][%d]= ", i+1, j+1);
			while (scanf_s("%d", *(a+i)+j) != 1 || *(*(a + i) + j) == -1 || getchar() != '\n') {
				printf("error\n");
				rewind(stdin);
			}
		}
		*(*(a + i) + s-1) = -1;
	}
	show(a, n);
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		for (int j = last(a, i); j >= 0; j--) {
			if ((*(*(a + i) + j)) % 2 == 0 && (j+1) % 2 == 0) {
				move(a, i, j);
				*(a + i) = (int*)realloc(*(a+i), (last(a, i) + 2) * sizeof(int));
			}
		}
	}
	show(a, n);
	for (int i = 0; i < n; i++)
		free(*(a+i));
	free(a);
}
