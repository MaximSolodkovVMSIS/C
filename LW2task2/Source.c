#include <stdio.h>  

int main()
{
	int a;
	long int x;
	printf("Enter a ");
	scanf_s("%d", &a);
	x = a * a + 1;
	while (x < 1000001) {
		x = x * x + 1;
		if (x >= 1000001)
			break;
	}

	printf("x = %ld", x);
	return 0;
}