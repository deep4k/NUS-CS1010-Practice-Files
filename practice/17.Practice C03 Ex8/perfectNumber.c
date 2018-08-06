// perfectNumber.c 
// Repeatedly reads a non-negative value, and stops when zero is read.
// For each positive value read, it checks if the value is a perfect number.

#include <stdio.h>

int is_perfect(int);
void print_output(int, int);

int main(void) {
	int num=1;
	int res;

	while(num!=0) {
		printf("Enter number: ");
		scanf("%d", &num);

		if(num==0) {
			break;
		}

		res = is_perfect(num);
		print_output(res, num);

	}

	return 0;
}
// this function checks if the number passed is perfect or not
// 1 for true and 0 for false
// precond num > 0

int is_perfect(int num) {

	int i;
	int j=0;
	int sum=0;

	for(i=1;i<=num-1;i++) {
		if(((num%i)==0)) {
			j = i;
		}
		sum = sum + j;
		j = 0;
	}

	if(sum == num) {
		return 1;
	}

	return 0;
}


// this function prints the expected output
void print_output(int res, int num) {

	switch(res) {
		case 0: printf("%d is not a perfect number.\n", num); break;
		case 1: printf("%d is a perfect number.\n", num);
	}
}


