#include <stdio.h>

int inputNumber = 0;
int reverseNum = 0;

int main(void)
{
	// local function declarations
	int reverseNumber(int);
	void printNumberToWords(int);
	printf("Enter A Number : ");
	scanf("%d", &inputNumber);
	
	reverseNum = reverseNumber(inputNumber);

	printf("Input Number : %d\treverseNumber : %d\n", inputNumber, reverseNum);

	printNumberToWords(reverseNum);

	return(0);
}

int reverseNumber(int number)
{
	int numberOne = 0; 
	int numberTwo = -1;
	int result = 0;

	// reversing the number
	while (number > 0)
	{
		numberOne = number % 10;

		result = (result * 10) + numberOne;
		if (numberTwo == 0)
		{
			result = result * 10;
		}

		numberTwo = numberOne;

		number = number / 10;

	}

	return(result);
}

void printNumberToWords(int number)
{

}
