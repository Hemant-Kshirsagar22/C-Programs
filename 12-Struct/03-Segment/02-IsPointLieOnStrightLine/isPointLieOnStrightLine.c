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
int isPointLieOnStraightLine(struct segment, struct Point);

int main(void)
{
	struct segment segmentOne;
	struct Point pOne;

	printf("Enter vertex 1 X-Coordinate : ");
	scanf("%f", &segmentOne.pOne.x);

	printf("Enter Vertex 1 Y-Coordinate : ");
	scanf("%f", &segmentOne.pOne.y);

	printf("Enter vertex 2 X-Coordinate : ");
    scanf("%f", &segmentOne.pTwo.x);

    printf("Enter Vertex 2 Y-Coordinate : ");
    scanf("%f", &segmentOne.pTwo.y);

	printf("\n\nEnter Point X-Coordinate : ");
	scanf("%f", &pOne.x);

	printf("Enter Point Y-Coordinate : ");
	scanf("%f", &pOne.y);

	printf("\n\n");

	if(isSegment(segmentOne) != TRUE)
	{
		printf("\n\nThis is not a Straight line\n\n");
		return(0);
	}

	if(isPointLieOnStraightLine(segmentOne, pOne))
	{
		printf("Point Lie On The Line\n\n");
	}
	else
	{
		printf("Point Not Lie On The Line\n\n");
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

int isPointLieOnStraightLine(struct segment seg, struct Point point)
{
	if((seg.pOne.x == point.x) && (point.x == seg.pTwo.x))
	{
		if(((seg.pOne.y <= point.y) && (point.y <= seg.pTwo.y)) || ((seg.pOne.y >= point.y) && (point.y >= seg.pTwo.y)))
		{
			return(TRUE);
		}
		else
		{
			return(FALSE);
		}
	}
	else if((seg.pOne.y == point.y) && (seg.pTwo.y == point.y))
    {
		if(((seg.pOne.x <= point.x) && (point.x <= seg.pTwo.x)) || ((seg.pOne.x >= point.x) && (point.x >= seg.pTwo.x)))
        {
            return(TRUE);
        }
		else
		{
			return(FALSE);
		}
    }
	else
	{
		return(FALSE);
	}
}
