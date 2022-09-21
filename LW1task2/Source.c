#include <stdio.h>    
#include <math.h>
int main()
{

	double x1, x2, x3, y1, y2, y3, a, b, c;
	printf("Enter the coordinates of the first vertex: ");
	scanf_s("%lf%lf", &x1, &y1);
	printf("Enter the coordinates of the second vertex: ");
	scanf_s("%lf%lf", &x2, &y2);
	printf("Enter the coordinates of the third vertex: ");
	scanf_s("%lf%lf", &x3, &y3);
	a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	printf("a = %lf\n b = %lf\n c = %lf\n", a, b, c);
	if (a >= b + c || b >= a + c || c >= a + b)
	{
		printf("There is no triangle");
		return 0;
	}
	if (a * a + b * b == c * c)
		printf("The triangle is rectilinear");
	else if (b * b + c * c == a * a)
		printf("The triangle is rectilinear");
	else if (a * a + c * c == b * b)
		printf("The triangle is rectilinear"); //
	else if (a * a + b * b < c * c)
		printf("The triangle is obtuse");
	else if (c * c + b * b < a * a)
		printf("The triangle is obtuse");
	else if (c * c + a * a < b * b)
		printf("The triangle is obtuse"); //
	else printf("The triangle is acute - angled");


	return 0;
}