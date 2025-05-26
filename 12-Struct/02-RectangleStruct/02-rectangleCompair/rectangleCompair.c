#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct rectangle
{
	float length;
	float breadth;
};

void displayRect(struct rectangle);
int compairRect(struct rectangle, struct rectangle);

int main(int argc, char *argv[])
{
	struct rectangle rectOne;
	struct rectangle rectTwo;

	printf("\n\nEnter Length  : ");
        scanf("%f", &rectOne.length);

        printf("\nEnter Breadth : ");
        scanf("%f", &rectOne.breadth);

	printf("\n\nEnter Length  : ");
        scanf("%f", &rectTwo.length);

        printf("\nEnter Breadth : ");
        scanf("%f", &rectTwo.breadth);

	displayRect(rectOne);
	displayRect(rectTwo);

	if(compairRect(rectOne, rectTwo) == TRUE)
	{
		printf("\n\nRectangles Are Equal\n\n");
	}
	else
	{
		printf("\n\nRectangles Are NOT Equal !!!\n\n");
	}
	
	return(0);
}

int compairRect(struct rectangle rectOne, struct rectangle rectTwo)
{
	if((rectOne.length == rectTwo.length) && (rectOne.breadth == rectTwo.breadth))
	{
		return(TRUE);
	}
	else
	{
		return(FALSE);
	}
}

void displayRect(struct rectangle rect)
{
	static int rectCount = 1;
	printf("\nRectangle %d : \n\n", rectCount);

	printf("\t\t\tLength  : %.2f\n", rect.length);
	printf("\t\t\tBreadth : %.2f\n\n", rect.breadth);

	rectCount++;
}
