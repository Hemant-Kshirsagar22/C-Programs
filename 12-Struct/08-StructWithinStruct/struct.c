#include <stdio.h>

// method One
struct Point
{
	int x;
	int y;
};

struct Line
{
	struct Point pointOne;
	struct Point pointTwo;
}lineOne;

// method Two
struct line
{
	struct point
	{
		int x;
		int y;
	}pointOne, pointTwo;
}lineTwo = { { 10, 20 }, { 20, 20 } };

int main(void)
{
	printf("\n\nMethod One \n\n");
	printf("lineOne.pointOne.x = %d\n", lineOne.pointOne.x);
	printf("lineOne.pointOne.y = %d\n", lineOne.pointOne.y);
	printf("lineOne.pointTwo.x = %d\n", lineOne.pointTwo.x);
	printf("lineOne.pointTwo.y = %d\n", lineOne.pointTwo.y);

	printf("\n\nnethod Two\n\n");
	printf("lineTwo.pointOne.x = %d\n", lineTwo.pointOne.x);
	printf("lineTwo.pointOne.y = %d\n", lineTwo.pointOne.y);
	printf("lineTwo.pointTwo.x = %d\n", lineTwo.pointTwo.x);
	printf("lineTwo.pointTwo.y = %d\n\n\n", lineTwo.pointTwo.y);
	return(0);
}
