#include <stdio.h>

int main(void)
{
	void div(int, int, int*);

	int numberOne = 0;
	int numberTwo = 0;
	int result = 0;

	printf("Enter First Number : ");
	scanf("%d",&numberOne);

	printf("Enter Second Number : ");
	scanf("%d",&numberTwo);

	div(numberOne,numberTwo,&result);

	printf("%d / %d = %d\n",numberOne, numberTwo, result);

	return(0);
}

void div(int numberOne, int numberTwo, int *result)
{
	*result = numberOne / numberTwo;
}
