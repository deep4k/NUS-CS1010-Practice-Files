// AscendingDigits.c
// This program reads 3 positive integers and outputs "Yes" if
// the hundreds digits are in ascending order, or "No" otherwise.
#include <stdio.h>

int isAscending(int, int, int);

int main(void) { 

	int num1, num2, num3;

	int res;

	printf("Enter 3 positive integers: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	printf("The integers are %d, %d and %d\n", num1, num2, num3);

	res = isAscending(num1, num2, num3);

	if(res == 1)
		printf("Yes\n");
	else if(res == 0)
		printf("No\n");

	return 0;
}

// This function returns 1 if the digits at the hundredth position
// of the 3 parameters are in ascending order, or 0 otherwise.

int isAscending(int num1, int num2, int num3) {

	int res = 0; 

	if(((num1 % 1000)/100) < ((num2 % 1000)/100)) { 
		if(((num2 % 1000)/100)  < ((num3 % 1000)/100))
			res = 1;
	}

	return res;
}



