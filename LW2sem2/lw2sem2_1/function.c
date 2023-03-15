#include"function.h"

#define FILE_ERROR -3

int error_check(errno_t err) {
	if (err != 0) {
		printf("\nFile open error\n");
		exit(FILE_ERROR);
	}
	return 1;
}

void sort_by_size(Words** array, const int* size) {
	Words buf;
	for (int i = 0; i < (*size) - 1; i++) {
		for (int j = 0; j < (*size) - 1; j++) {
			if ((*array)[j].length > (*array)[j + 1].length) {
				buf = (*array)[j];
				(*array)[j] = (*array)[j + 1];
				(*array)[j + 1] = buf;
			}
		}
	}
}

void output(Words** array, const int* size) {
	for (int i = 0; i < (*size); i++) {

		printf("Word: %s\n", (*array)[i].word);
		printf("Size: %d\n", (*array)[i].length);
		printf("\n");
	}
}

void dictionary_output(Dictionary** array, const int* size) {
	for (int i = 0; i < (*size); i++) {

		printf("Word1: %s\n", (*array)[i].word1);
		printf("Word2: %s\n", (*array)[i].word2);
		printf("\n");
	}
}

void input_word_in_array(Words lap, Words** array, int* size) {
	(*size)++;
	if ((*array) == NULL) {
		(*array) = (Words*)malloc((*size) * sizeof(lap));
	}
	else {
		(*array) = (Words*)realloc((*array), (*size) * sizeof(lap));
	}
	(*array)[(*size) - 1] = lap;
}

void input_dictionary_in_array(Dictionary word, Dictionary** array, int* size) {
	(*size)++;
	if ((*array) == NULL) {
		(*array) = (Dictionary*)malloc((*size) * sizeof(word));
	}
	else {
		(*array) = (Dictionary*)realloc((*array), (*size) * sizeof(word));
	}
	(*array)[(*size) - 1] = word;
}

char* word_after_n(char* str, int index) {
	char* word = (char*)calloc(256, 1);
	int count = 0;
	while (str[index] != '\n') {
		word[count] = str[index];
		index++;
		count++;
	}
	word = (char*)realloc(word, (strlen(word) + 1));
	return word;
}

char* word_after_slash(char* str) {
	char* word = (char*)calloc(256, 1);
	int count = 0;
	while (str[count] != '/') {
		word[count] = str[count];
		count++;
	}
	word = (char*)realloc(word, (strlen(word) + 1));
	return word;
}

char* find_word_in_dictionary(char* str, char* ptr_word) {
	int i, j, k;
	char* word = NULL;
	for (i = 0; str[i] != '\0'; i++) {
		for (j = i, k = 0; ptr_word[k] != '\0' && str[j] == ptr_word[k]; j++, k++)
			;
		if (ptr_word[k] == '\0' && ((i == 0 && str[j] == '/') || (str[i - 1] == '/' && str[j] == '\n'))) {
			if (str[i] == str[0] && str[j] == '/') {
				word = word_after_n(str, (j + 1));
				break;
			}
			else {
				word = word_after_slash(str);
				break;
			}
		}
	}
	return word;
}

int count_word(char* str, char* ptr, int* index) {
	int i = (*index) + strlen(ptr), j, k, counter = 0;
	for (int t = 0; t < (*index); t++) {
		for (j = t, k = 0; ptr[k] != '\0' && str[j] == ptr[k]; j++, k++)
			;
		if (ptr[k] == '\0' && (str[t - 1] == ' ' || str[t - 1] == '\"' || str[t - 1] == '\'' || str[t] == str[0]) && str[j + 1] == ' ') {
			return -1;
		}
	}
	for (; str[i] != '\0'; i++) {
		for (j = i, k = 0; ptr[k] != '\0' && str[j] == ptr[k]; j++, k++)
			;
		if (ptr[k] == '\0' && (str[i - 1] == ' ' || str[i - 1] == '\"' || str[i - 1] == '\'' || str[i] == str[0]) && str[j + 1] == ' ') {
			counter++;
		}
	}
	if (counter != 0) {
		return counter;
	}
	return 0;
}

