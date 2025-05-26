#include <stdio.h>

struct rectangle
{
	float length;
	float breadth;
};

int main(void)
{
	struct rectangle rectangleOne = { 10.0f, 20.0f };
	
	printf("\n\nRectangle length : %.2f\n", rectangleOne.length);
	printf("Rectangle Breadth : %.2f\n\n\n", rectangleOne.breadth);
	return(0);
}
