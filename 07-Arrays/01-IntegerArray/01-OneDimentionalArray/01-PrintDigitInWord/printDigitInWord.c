#include <stdio.h>

int digit = 0;

int main(void)
{
	// local function declarations
	void printDigitToWord(int);

	printf("\n\nEnter A Digit : ");
	scanf("%d", &digit);

	printDigitToWord(digit);

	return(0);
}

void printDigitToWord(int digit)
{
	printf("\n\n");

	switch (digit)
	{
	case 0:
		printf("You Have Enter : \"Zero\"\n");
		break;

	case 1:
		printf("You Have Enter : \"One\"\n");
		break;

	case 2:
		printf("You Have Enter : \"Two\"\n");
		break;

	case 3:
		printf("You Have Enter : \"Three\"\n");
		break;

	case 4:
		printf("You Have Enter : \"Four\"\n");
		break;

	case 5:
		printf("You Have Enter : \"Five\"\n");
		break;

	case 6:
		printf("You Have Enter : \"Six\"\n");
		break;

	case 7:
		printf("You Have Enter : \"Seven\"\n");
		break;

	case 8:
		printf("You Have Enter : \"Eight\"\n");
		break;

	case 9:
		printf("You Have Enter : \"Nine\"\n");
		break;

	default:
		printf("Please Enter Digit (Between 0 TO 9)");
		break;
	}

	printf("\n\n");

}
