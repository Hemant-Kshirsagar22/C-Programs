#include <stdio.h>

int main(void)
{
	// function declarations
	void arrayPrint(int *, int);

	// local variables
	int arrayOne[] = {1,2,3,4,5};

	arrayPrint(arrayOne, 5 - 1);

	return(0);
}

/*void arrayPrint(int *array, int size)
{
	static int i = 0;

	if(i < size)
	{
		printf("array[%d] = %d\n", i, array[i]);
		i++;
		arrayPrint(array, size);
	}
}*/

void arrayPrint(int *array, int size)
{
	if(size > 0)
	{
		arrayPrint(array, size - 1);
	}

	printf("array[%d] = %d\n", size, array[size]);
}

