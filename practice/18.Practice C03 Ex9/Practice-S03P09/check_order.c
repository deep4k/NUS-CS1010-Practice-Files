// check_order.c 
// Repeatedly reads positive integer, until the input value 
// is zero, or the data are not in increasing order.

#include <stdio.h>

int main(void) {
	int num1;
	int num2;

	num1 = 1;
	num2 = 2;

	while(num1<num2) {
		printf("Enter positive integer: ");
		scanf("%d", &num1);
		printf("Enter positive integer: ");
		scanf("%d", &num2);
	}

	if((num1>=num2) && (num1 != 0) && (num2 != 0)) {
		printf("Data are not in increasing order.\n");
	}

	if((num1 == 0) || (num2 == 0)) {
		printf("Data are in increasing order.\n");
	}

	return 0;
}

