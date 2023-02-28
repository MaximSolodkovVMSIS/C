#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Struct.h"
#include "function.h"
int main() {
    int size = 0;
    machine* array = NULL;
    menu(&array, &size);
    free(array);
    return  0;
}
