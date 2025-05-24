#include <stdio.h>

int main(void)
{
	// function declarations
	void printCountDown(int);

	int numberOne = 0;
	printf("Enter The Number : ");
	scanf("%d", &numberOne);

	printCountDown(numberOne);
	return(0);
}

void printCountDown(int numberOne)
{
	printf("%d\n", numberOne);

	if(numberOne > 0)
	{
		printCountDown(numberOne - 1);
	}
}

