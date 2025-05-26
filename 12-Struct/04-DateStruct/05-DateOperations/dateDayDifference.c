// working on it
#include <stdio.h>

typedef struct Date 
{
	int dd;
	int mm;
	int yyyy;
} Date;

void accept(Date *);
void display(Date *);
int isValidDate(Date *);
int numberOfDaysInMonth(Date *);
int calculateDaysBetweenDates(Date *, Date *);
int isLeapYear(Date *);

int main(void)
{
	Date dateOne;
	Date dateTwo;

	accept(&dateOne);
	accept(&dateTwo);

	display(&dateOne);
	display(&dateTwo);

	if(isValidDate(&dateOne) != 0 || isValidDate(&dateTwo) != 0)
	{
		printf("\n\nENTER VALID DATES\n\n");
		return(0);
	}

	printf("NUMBER OF DAYS IN BETWEEN DATES IS : %d\n\n", calculateDaysBetweenDates(&dateOne, &dateTwo));

	return(0);
}

void accept(Date *date)
{
	printf("\n\nEnter Day   : ");
	scanf("%d", &date->dd);

	printf("Enter Month : ");
	scanf("%d", &date->mm);

	printf("Enter Year  : ");
	scanf("%d", &date->yyyy);
}

void display(Date *date)
{
	printf("\n\n%d / %d / %d\n\n", date->dd, date->mm, date->yyyy);
}

int isValidDate(Date *date)
{
	int dayCount = numberOfDaysInMonth(date);

	if(dayCount == -1)
	{
		printf("ENTER VALID MONTH\n");
		return(-1);
	}

	if(date->dd < 1 || date->dd > dayCount)
	{
		printf("ENTER VALID DAY\n");
		return(-2);
	}

	return(0);
}
int numberOfDaysInMonth(Date *date)
{
	switch(date->mm)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return(31);
			break;

		case 2:
			if(isLeapYear(date))
			{
				return(29);
			}
			else
			{
				return(28);
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return(30);
			break;

		default:
			printf("PLEASE GIVE VALID MONTH\n\n");
			return(-1);
			break;
	}
}

int isLeapYear(Date *date)
{
	if((date->yyyy % 4 == 0) || (date->yyyy % 400 == 0))
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int calculateDaysBetweenDates(Date *dateOne, Date *dateTwo)
{
	int i = 0;
	int daysInMonthOne = 0;
	int daysInMonthTwo = 0;

	int numberOfDaysInBetween = 0;

	if(dateOne->mm == dateTwo->mm)
	{
		if(dateOne->dd > dateTwo->dd)
		{
			numberOfDaysInBetween = (dateOne->dd - dateTwo->dd);
		}
		else
		{
			numberOfDaysInBetween = (dateTwo->dd - dateOne->dd);
		}
	}
	else if(dateOne->mm < dateTwo->mm)
	{
		int daysInBetweenMonths = 0;

		daysInMonthOne = numberOfDaysInMonth(dateOne);
		daysInMonthTwo = numberOfDaysInMonth(dateTwo);

		Date date;
		date.mm = dateOne->mm;
		date.yyyy = dateOne->yyyy;

		for(i = dateOne->mm; i < dateTwo->mm; i++, date.mm = date.mm + 1)
		{
			daysInBetweenMonths += numberOfDaysInMonth(&date);
		}

		numberOfDaysInBetween = (daysInMonthOne - dateOne->dd) + (daysInBetweenMonths - (daysInMonthTwo - dateTwo->dd));
	}
	else if(dateOne->mm > dateTwo->mm)
	{
		int daysInBetweenMonths = 0;

		daysInMonthOne = numberOfDaysInMonth(dateOne);
		daysInMonthTwo = numberOfDaysInMonth(dateTwo);

		Date date;
		date.mm = dateTwo->mm;
		date.yyyy = dateOne->yyyy;

		for(i = dateTwo->mm; i <= dateOne->mm; i++, date.mm = date.mm + 1)
		{
			daysInBetweenMonths += numberOfDaysInMonth(&date);
		}

		numberOfDaysInBetween = (daysInMonthTwo - dateTwo->dd) + (daysInBetweenMonths - (daysInMonthOne - dateOne->dd));
	}

	return(numberOfDaysInBetween);
}

