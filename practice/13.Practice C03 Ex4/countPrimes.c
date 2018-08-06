// countPrimes.c
// To count the number of primes in the range [1, limit]
// where limit is entered by user.
#include <stdio.h>
#include <math.h>

int is_prime(int);

int main(void) {    
	int limit;
	int prime;
	int i;

	printf("Enter limit: ");
	scanf("%d", &limit);

	for(i=1;i<=limit;i++) {

		if(is_prime(i)==1) {
			prime++;
		}
	}
	printf("Number of primes (1-%d): %d\n",limit,prime);

	return 0;
}

// this function checks if a given number 
// is a prime
// precond: n>1

int is_prime(int n) {

	int res = 1;
	int i;
	double limit;

	limit = ceil(sqrt(n));

	for(i=2;i<=limit;i++) {
		if((n%i) == 0)
			res = 0;
	}
	if(n==1) {
		res=0;
	}
	if(n==2) {
		res=1;
	}
	return res;
}

