#include <stdio.h>

typedef struct Date
{
	int dd;
	int mm;
	int yyyy;
} Date;

void display(Date);

int main(void)
{
	Date date;
	
	date.dd   = 22;
	date.mm   = 3;
	date.yyyy = 2025;

	display(date);

	return(0);
}

void display(Date date)
{
	printf("\n%d / %d / %d\n\n", date.dd, date.mm, date.yyyy);
}

