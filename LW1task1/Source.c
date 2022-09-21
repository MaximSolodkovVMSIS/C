#include <stdio.h>        
int main(void)
{
    float a, b, c, S, V;
    printf("Enter a values\n");
    scanf_s("%f", &a);
    scanf_s("%f", &b);
    scanf_s("%f", &c);
    S = a * b * 2 + b * c * 2 + a * c * 2;
    V = a * b * c;
    printf("S = %.3f\n", S);
    printf("V = %.3f\n", V);



    return 0;
}