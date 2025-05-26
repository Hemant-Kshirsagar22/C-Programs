#include <stdio.h>

typedef struct info
{
	int i;
	float f;
	double d;
} info;

typedef info * pInfo;

// global function declarations
void display(pInfo);

int main(int argc, char *argv[])
{
	info infoOne = { 10, 20.03f, 0.002323 };

	display(&infoOne);
	return(0);
}

void display(pInfo infoPtr)
{
	printf("\ninfo->i = %d\ninfo->f = %f\ninfo->d = %lf\n\n", infoPtr->i, infoPtr->f, infoPtr->d);
}

