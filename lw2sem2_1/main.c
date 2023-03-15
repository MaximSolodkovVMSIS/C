#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

int main() {
	Words* array = NULL;
    Dictionary* arr = NULL;
	int size_of_words = 0;
	int size_of_dictionary = 0;
	words_for_dictionary(&array, &arr, &size_of_words, &size_of_dictionary);
	input_dictionary(&arr, &size_of_dictionary);
	zipper();
	print_file_size("C:\\programming\\C\\zipper\\arhfile.txt");
	free(array);
	free(arr);
	return 0;
}