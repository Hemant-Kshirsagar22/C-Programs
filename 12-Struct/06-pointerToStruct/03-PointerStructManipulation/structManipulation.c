#include <stdio.h>

typedef struct info
{
	int i;
	float f;
	double d;
} info;

int main(void)
{
	info infoOne = { 10, 20.004f, 0.00004 };
	info *pInfo = NULL;

	pInfo = &infoOne;

	printf("Direct Access\n\n");
	printf("info.i = %d\ninfo.f = %f\ninfo.d = %lf\n\n", infoOne.i, infoOne.f, infoOne.d);

	(*pInfo).i = 100;
	(*pInfo).f = 3.14f;
	(*pInfo).d = 1.00021;

	printf("Indirect Access\n\n");
	printf("(*pInfo).i = %d\n(*pInfo).f = %f\n(*pInfo).d = %lf\n\n", (*pInfo).i, (*pInfo).f, (*pInfo).d);

	return(0);
}
