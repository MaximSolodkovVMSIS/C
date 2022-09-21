#include <stdio.h>        
int main()
{
	int a, x, b;
	float c;
	printf("Enter the expression\n 1 is +\n 2 is -\n 3 is *\n 4 is / \n");
	scanf_s("%d", &a);
	scanf_s("%d", &x);
	scanf_s("%d", &b);
	switch (x)
	{
	case 1:
		c = a + b;
		break;
	case 2:
		c = a - b;
		break;
	case 3:
		c = a * b;
		break;
	case 4:
		c = a;
		c = c / b;
		break;
	}
	printf("%.3f", c);
	return 0;
}