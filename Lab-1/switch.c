#include<stdio.h>

void main()
{
	int a, b;
	printf("Enter First Number: ");
	scanf("%d", &a);
	printf("Enter second number: ");
	scanf("%d", &b);

	int ch;
	while(1)
	{
	printf("\nMenu:\t0. Add\n\t1. Sub\n\t2. Mul\n\t3. Dev\n\nEnter your choice:");
	scanf("%d", &ch);
	switch(ch)
	{
		case 0:
		printf("Addition = %d\n", a+b);
		break;
	
		case 1:
		printf("Subtraction is = %d\n", a-b);
		break;

		case 2:
		printf("Multiplication = %d\n", a*b);
		break;

		case 3:
		printf("Division = %d\n", a/b);
		break;

		default:
		printf("None choice\n");
		exit(0);
	}
	}
}

