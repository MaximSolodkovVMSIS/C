#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
void main(int argc, char **argv) {
	if (argc == 1) {
		printf("no arg");
		return;
	}
	mergesort(argv, 1, argc-1);
	printf("Your lines sorted by amount of words of even number of letters:\n");
	type(argc, argv);
}