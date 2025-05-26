#include <stdio.h>
#include <stdlib.h>

struct info
{
	int i;
	float f;
	double d;
};

int main(void)
{
	struct info* infoPtr;

	int structSize = sizeof(struct info);

	infoPtr = (struct info *)malloc(structSize);

	if(infoPtr == NULL)
	{
		printf("malloc() failed !!!\n\n");
		return(0);
	}

	infoPtr->i = 10;
	infoPtr->f = 3.142f;
	infoPtr->d = 123.44444;

	printf("infoPtr->i : %d\ninfoPtr->f = %f\ninfoPtr->d = %lf\n\n", infoPtr->i, infoPtr->f, infoPtr->d);

	free(infoPtr);
	infoPtr = NULL;

	return(0);
}