int is_letter(char symbol) {
	if (symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z') return 1;
	return 0;
}

int find_word(char* string, int* index) {
	while (string[(*index)] != '\0') {
		if ((*index) == 0 && is_letter(string[(*index)]) != 0 || string[(*index) - 1] != '-' && is_letter(string[(*index) - 1]) == 0 && is_letter(string[(*index)]) != 0) {
			return (*index);
		}
		(*index)++;
	}
	return -1;
}

char* take_word(char* str, int start) {
	int index = 0;
	char* buf = (char*)calloc(256, 1);
	while (str[start] != ' ' && str[start] != '\0' && str[start] != '\n' && str[start] != ',' && str[start] != ':' && str[start] != ';' && str[start] != '.' && str[start] != '\"' && str[start] != '!' && str[start] != '?' && str[start] != ')') {
		buf[index] = str[start];
		start++;
		index++;
	}
	buf = (char*)realloc(buf, strlen(buf) + 1);
	return buf;
}

void check_words(Words** array, int* size, char* word, int counter) {
	Words buf;
	int size_of_word = 0;
	if (strlen(word) >= 2) {
		if (counter == 0) {
			size_of_word = strlen(word);
		}
		else if (counter == -1) {
			size_of_word = 0;
		}
		else {
			size_of_word = counter * strlen(word);
		}
		for (int i = 0; i < (*size); i++) {
			if (!strcmp(word, (*array)[i].word)) {
				(*array)[i].length += size_of_word;
				return;
			}
		}
		if (counter == -1) {
			buf.word = word;
			buf.length = strlen(word);
			input_word_in_array(buf, array, size);
		}
		else {
			buf.word = word;
			buf.length = size_of_word;
			input_word_in_array(buf, array, size);
		}
	}
	else {
		return;
	}
}

void change_words(Words** array, Dictionary** arr, int* size_of_words, int* size_of_dictionary) {
	Dictionary word;
	int start = ((*size_of_words) - 1);
	int end = 0;
	while (strlen((*array)[end].word) <= 4) {
		if (strlen((*array)[start].word) > strlen((*array)[end].word)) {
			if ((*array)[start].length > (*array)[end].length) {
				word.word1 = (*array)[start].word;
				word.word2 = (*array)[end].word;
				input_dictionary_in_array(word, arr, size_of_dictionary);
				start--;
				end++;
			}
		}
		if (strlen((*array)[start].word) <= strlen((*array)[end].word)) {
			start--;
		}
	}
	dictionary_output(arr, size_of_dictionary);
}

void words_for_dictionary(Words** array, Dictionary** arr, int* size_of_words, int* size_of_dictionary) {
	FILE* file = NULL;
	char* word = NULL;
	char* buf = (char*)calloc(4096, 1);
	int index = 0, start = 0, counter = 0;


	int error = 0;

	if ((error = fopen_s(&file, "C:\\programming\\C\\zipper\\source.txt", "r") != NULL)) {
		return 1;
	}


	fgets(buf, 4096, file);
	while (!feof(file)) {
		while ((start = find_word(buf, &index)) != -1) {
			word = take_word(buf, start);
			counter = count_word(buf, word, &index);
			check_words(array, size_of_words, word, counter);
			index++;
		}
		index = 0;
		fgets(buf, 4096, file);
	}

	fclose(file);

	free(buf);
	free(word);
	sort_by_size(array, size_of_words);
	output(array, size_of_words);
	change_words(array, arr, size_of_words, size_of_dictionary);
}

void input_dictionary(Dictionary** arr, int* size_of_dictionary) {
	FILE* file = NULL;

	fopen_s(&file, "C:\\programming\\C\\zipper\\arhfile.txt", "w");

	for (int i = 0; i < (*size_of_dictionary); i++) {
		fprintf(file, "%s", (*arr)[i].word1);
		fprintf(file, "%c", '/');
		fprintf(file, "%s\n", (*arr)[i].word2);
	}
	fprintf(file, "%c\n", '$');

	fclose(file);
}

char* word_from_dictionary(char* word) {
	FILE* file = NULL;
	char* buf = (char*)calloc(1024, 1);
	char* new_word = NULL;
	int count = 0;

	fopen_s(&file, "C:\\programming\\C\\zipper\\arhfile.txt", "r");

	fgets(buf, 1024, file);
	while (buf[0] != '$') {
		if ((new_word = find_word_in_dictionary(buf, word)) != NULL) {
			break;
		}
		fgets(buf, 1024, file);
	}

	fclose(file);

	free(buf);
	return new_word;
}

void input_word_from_dictionary(char** str, char* word, char* new_word, int* index) {
	if (new_word == NULL) {
		return;
	}
	int diff = strlen(word) - strlen(new_word), count = 0, start = (*index), second_start = 0;
	if (diff > 0) {
		while (count != strlen(new_word)) {
			(*str)[start] = new_word[count];
			start++;
			count++;
		}
		second_start = start;
		for (int i = 0; i < diff; i++) {
			while ((*str)[start] != '\0') {
				(*str)[start] = (*str)[start + 1];
				start++;
			}
			start = second_start;
		}
		(*index) += strlen(new_word) - 1;
	}
	else {
		diff = strlen(new_word) - strlen(word);
		start = (strlen((*str)) + 1);
		for (int i = 0; i < diff; i++) {
			while (start != (*index)) {
				(*str)[start] = (*str)[start - 1];
				start--;
			}
			start = strlen((*str)) + 1;
		}
		start = (*index);
		while (count != strlen(new_word)) {
			(*str)[start] = new_word[count];
			start++;
			count++;
		}
		(*index) += strlen(new_word) - 1;
	}
}

void create_file(char* str) {
	FILE* file = NULL;

	fopen_s(&file, "C:\\programming\\C\\zipper\\arhfile.txt", "a");

	fputs(str, file);

	fclose(file);
}

void zipper() {
	FILE* file = NULL;
	char* word = NULL;
	char* new_word = NULL;
	char* buf = (char*)calloc(4096, 1);
	int index = 0, start = 0;

	fopen_s(&file, "C:\\programming\\C\\zipper\\source.txt", "r");

	fgets(buf, 4096, file);
	while (!feof(file)) {
		while ((start = find_word(buf, &index)) != -1) {
			word = take_word(buf, start);
			new_word = word_from_dictionary(word);
			input_word_from_dictionary(&buf, word, new_word, &index);
			index++;
		}
		create_file(buf);
		index = 0;
		fgets(buf, 4096, file);
	}

	fclose(file);

	free(buf);
	free(word);
	free(new_word);
}
void print_file_size(const char* filename) {
	FILE* file;
	if (fopen_s(&file, filename, "rb") != 0) {
		printf("Error opening file %s\n", filename);
		exit(1);
	}
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fclose(file);
	printf("Sixe of file is %ld bytes\n", size);
}