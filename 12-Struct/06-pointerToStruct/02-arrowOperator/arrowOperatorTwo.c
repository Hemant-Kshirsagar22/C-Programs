#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	int i;
	float f;
	double d;
} info;

int main(void)
{
	info *infoPtr = NULL;

	int structSize = sizeof(info);

	infoPtr = (info *)malloc(structSize);

	if(infoPtr == NULL)
	{
		printf("malloc() failed !!!\n\n");
		return(0);
	}

	infoPtr->i = 10;
	infoPtr->f = 3.14f;
	infoPtr->d = 2.334;

	printf("infoPtr->i : %d\ninfoPtr->f : %f\ninfoPtr->d : %lf\n\n", infoPtr->i, infoPtr->f, infoPtr->d);

	free(infoPtr);
	infoPtr = NULL;

	return(0);
}

