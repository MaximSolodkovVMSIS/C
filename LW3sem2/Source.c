#include "function.h"
int main() {
    int result = menu();
    if (result != 0)
        printf("An error occurred while converting the image.\n");
    return 0;
}