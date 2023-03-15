#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"
int error_check(errno_t err);
void words_output(words** array, const int* size);
void input_words_in_array(words word, words** array, int* size);
int is_letter(char symbol);
int find_word(char* string, int* index);
char* take_word(char* str, int start);
char* word_from_dictionary(words** array, char* word, int* size);
void input_dictionary(words** array, char* str, int* size);
void input_word_from_dictionary(char** str, char* word, char* new_word, int* index);
void input_file(char* str);
void unzipper(words** array, int* size);