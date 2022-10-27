#include <stdlib.h>
void move(int** a, int i, int j) {
	for (; *(*(a + i) + j) != -1; j++)
		*(*(a + i) + j) = *(*(a + i) + j+1);
}
int last(int** a, int i) {
	for (int k = 0;; k++)
		if (*(*(a + i) + k) == -1)
			return k-1;
}
void show(int** a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; *(*(a + i) + j - 1) != -1; j++) {
			printf("%4d", *(*(a + i) + j));
		}
		printf("\n");
	}
}