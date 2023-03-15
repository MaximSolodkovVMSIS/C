#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

int main() {
	words* arr = NULL;
	int size = 0;
	unzipper(&arr, &size);
	free(arr);
	return 0;
}