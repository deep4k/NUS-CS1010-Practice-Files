// countInputs.c
// To count the number of input values user entered.
#include <stdio.h>

int main(void) {   

	int input;
	int number;

	printf("Enter integers, terminate with ctrl-d\n");

	while (scanf("%d", &input)==1){
		number++;
	}

	printf("Number of values entered = %d\n",number);

	return 0;
}

