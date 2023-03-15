#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"

int error_check(errno_t err);
void output(Words** array, const int* size);
void dictionary_output(Dictionary** array, const int* size);
void input_word_in_array(Words lap, Words** array, int* size);
void input_dictionary_in_array(Dictionary word, Dictionary** array, int* size);
char* word_after_n(char* str, int index);
char* word_after_slash(char* str);
char* find_word_in_dictionary(char* str, char* ptr_word);
int count_word(char* str, char* ptr, int* index);
int is_letter(char symbol);
int find_word(char* string, int* index);
char* take_word(char* str, int start);
void check_words(Words** array, int* size, char* word, int counter);
void change_words(Words** array, Dictionary** arr, int* size_of_words, int* size_of_dictionary);
void words_for_dictionary(Words** array, Dictionary** arr, int* size_of_words, int* size_of_dictionary);
void input_dictionary(Dictionary** arr, int* size_of_dictionary);
char* word_from_dictionary(char* word);
void input_word_from_dictionary(char** str, char* word, char* new_word, int* index);
void create_file(char* str);
void zipper();
void print_file_size(const char* filename);