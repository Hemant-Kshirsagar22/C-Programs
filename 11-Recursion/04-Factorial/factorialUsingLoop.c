#include <stdio.h>

int main(void)
{
	int factorial(int);

	int numberOne = 0;

	printf("Enter The Number To Find Factorial : ");
	scanf("%d", &numberOne);

	printf("%d! = %d\n", numberOne, factorial(numberOne));

	return(0);
}

int factorial(int numberOne)
{
	int sum = 1;

	if(numberOne == 0)
	{
		return(sum);
	}

	do
	{
		sum = sum * numberOne;
		numberOne--;
	}while(numberOne > 0);

	return(sum);
}

