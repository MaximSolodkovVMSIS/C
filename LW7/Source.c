#include <stdio.h> 
#include <stdlib.h> 
#include "Header.h"
//Удалить слова меньше k букв
//Даны строки S и S0. Удалить из строки S первую подстроку, совпадающую с S0. Если совпадающих подстрок нет, то вывести строку S без изменений
void main() {
	int choice;
	void (*fun) (char**, char**);
	printf("Choose task 1 or 2\n");
	while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2) || getchar() != '\n') {
		printf("try again\n");
		rewind(stdin);
	}
	char* line1, *line2;
	if (choice == 1) {
		printf("Delete words less than k letters\n");
		fun = firsttask;
	}
	else {
		printf("The strings S and S0 are given. Remove the first substring matching S0 from the string S.\nIf there are no matching substrings, then output the string S unchanged\n");
		fun = secondtask;
	}
	fun(&line1, &line2);
}
