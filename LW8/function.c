#include <stdio.h>
#include <stdlib.h>
int is_letter(char line) {
    if ((line >= 'a' && line <= 'z') || (line >= 'A' && line <= 'Z'))
        return 1;
    return 0;
}
int len(char* line) {
    int i = 0;
    for (; line[i] != '\0'; i++);
    return i;
}
int get_words_of_even(char* line) {
    int words = 0, start = 0;
    for (int i = len(line); i != 0; i--) {
        if (is_letter(line[i - 1]) && !is_letter(line[i])) {
            start = i;
            continue;
        }
        if (!is_letter(line[i - 1]) && is_letter(line[i])) {
            words += ((start - i) % 2 == 0);
            start = 0;
        }
    }
    if (is_letter(line[0]) && start != 0)
        words += (start % 2 == 0);
    return words;
}
void swap(char** line1, char** line2) {
    char* temp = *line1;
    *line1 = *line2;
    *line2 = temp;
}
void move(char** argv, int start, int end) {
    for (int i = end; i > start; i--) {
        swap(argv + i, argv + i - 1);
    }
}
void merge(int start, int mid, int end, char **argv){
    int i = start, j = mid + 1;
    for (;i <= mid && j <= end;) {
        if (get_words_of_even(argv[i]) <= get_words_of_even(argv[j])) {
            i++;
        }
        else {
            move(argv, i, j);
            i++;
            mid++;
            j++;
        }
    }
}
void mergesort(char** argv,int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        mergesort(argv, start, mid);
        mergesort(argv, mid + 1, end);
        merge(start,mid,end, argv);
    }
}
void type(int argc, char** argv) {
    for (int i = 1; i < argc; i++)
        printf("%s %d words\n", argv[i], get_words_of_even(argv[i]));
}
