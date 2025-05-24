#include <stdio.h>

int main(void)
{
	// function declaration
	void arraySum(int *, int *, int *, int);
	void display(int *, int);

	int arrayOne[] = { 1, 2, 3, 4, 5 };
	int arrayTwo[] = { 1, 2, 3, 4, 5 };
	int arrayThree[5];

	arraySum(arrayThree, arrayOne, arrayTwo, 5);
	
	printf("\nArrayOne : ");
	display(arrayOne, 5);

	printf("\nArrayTwo : ");
	display(arrayTwo, 5);

	printf("\nAddition : ");
	display(arrayThree, 5);

	printf("\n\n");

	return(0);
}

void arraySum(int *result, int *arrayOne, int *arrayTwo, int size)
{
	if(size > 0)
	{
		size = size - 1;
		result[size] = arrayOne[size] + arrayTwo[size];
		printf("result[%d] = %d\n", size, result[size]);
		arraySum(result, arrayOne, arrayTwo, size);
	}
}

void display(int *array, int size)
{
	if(size > 0)
	{
		size = size - 1;
		display(array, size);
		printf("%d\t", array[size]);
	}
}

