#include <stdio.h>

struct Point
{
	float x;
	float y;
};

int main(int argc, char *argv[])
{
	struct Point pointOne = { 2.5f, 3.5f };

	printf("\n\nStruct Point Display\n\n");
	printf("x : %.2f\n", pointOne.x);
	printf("y : %.2f\n\n\n", pointOne.y);

	return(0);
}
