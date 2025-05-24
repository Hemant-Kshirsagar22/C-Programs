#include <stdio.h>

int main(void)
{
	int arrayElementSum(int *, int);
	void display(int *, int);

	int arrayOne[] = { 1, 2, 3, 4, 5 };

	printf("\n\nArrayOne : ");
	display(arrayOne, 5);
	printf("\n\nArraySum = %d\n\n", arrayElementSum(arrayOne, 5));

	return(0);
}

int arrayElementSum(int *array, int size)
{
	size--;
	if(size == 0)
	{
		return(array[size]);
	}

	return(array[size] + arrayElementSum(array, size));
}


void display(int *array, int size)
{
	if(size > 0)
	{
		size = size - 1;
		display(array,size);
		printf("%d\t",array[size]);
	}
}
