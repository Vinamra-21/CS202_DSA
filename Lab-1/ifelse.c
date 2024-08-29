#include<stdio.h>

void main()
{
	int a, b;
	printf("Enter First Number: ");
	scanf("%d", &a);
	printf("Enter second number: ");
	scanf("%d", &b);

	if(a > b)
	{
		printf("%d is greater than %d\n", a, b);
	}
	else
	{
		printf("%d is less than %d\n", a, b);
	}
}

