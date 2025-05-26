#include <stdio.h>

typedef struct Date { int dd; int mm; int yyyy; } Date;

void accept(Date *);
void display(Date *);

int main(void)
{
	Date date;

	accept(&date);

	display(&date);

	return(0);
}

void accept(Date *date)
{
	printf("\n\nEnter Day   : ");
	scanf("%d", &(*date).dd);

	printf("Enter Month : ");
	scanf("%d", &(*date).mm);

	printf("Enter Year  : ");
	scanf("%d", &date->yyyy);
}

void display(Date *date)
{
	printf("\n\n%d / %d / %d\n\n", date->dd, (*date).mm, date->yyyy);
}

