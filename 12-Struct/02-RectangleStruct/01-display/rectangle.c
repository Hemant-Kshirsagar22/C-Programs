#include <stdio.h>

struct rectangle 
{
	float length;
	float breadth;
};

void displayRectangle(struct rectangle);

int main(void)
{
	struct rectangle rectangleOne = { 10.0f, 20.0f };
	struct rectangle rectangleTwo = { 20.0f, 10.0f };

	displayRectangle(rectangleOne);
	displayRectangle(rectangleTwo);

	return(0);
}

void displayRectangle(struct rectangle rectangle)
{
	printf("\n");
	printf("Rectangle Length  : %.2f\n", rectangle.length);
	printf("Rectangle breadth : %.2f\n\n", rectangle.breadth);
}


