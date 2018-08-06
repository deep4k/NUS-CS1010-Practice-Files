/*  
 * CS1010 AY2016/17 Semester 1 Lab2 Ex2
 * square_free.c
 * Description: reads 4 positive integers in sequence: lower1, upper1, lower2, upper2, and computes 
 *              the number of square-free integers in two ranges[lower1,upper1](both inclusive) and [lower2,upper2](both inclusive)and compares
 *              and reports which range has most square-free integers
 * Name: Deepak Buddha
 * Discussion Group: C02
 */

#include<stdio.h>

int is_square_free(int);
int count_squarefree(int, int);

int main(void) {

	int lower1,
		upper1,
		lower2,
		upper2,
		sf_range1,	// number of square free numbers in range 1 : [lower1,upper1]	
		sf_range2;  // number of square free numbers in range 2 : [lower2,upper2]

	printf("Enter four positive integers: ");
	scanf("%d %d %d %d", &lower1, &upper1, &lower2, &upper2);

	sf_range1 = count_squarefree(lower1, upper1);

	sf_range2 = count_squarefree(lower2, upper2);

	if (sf_range1 > sf_range2) 

		printf("Range [%d, %d] has more square-free numbers: %d\n", lower1, upper1, sf_range1);

	else if (sf_range2 > sf_range1)

		printf("Range [%d, %d] has more square-free numbers: %d\n", lower2, upper2, sf_range2);

	else if (sf_range1 == sf_range2)

		printf("Both ranges have the same number of square-free numbers: %d\n", sf_range1);

	return 0;
}


// this function counts every single squarefree number within range of lower to upper : [lower,upper]
int count_squarefree(int lower, int upper) {

	int i,     // i is the counter
		res=0, // res is number of square free numbers in range
		j;     // j is used as intermediate variable in calculation

	for (i=lower; i<=upper; i++) {

		j = is_square_free(i); 

		if(j == 1) { 

			res++;
		}
	}

	return res;
}


// this function checks for each given number, n , if that number is a square free number or not
int is_square_free(int n) {

	int i=2, // i is the counter
		res; // res is result of if square free or not, 1 is true and 0 is false

	while (n >= (i*i)) {

		if ((n % (i*i)) == 0) {

			return res = 0;
		}
		i++;
	}
	return res = 1;
}





