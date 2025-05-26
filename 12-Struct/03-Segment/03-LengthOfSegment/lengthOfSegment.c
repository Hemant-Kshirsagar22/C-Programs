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
int lengthOfLine(struct segment);

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

	if(isSegment(segmentOne) != TRUE)
	{
		printf("\n\nThis is not a Straight line\n\n");
		return(0);
	}

	printf("\n\nLength Of Line : %d\n\n", lengthOfLine(segmentOne));

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

int lengthOfLine(struct segment seg)
{
	if(seg.pOne.x == seg.pTwo.x)
	{
        if(seg.pOne.y > 0 && seg.pTwo.y > 0)
        {
            if(seg.pOne.y > seg.pTwo.y)
            {
                return(seg.pOne.y - seg.pTwo.y);
            }
            else
            {
                return(seg.pTwo.y - seg.pOne.y);
            }
        }
		if(seg.pOne.y < 0)
        {
            seg.pOne.y = seg.pOne.y * -1;
        }
        if(seg.pTwo.y < 0)
        {
            seg.pTwo.y = seg.pTwo.y * -1;
        }

		return(seg.pOne.y + seg.pTwo.y);
	}
    else if(seg.pOne.y == seg.pTwo.y)
    {
        
        if(seg.pOne.x > 0 && seg.pTwo.x > 0)
        {
            if(seg.pOne.x > seg.pTwo.x)
            {
                return(seg.pOne.x - seg.pTwo.x);
            }
            else
            {
                return(seg.pTwo.x - seg.pOne.x);
            }
        }
        
        if(seg.pOne.x < 0)
        {
                seg.pOne.x = seg.pOne.x * -1;
        }
        if(seg.pTwo.x < 0)
        {
            seg.pTwo.x = seg.pTwo.x * -1;
        }
        
        return(seg.pOne.x + seg.pTwo.x);
    }
    else
    {
        return(0);
    }

}
