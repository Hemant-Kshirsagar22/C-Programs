#include <stdio.h>

#define MAX_LENGTH 512

// global variable declarations
struct StudentData
{
	char div;
	int rollNumber;
	int marks[5];
	char name[MAX_LENGTH];
};

// global function declarations
void acceptStudentData(struct StudentData *);
void displayStudentData(struct StudentData *);
int getTotalMarks(int *);
float calculatePercentage(int);

int main(void)
{
	struct StudentData studentData;

	acceptStudentData(&studentData);
	displayStudentData(&studentData);

	printf("\n\nTotal      : %d\n", getTotalMarks(studentData.marks));
    	printf("Percentage : %3.2f\n", calculatePercentage(getTotalMarks(studentData.marks)));
    	printf("\n-------------------------------------------------\n");

	return(0);
}

void acceptStudentData(struct StudentData *studentData)
{
	int i = 0;

	printf("\n-------------------------------------------------\n");
	printf("\t\tACCEPTING STUDENT MARKS");
	printf("\n-------------------------------------------------\n");
	printf("\nEnter Roll Number : ");
	scanf("%d", &(*studentData).rollNumber);

	fflush(stdin);
	printf("Enter Name : ");
	gets((*studentData).name);

	fflush(stdin);
	printf("Enter Class : ");
	(*studentData).div = getc(stdin);

	for(i = 0; i < 5; i++)
	{
		while(1)
		{
			printf("Enter Marks In Subject %d Out Of 100 : ", (i + 1));
			scanf("%d", &(*studentData).marks[i]);

			if((*studentData).marks[i] >= 0 && (*studentData).marks[i] <= 100)
			{
				break;
			}
			else
			{
				printf("Enter Marks between 0 to 100 !!!\n\n");
			}
		}
	}

	printf("\n-------------------------------------------------\n\n");
}

void displayStudentData(struct StudentData *studentData)
{
	int i = 0;

	printf("\n-------------------------------------------------\n");
    	printf("\t\tDISPLAYING STUDENT MARKS");
    	printf("\n-------------------------------------------------\n");

	printf("\nRoll Number : %d\n", (*studentData).rollNumber);
	printf("\nName        : %s\n", (*studentData).name);
	printf("\nDivision    : %c\n", (*studentData).div);

	printf("\n\t\t|-----------------|\n");
	for(i = 0; i < 5; i++)
	{
		printf("\t\t| Subject %d | %3d |\n", (i + 1), (*studentData).marks[i]);
		printf("\t\t|-----------------|\n");
	}
}

int getTotalMarks(int *marks)
{
    int i = 0;
    int total = 0;
    
    for(i = 0; i < 5; i++)
    {
        total = total + *(marks + i);
    }
    
    return(total);
}

float calculatePercentage(int totalMarks)
{
    return(((float)totalMarks / 500.0f) * 100.0f);
}
