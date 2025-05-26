#include <stdio.h>

struct Date
{
	int dd;
	int mm;
	int yyyy;
};

void display(struct Date);

int main(void)
{
	struct Date date = {22, 3, 2025};
	
	display(date);

	return(0);
}

void display(struct Date date)
{
	printf("\n\n%d/%d/%d\n\n",date.dd, date.mm, date.yyyy);
}

