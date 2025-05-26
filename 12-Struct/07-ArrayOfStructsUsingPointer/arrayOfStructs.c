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
	struct info *pInfo = NULL;
	int structSize = 0;
	int numberOfElements = 0;
	int totalBytes = 0;

	structSize = sizeof(struct info);
	
	numberOfElements = 10;

	totalBytes = structSize * numberOfElements;

	pInfo = (struct info *)malloc(totalBytes);

	if(pInfo == NULL)
	{
		printf("malloc() failed !!!\n\n");
		return(-1);
	}

	for(int i = 0; i < numberOfElements; i++)
	{
		(*(pInfo + i)).i = (int)rand();
		(*(pInfo + i)).f = (float)rand();
		(*(pInfo + i)).d = (double)rand();
	}

	for(int i = 0; i < numberOfElements; i++)
	{
		printf("\n");
		printf("pInfo[%d].i = %d\n", i, pInfo[i].i);
		printf("pInfo[%d].f = %f\n", i, pInfo[i].f);
		printf("pInfo[%d].d = %lf\n\n", i, pInfo[i].d);
	}
	
	free(pInfo);
	pInfo = NULL;
	return(0);
}
