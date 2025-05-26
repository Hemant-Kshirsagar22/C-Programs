#include <stdio.h>

struct info
{
	int i;
	int *iPtr;

	float f;
	float *fPtr;

	double d;
	double *dPtr;
}infoOne;

int main(void)
{
	infoOne.i = 10;
	infoOne.iPtr = &(infoOne.i);

	infoOne.f = 3.14f;
	infoOne.fPtr = &(infoOne.f);

	infoOne.d = 0.232323;
	infoOne.dPtr = &(infoOne.d);

	printf("\n\nl-value of infoOne.i           : %p\n", &(infoOne.i));
	printf("r-value of infoOne.iPtr        : %p\n", infoOne.iPtr);

	printf("l-value of infoOne.f           : %p\n", &(infoOne.f));
	printf("r-value of infoOne.fPtr        : %p\n", infoOne.fPtr);

	printf("l-value of infoOne.d           : %p\n", &(infoOne.d));
	printf("r-value of infoOne.dPtr        : %p\n", infoOne.dPtr);

	printf("\n\ndirect access   : infoOne.i    : %d\n", infoOne.i);
        printf("indirect access : infoOne.iPtr : %d\n", *(infoOne.iPtr));

        printf("direct access   : infoOne.f    : %f\n", infoOne.f);
        printf("indirect access : infoOne.fPtr : %f\n", *(infoOne.fPtr));

        printf("direct access   : infoOne.d    : %lf\n", infoOne.d);
        printf("indirect access : infoOne.dPtr : %lf\n", *(infoOne.dPtr));

	*infoOne.iPtr = 20;
	*infoOne.fPtr = 23.009f;
	*infoOne.dPtr = 0.0003;

	printf("\n\ndirect access   : infoOne.i    : %d\n", infoOne.i);
	printf("indirect access : infoOne.iPtr : %d\n", *(infoOne.iPtr));
	
	printf("direct access   : infoOne.f    : %f\n", infoOne.f);
	printf("indirect access : infoOne.fPtr : %f\n", *(infoOne.fPtr));

	printf("direct access   : infoOne.d    : %lf\n", infoOne.d);
	printf("indirect access : infoOne.dPtr : %lf\n\n\n", *(infoOne.dPtr));

	return(0);
}
