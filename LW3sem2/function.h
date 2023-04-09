#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "struct.h"
FILE* open_input_file(const char* fileName);
FILE* open_file(char* fileName, char* mode);
void get_input_file_name(char* input_file_name);
void get_output_file_name_BW(char* output_file_name);
void get_output_file_name_neg(char* output_file_name);
void get_output_file_name_gamma(char* output_file_name);
void get_output_filename_median(char* output_file_name);
void convert_file_in_bw(FILE* input_file, FILE* output_file, BMPFileHeader header);
void convert_file_in_neg(FILE* input_file, FILE* output_file, BMPFileHeader header);
void gamma_correction(char* input_file, char* output_file, BMPFileHeader header, double gamma);
int compare(const void* a, const void* b);
void median_filter(char* inputFileName, char* outputFileName, int filterSize);
void remove_file(char* filename);
void show_menu();
int get_menu_choice();
int menu();