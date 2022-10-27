#include <stdio.h>        
int main()
{
	float a, b;
	printf("Enter the cordinates ");
	scanf_s("%f", &a);
	scanf_s("%f", &b);
	if (b < 0)
	{
		printf("Doesn't satisfy the condition"); //не удвоволетворятет условию 
		return 0;
	}
	if (a * a + b * b <= 1) {
		printf("The point is located at the top of the circle");  //точка находится в верхней части круга
	}
	else
		printf("The point isn't in upper part of the circle");    //точка не находится в верхней части кругa 
	return 0;
}