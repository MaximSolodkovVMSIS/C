#include <stdio.h>  
int main()
{
	int N, a = 1, b = 1;
	printf("Enter N more then 1: ");
	scanf_s("%d", &N);
	if (N <= 1) {
		printf("Error");
		return 0;
	}
	while (N >= a && N >= b)
	{
		if (a > b)
			b += a;
		else
			a += b;
	}
	if (a < b)
		printf("Number is %d", b);
	else
		printf("Number is %d", a);
	return 0;
}