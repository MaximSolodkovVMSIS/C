#include <stdio.h>        
#include <stdlib.h>
#include "arrays.h"
int main() {
	int* a;
	int min, n;
	printf("input the size of array ");
	while (scanf_s("%d", &n) != 1 || n < 1 || getchar() != '\n') {
		printf("Error\n");
		rewind(stdin);
	}
	a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		while (scanf_s("%d", a+i) != 1 || getchar() != '\n') {
			printf("Error\n");
			rewind(stdin);
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", *(a + i));
	printf("\n");
	min = minim(a, n);
	for (int i = 0; i < n; i++) {
		if (*(a + i) == min) {
			move(a, &n, i);
			a = (int*)realloc(a, n * sizeof(int));
			i--;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
	free(a);
}
