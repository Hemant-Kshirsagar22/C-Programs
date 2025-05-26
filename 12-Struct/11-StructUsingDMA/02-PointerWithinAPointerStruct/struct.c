#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data
{
	int i;
	int *iPtr;
};

int main(void)
{

	struct Data *pData = NULL;

	pData = (struct Data *)malloc(1 * sizeof(struct Data));

	if(pData == NULL)
	{
		printf("malloc failed !!!\n");
		return(-1);
	}

	memset((void *)pData, 0, sizeof(struct Data));

	(*pData).i = 10;
	(*pData).iPtr = &((*pData).i);

	printf("pData.i = %d\n", (*pData).i);
	printf("*pData.iPtr = %d\n", *((*pData).iPtr));
	return(0);
}

