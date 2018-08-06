// primeTest.c
// To check if a number is prime.
#include <stdio.h>
#include <math.h>

int is_prime(int);

int main(void) {    
	int value;

	printf("Enter a positive integer: ");
	scanf("%d", &value);

	if (is_prime(value) == 1) 
		printf("%d is a prime.\n", value);
	else
		printf("%d is not a prime.\n", value);

	return 0;
}

// Write a description for this function,
// and fill in the precondition below.
// Precond: n > 1
int is_prime(int n) {

	int res = 1;
	int i;
	double sr = sqrt(n);
	int limit = ceil(sr);

	for (i = 2; i <= limit; i++) {

		if((n%i) == 0) 
			res = 0;
	}

	if(n == 1) {
		res = 0;
	}

	if(n == 2) {
		res = 1;
	}

	return res;
}





