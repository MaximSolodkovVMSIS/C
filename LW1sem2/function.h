#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int enum_print(int num);
char* enter_str();
int input_price();
int input_fuel_tank_volume();
int input_engine_volume();
void add_structure_machine_in_array(machine lap, machine** array, int* size);
void input_machine(machine** array, int* size);
void output_machine(machine* array, int size);
int menu_content();
int choice_for_menu();
void menu(machine** array, int* size);
int choice_for_sort();
int first_symbol(char* str);
void swap_symbol(machine** array, char* ind1, char* ind2, int pos);
void swap_number(machine** array, int ind1, int ind2, int pos);
void sort(machine** array, int* size);
void sort_by_two_fields_at_the_same_time(machine** array, int* size);
int pos_for_delete();
void delete(machine** array, int* size);