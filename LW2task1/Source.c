#include <stdio.h>  
int sum(x) {
	return (x % 10) + ((x / 10) % 10) + (x / 100);
}
int flip(n)
{
	int m = 0, d = n;
	while (d > 0) {
		m = m * 10 + d % 10;
		d = d / 10;
	}
	return m;
}
int main()
{
	int a = 401;
	while (a < 500)
	{
		if (sum(a) == 9 && a == flip(a) * 47 / 36) {
			printf("the number is %d", a);
			return 0;
		}
		a = a + 1;
	}
	printf("Error");
	return 0;
}