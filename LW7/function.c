#include <stdio.h> 
#include <stdlib.h> 
int comp(int len, char* s0, char* s) {
    for (int i = 0; i < len; i++) {
        if (s0[i] != s[i])
            return 0;
    }
    return 1;
}
char* reallOK(char* ptr, int size, int sizenew) {
    char* ptr1 = (char*)malloc(sizenew);
    for (int i = 0; (i < size && i < sizenew); i++)
        *(ptr1 + i) = *(ptr + i);
    *(ptr1 + sizenew) = '\0';
    return ptr1;
}
int letter(char* line, int i) {
    if ((*(line + i) >= 'a' && *(line + i) <= 'z') || (*(line + i) >= 'A' && *(line + i) <= 'Z'))
        return 1;
    return 0;
}
void del(char* line, int i, int step) {
    for (int j = i; *(line + j + step - 1) != '\0'; j++) {
        *(line + j) = *(line + j + step);
    }
}
void firsttask(char** line, char** line2) {
    int k, len = 1;
    printf("input k: ");
    while (scanf_s("%d", &k) != 1 || getchar() != '\n') {
        printf("error\n");
        rewind(stdin);
    }
    printf("input string \n");
    *line = (char*)calloc(len, sizeof(char));
    for (int i = 0; ; i++) {
        *(*line + i) = getchar();
        if (*(*line + i) == '\n') {
            len = i;
            *(*line + i) = '\0';
            break;
        }
        else {
            len = i + 1;
            *line = reallOK(*line, len, (len + 1) * sizeof(char));
        }
    }
    int end = 0, start = 0;
    for (int i = len; i >= 0; i--) {
        if (!letter(*line, i) && letter(*line, i - 1))
            end = i - 1;
        if (letter(*line, i) && !letter(*line, i - 1)) {
            start = i;
            if (end - start + 1 < k) {
                del(*line, start, end - start + 1);
                len = len - end + start - 1;
            }
            end = 0, start = 0;
        }
    }
    *line = reallOK(*line, len, len * (sizeof(char)));
    for (int i = 0; line[0][i] != '\0'; i++)
        printf("%c", line[0][i]);
}
void secondtask(char** line1, char** line2) {
    int len1 = 1,len2 = 1;
    printf("input string \n");
    *line1 = (char*)calloc(len1, sizeof(char));
    for (int i = 0; ; i++) {
        *(*line1 + i) = getchar();
        if (*(*line1 + i) == '\n') {
            len1 = i;
            *(*line1 + i) = '\0';
            break;
        }
        else {
            len1 = i + 1;
            *line1 = reallOK(*line1, len1, (len1 + 1) * sizeof(char));
        }
    }
    printf("input the string to delete: ");
    *line2 = (char*)calloc(len2, sizeof(char));
    for (int i = 0; ; i++) {
        *(*line2 + i) = getchar();
        if (*(*line2 + i) == '\n') {
            len2 = i;
            *(*line2 + i) = '\0';
            break;
        }
        else {
            len2 = i + 1;
            *line2 = reallOK(*line2, len2, (len2 + 1) * sizeof(char));
        }
    }
    for (int i = 0; i < len1 - len2 + 1; i++) {
        if (comp(len2, *line2, *line1 + i)) {
            del(*line1, i, len2);
            len1 -= len2;
            break;
        }
    }
    *line1 = reallOK(*line1, len1+1, len1+1);
    for (int i = 0; i<len1; i++)
        printf("%c", line1[0][i]);
}