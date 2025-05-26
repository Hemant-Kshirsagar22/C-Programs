#include <stdio.h>

struct infoOne
{
	int i;
	float f;
	double d;
};

struct infoTwo
{
	int i;
	double d;
	float f;
};

int main(void)
{
	int structSizeOne = 0;
	int structSizeTwo = 0;

	// same struct but order of member is changed but we got differet sizes because while allocating to struct bit allienment happens.
	// while allocating memory to struct the biggest type block is cosider to allocate memory to it.
	// in above struct infoOne  biggest size is 8 bytes so first two members i.e. int and float is allocated in one block and other block is given to double hence size is 16 bytes


	// for struct infoTwo biggest size is 8 bytes so first member got 8 byte block but it uses only 4 bytes from it and other is dosent use
	// double member cant fit in remaining so new block is allocated to double
	// for float member another block is allcated so size of the struct infoTwo is 24 bytes
	// hence the sequence of struct members matters while allocating memory
	
	// rules for struct
	// 1. add members in increasing order of size
	// 2. same type members should allocate one after the another.



	structSizeOne = sizeof(struct infoOne);
	structSizeTwo = sizeof(struct infoTwo);

	printf("\n\nsizeof struct infoOne : %d\nsizeof struct infoTwo : %d\n\n", structSizeOne, structSizeTwo);

	return(0);
}
