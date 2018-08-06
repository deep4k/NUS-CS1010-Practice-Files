// countNumbers.c
// To count the number of integers in the range [limit1, limit2]
// which are not divisible by divisor1 and divisor2
#include <stdio.h>
#include <math.h>

int count_numbers(int, int, int, int);

int main(void) {    
	int divisor1, divisor2, limit1, limit2;
	int answer;

	do {

		printf("Enter 2 divisors: ");
		scanf("%d %d", &divisor1, &divisor2);

	}while((divisor1 == divisor2) || (divisor1<=0) || (divisor2<=0));

	do {

		printf("Enter lower and upper limits: ");
		scanf("%d %d", &limit1, &limit2);

	}while((limit1 >  limit2) || (limit1==limit2) || (limit1<=0) || (limit2<=0));

	answer = count_numbers(divisor1, divisor2, limit1, limit2);


	printf("Answer = %d\n", answer);

	return 0;
}
//this function calculates the numbers from limit 1 to limit2
//not divisible by divisor 1 and divisor 2
int count_numbers(int x1, int x2, int y1, int y2) {

	int i;
	int answer;
	double j;
	double k;

	for(i=y1;i<=y2;i++) {
		
		j = i/(double)x1;
		k = i/(double)x2;

		if((fmod(j,1.0) != 0)  && (fmod(k,1.0) != 0)) {
			answer++;
		}
	}
	return answer;
}



