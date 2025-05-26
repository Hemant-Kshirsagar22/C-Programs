#include <stdio.h>

typedef struct info
{
	int i;
	float f;
	double d;
} info;

int main(void)
{
	info infoOne = { 1, 1.1f, 2.002 };
	info *pInfo = NULL;

	pInfo = &infoOne;

	printf("Direct Access\n\n");
	printf("infoOne.i = %d\ninfoOne.f = %f\ninfo.d = %lf\n\n",infoOne.i, infoOne.f, infoOne.d);

	pInfo->i = 100;
	pInfo->f = 100.22f;
	pInfo->d = 21.11;

	printf("Indirect Access\n\n");
	printf("pInfo->i = %d\npInfo->f = %f\npInfo->d = %lf\n\n", pInfo->i, pInfo->f, pInfo->d);

	return(0);
}

