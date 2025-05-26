#include <stdio.h>

struct rectangle 
{
	float length;
	float breadth;
};

void drawRectangle(struct rectangle);

int main(void)
{
	struct rectangle rectangleOne = { 2.0f, 4.0f };
	struct rectangle rectangleTwo = { 4.0f, 2.0f };

    drawRectangle(rectangleOne);
    drawRectangle(rectangleTwo);

	return(0);
}

void drawRectangle(struct rectangle rectangle)
{
	printf("\n");
	printf("Rectangle Length  : %.2f\n", rectangle.length);
	printf("Rectangle breadth : %.2f\n\n", rectangle.breadth);

	float i = 0.0f;
	float j = 0.0f;
    float k = 0.0f;

	for(i = 0; i < rectangle.breadth;i += 1.0f)
	{
        printf("\t\t\t");
		if(i == 0 || i == rectangle.breadth - 1.0f)
        {
            for(k = 0; k < rectangle.breadth; k += 1.0f)
            {
                printf("-");
            }
            printf("\n");
            
            continue;
        }

		for(j = 0; j < rectangle.length ; j += 1.0f)
		{
			if(j == 0 || j == rectangle.length - 1.0f)
			{
				printf("|");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
    
    printf("\n\n");
}


