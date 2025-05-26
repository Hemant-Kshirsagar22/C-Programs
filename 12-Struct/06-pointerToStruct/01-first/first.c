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
	struct info *infoPtr = NULL;

	int structSize = sizeof(struct info);

	infoPtr = (struct info *)malloc(structSize);

	if(infoPtr == NULL)
	{
		printf("malloc() failed !!!\n\n");
		return(0);
	}

	(*infoPtr).i = 10;
	(*infoPtr).f = 3.142f;
	(*infoPtr).d = 0.00006;

	printf("info.i = %d\ninfo.f = %f\ninfo.d = %lf\n\n",
			(*infoPtr).i,
			(*infoPtr).f,
			(*infoPtr).d);

	
	free(infoPtr);
	infoPtr = NULL;

	return(0);
}
