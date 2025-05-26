#include <stdio.h>

enum Months
{
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

struct Date
{
	int day;
	enum Months month;
	int year;
};

int main(void)
{
	struct Date dayOne = { 15, MARCH, 2025 };
	int structSize = 0;
	int memberOne = 0;
	int memberTwo = 0;
	int memberThree = 0;

	printf("\n%d / %d / %d\n\n",dayOne.day, dayOne.month, dayOne.year);

	structSize = sizeof(struct Date);
	memberOne = sizeof(dayOne.day);
	memberTwo = sizeof(dayOne.month);
	memberThree = sizeof(dayOne.year);

	printf("sizeof struct Date       : %d\n",structSize);
	printf("sizeof struct Date.day   : %d\n", memberOne);
	printf("sizeof struct Date.month : %d\n", memberTwo);
	printf("sizeof struct Date.year  : %d\n\n", memberThree);

	return(0);
}

