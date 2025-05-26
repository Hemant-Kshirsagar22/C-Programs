#include <stdio.h>

struct info
{
	int i;
	float f;
	double d;
}infoOne = {10, 2.14f, 0.332}; // method 1

int main(void)
{
	struct info infoTwo = {3, 3.14f, 0.000220}; // method 2

	printf("\n\ninfoOne.i = %d\n", infoOne.i);
	printf("infoOne.f = %f\n", infoOne.f);
	printf("infoOne.d = %lf\n", infoOne.d);

	printf("\n\ninfoTwo.i = %d\n", infoTwo.i);
	printf("infoTwo.f = %f\n", infoTwo.f);
	printf("infoTwo.d = %lf\n\n\n", infoTwo.d);

	return(0);
}
