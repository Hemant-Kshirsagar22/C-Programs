#include <stdio.h>

int numberOne = 0;
int numberTwo = 0;
int counterNumber = 0;
int numberOfRows = 0;

int main(void)
{
	printf("\n\nEnter Number Of Rows : ");
	scanf("%d",&numberOfRows);

	printf("\n\n");

	counterNumber = 1;

	for(numberOne = 1; numberOne <= numberOfRows;numberOne++)
	{
		for(numberTwo = numberOfRows ;numberTwo > numberOne;numberTwo--)
		{
			printf(" ");
		}

		for(numberTwo = 1; numberTwo <= numberOne;numberTwo++,counterNumber++)
		{
			printf("%d",counterNumber);
		}

		printf("\n");
	}

	printf("\n\n");

	return(0);
}

/*
OUTPUT


Enter Number Of Rows : 4


   1
  23
 456
78910



*/
