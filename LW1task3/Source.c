#include <stdio.h>        
int main()
{
	float a, b;
	printf("Enter the cordinates ");
	scanf_s("%f", &a);
	scanf_s("%f", &b);
	if (b < 0)
	{
		printf("Doesn't satisfy the condition"); //�� ���������������� ������� 
		return 0;
	}
	if (a * a + b * b <= 1) {
		printf("The point is located at the top of the circle");  //����� ��������� � ������� ����� �����
	}
	else
		printf("The point isn't in upper part of the circle");    //����� �� ��������� � ������� ����� ����a 
	return 0;
}