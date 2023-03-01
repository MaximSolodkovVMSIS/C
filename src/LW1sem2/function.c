#include "Struct.h"
#include "function.h"
int enum_print(int num) {
    if (num == 4) return SMALL;
    if (num == 8) return AVERAGE;
    if (num == 12) return BIG;
    if (num == 16) return GRATE;
    return -1;

}
char* enter_str() {
    int size = 0;
    char* string = (char*)calloc(256, sizeof(char));
    gets_s(string, 255);
    size = strlen(string);
    string = (char*)realloc(string, size + 1);
    return string;
}

int input_price() {
    int price = 0;
    while (scanf_s("%d", &price) != 1 || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
        printf("Input price again: ");
    }
    return price;
}

int input_fuel_tank_volume() {
    int fuel_tank_volume = 0; 
    while (scanf_s("%d", &fuel_tank_volume) != 1 || fuel_tank_volume < 30 || (fuel_tank_volume < 30 && fuel_tank_volume > 90) || fuel_tank_volume > 90 || getchar() != '\n'){
        printf("Error\n");
        rewind(stdin);
        printf("Input fuel tank volume again(from 30 liters to 90 liters): ");
    }
    return fuel_tank_volume;
}

int input_engine_volume() {
    int engine_volume = 0;
    while (scanf_s("%d", &engine_volume) != 1 || engine_volume < 4 || (engine_volume > 4 && engine_volume < 8) || (engine_volume > 8 && engine_volume < 12) || engine_volume > 16 || getchar() != '\n'){
        printf("Error\n");
        rewind(stdin);
        printf("Input engine volume again: ");
    }
    return engine_volume;
}

void add_structure_machine_in_array(machine m, machine** array, int* size) {
    (*size)++;
    if ((*array) == NULL) {
        (*array) = (machine*)malloc((*size) * sizeof(m));
    }
    else {
        (*array) = (machine*)realloc((*array), (*size) * sizeof(m));
    }
    (*array)[(*size) - 1] = m;
}

void output_machine(machine** array, const int *size) {
    for (int i = 0; i < (*size); i++) {
        printf("Machine name: %s\n", (*array)[i].name);
        printf("Machine fuel tank volume: %d\n", (*array)[i].fuel_tank_volume);
        printf("Machine engine volume: %d\n", (*array)[i].engine_volume);
        printf("Machine price: %d\n", (*array)[i].price);
    }
}

int choice_for_sort() {
    int choice = 0; 
    while (scanf_s("%d", &choice) == 0 || choice < 1 || choice > 4 || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
        printf("Input your choice again");
    }
    return choice;
}

int first_symbol(const char *str) {
    int x = str[0];
    return x;
}
void swap_symbol(machine **array, char *ind1, char * ind2, int pos) {
    if (first_symbol(ind1) > first_symbol(ind2)) {
        machine str = (*array)[pos];
        (*array)[pos] = (*array)[pos + 1];
        (*array)[pos + 1] = str;
    }
}
void swap_number(machine** array, int ind1, int ind2, int pos) {
        if (ind1 > ind2) {
        machine str = (*array)[pos];
        (*array)[pos] = (*array)[pos + 1];
        (*array)[pos + 1] = str;
    }
}
void sort(machine** array,const int* size) {
    int choice = 0;
    printf("Enter you choice\n 1 for sort name of car \n 2 for sort price \n 3 for sort fuel tank valume \n 4 for sort engine volume\n");
    printf("Your choice: ");
    choice = choice_for_sort();
    switch (choice) {
    case 1:
        for (int i = 0; i < (*size) - 1; i++) {
            for (int j = 0; j < (*size) - 1; j++) {
                swap_symbol(array, (*array)[j].name, (*array)[j + 1].name, j);
            }
        }
        break;
    case 2:
        for (int i = 0; i < (*size) - 1; i++) {
            for (int j = 0; j < (*size) - 1; j++) {
                swap_number(array, (*array)[j].price, (*array)[j + 1].price, j);
            }
        }
        break;
    case 3:
        for (int i = 0; i < (*size) - 1; i++) {
            for (int j = 0; j < (*size) - 1; j++) {
                swap_number(array, (*array)[j].fuel_tank_volume, (*array)[j + 1].fuel_tank_volume, j);
            }
        }
        break;
    case 4:
        for (int i = 0; i < (*size) - 1; i++) {
            for (int j = 0; j < (*size) - 1; j++) {
                swap_number(array, (*array)[j].engine_volume, (*array)[j + 1].engine_volume, j);
            }
        }
        break;
    default: 
        exit(0);
    }
    output_machine(array, *size);
}
void sort_by_two_fields_at_the_same_time(machine** array, const int* size) {
    for (int i = 0; i < (*size) - 1; i++) {
        for (int j = 0; j < (*size) - 1; j++) {
            if ((*array)[j].engine_volume > (*array)[j + 1].engine_volume || (*array)[j].engine_volume == (*array)[j + 1].engine_volume && (*array)[j].price > (*array)[j + 1].price) {
                machine str = (*array)[j];
                (*array)[j] = (*array)[j + 1];
                (*array)[j + 1] = str;
            }
        }
    }
    output_machine(array, *size);
}
int pos_for_delete() {
    int pos;
    while (scanf_s("%d", &pos) == 0 || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
        printf("Try again: ");
    }
    return pos;
}
void delete(machine** array, int* size) {
    int pos = 0;
    printf("Input machine for delete: ");
    pos = pos_for_delete();
    free((*array)[pos - 1].name);
    for (int i = 0; i < (*size) - 1; i++) {
        (*array)[i] = (*array)[i + 1];
    }
    (*size)--;
    (*array) = (machine*)realloc((*array), (*size) * sizeof(machine));
    output_machine(array, *size);
}

void input_machine(machine** array, int* size) {
    machine tmp;
    printf("Enter a name of car: ");
    tmp.name = enter_str();
    printf("\nEnter a price of %s: ", tmp.name);
    tmp.price = input_price();
    printf("\nEnter a fuel tank volume(from 30 liters to 90 liters) of %s: ", tmp.name);
    tmp.fuel_tank_volume = input_fuel_tank_volume();
    printf("\nEnter a engine volume(4/8/12/16 liters) of %s: ", tmp.name);
    tmp.engine_volume = enum_print(input_engine_volume());
    add_structure_machine_in_array(tmp, array, size);
}

int menu_content() {
    printf("THIS MENU FOR YOU\n");
    printf("1 - output array\n");
    printf("2 - add car in array\n");
    printf("3 - sort for your array\n");
    printf("4 - for delete structure\n");
    printf("5 - for sort by two field\n");
    printf("Input your choice: ");
}

int choice_for_menu() {
    int choice = 0;
    while (scanf_s("%d", &choice) != 1 || choice <= 0 || choice > 5 || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
        printf("Input your choice again: ");
    }
    return choice;
}

void menu(machine** array, int* size) {
    int choice = 0;
    menu_content();
    choice = choice_for_menu();
    switch (choice) {
    case 1:
        output_machine(array, *size);
        menu(array, size);
        break;
    case 2:
        input_machine(array, size);
        menu(array, size);
        break;
    case 3:
        sort(array, size);
        menu(array, size);
        break;
    case 4:
        delete(array, size);
        menu(array, size);
        break;
    case 5: 
        sort_by_two_fields_at_the_same_time(array, size);
        menu(array, size);
        break;
    default:
        exit(0);
    }
}
