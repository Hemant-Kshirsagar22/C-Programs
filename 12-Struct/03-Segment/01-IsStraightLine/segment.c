#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct Point
{
	float x;
	float y;
};

struct segment
{
	struct Point pOne;
	struct Point pTwo;
};

int isSegment(struct segment);

int main(void)
{
	struct segment segmentOne;

	printf("Enter vertex 1 X-Coordinate : ");
	scanf("%f", &segmentOne.pOne.x);

	printf("Enter Vertex 1 Y-Coordinate : ");
	scanf("%f", &segmentOne.pOne.y);

	printf("Enter vertex 2 X-Coordinate : ");
        scanf("%f", &segmentOne.pTwo.x);

        printf("Enter Vertex 2 Y-Coordinate : ");
        scanf("%f", &segmentOne.pTwo.y);

	if(isSegment(segmentOne))
	{
		printf("\n\nThis is a Straight line\n\n");
	}
	else
	{
		printf("\n\nThis is not a Straight line\n\n");
	}

	return(0);
}

int isSegment(struct segment seg)
{

	if((seg.pOne.x == seg.pTwo.x) || (seg.pOne.y == seg.pTwo.y))
	{
		return(TRUE);
	}
	else
	{
		return(FALSE);
	}
}

