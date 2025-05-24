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

/*int factorial(int numberOne)
{
	if(numberOne == 0)
	{
		return(1);
	}

	return(numberOne * factorial(numberOne - 1)); 
}*/


int factorial(int numberOne)
{
	if(numberOne > 1)
	{
		return(numberOne * factorial(numberOne - 1));
	}
	else
	{
		return(1);
	}
}

