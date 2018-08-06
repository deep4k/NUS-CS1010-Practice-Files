// multiples5or7.c 
// Reads a positive integer num and count the number
// of multiples of 5 or 7 in the range [1, num].

#include <stdio.h>

int count_multiples(int);
void print_output(int, int);

int main(void) {
	int num;
	int answer;

	printf("Enter positive integer: ");
	scanf("%d", &num);

	answer = count_multiples(num);
	print_output(num, answer);

	return 0;
}

// Precond: value > 0
int count_multiples(int value) {
	int res;
	int i;

	for(i=1;i<=value;i++) {
		if(!(i%5) || !(i%7)) {
			res++;
		}
	}

	return res;
}

//a function that counts the number of multiples and prints 
//relevant outcome.
void print_output(int num, int res) {

	switch(res) {
		case 0: printf("There are no multiples of 5 or 7 in [1,%d].\n", num); break;
		case 1: printf("There is 1 multiple of 5 or 7 in [1,%d].\n", num); break;
		default: printf("There are %d multiples of 5 or 7 in [1,%d].\n", res, num);
	}
}
