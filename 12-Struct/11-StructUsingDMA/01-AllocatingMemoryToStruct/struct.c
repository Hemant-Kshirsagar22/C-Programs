#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DataOne
{
	char c;
	int i;
	float f;
	double d;
};

int main(void)
{
	struct DataOne *pDataOne = NULL;

	pDataOne = (struct DataOne *)malloc(1 * sizeof(struct DataOne));
	if(pDataOne == NULL)
	{
		printf("malloc() -> memory allocation failed !!!");
		return(-1);
	}

	printf("Before memset()\n");
	printf("dataOne.c : %c\n", (*pDataOne).c);
	printf("dataOne.i : %d\n", (*pDataOne).i);
	printf("dataOne.f : %f\n", (*pDataOne).f);
	printf("dataOne.d : %lf\n", (*pDataOne).d);

	memset((void *)pDataOne, 0, sizeof(struct DataOne));

	printf("\n\nAfter memset()\n");
	printf("dataOne.c : %c\n", (*pDataOne).c);
        printf("dataOne.i : %d\n", (*pDataOne).i);
        printf("dataOne.f : %f\n", (*pDataOne).f);
        printf("dataOne.d : %lf\n", (*pDataOne).d);

	return(0);
}

