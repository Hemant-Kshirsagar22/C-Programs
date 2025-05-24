#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// function declarations
	void arrayElementFactorial(int *, int *, int);
	void display(int *, int);
	void fillArray(int *, int);
	int *allocate(int);


	int numberOfElements = 0;
	printf("Enter The Number Of Element : ");
	scanf("%d", &numberOfElements);

	int *arrayOne = allocate(numberOfElements);
	int *result = allocate(numberOfElements);

	fillArray(arrayOne, numberOfElements);

	printf("\n\nArrayOne : \n");
	display(arrayOne, numberOfElements);
	printf("\n\n");

	arrayElementFactorial(result, arrayOne, numberOfElements);

	printf("Result : \n");
	display(result, numberOfElements);
	printf("\n\n");

	if(result)
	{
		free(result);
		result = NULL;
	}

	if(arrayOne)
	{
		free(arrayOne);
		arrayOne = NULL;
	}
	return(0);
}

int factorial(int number)
{
	if(number >= 1)
	{
		return(number * factorial(number - 1));
	}
	else
	{
		return(1);
	}

}

void arrayElementFactorial(int *result, int *array, int size)
{
	if(size > 0)
	{
		size--;
		result[size] = factorial(array[size]);
		arrayElementFactorial(result, array, size);
	}
}

void fillArray(int *array, int size)
{
	if(size > 0)
	{
		size--;
//		printf("%d\n", size);
		array[size] = rand() % 10;
		fillArray(array, size);
	}
}

void display(int *array, int size)
{
	if(size > 0)
	{
		size--;
//		printf("%d\n", size);
		printf("%d\t", array[size]);
		display(array, size);
	}
}

int *allocate(int numberOfElements)
{
	int *res = (int *)malloc(numberOfElements * sizeof(int));

	if(res != NULL)
	{
		return(res);
	}
	else
	{
		printf("Error Whiel Allocating variables !!!\n\n");
		return(NULL);
	}
}
