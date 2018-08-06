/* cs1010 16/17 sem1 
 ** magicNumber.c
 ** this program reads two positive integers with at most 5 digits, adds up the digit from right in pos 1,3,5 for each . the right most digit of the sum is printed
 ** Deepak Buddha
 ** group31
 */

#include<stdio.h>

int get_magic(int);

int main(void) {

	int num1,
		num2,
		magic1,
		magic2;

	printf("Enter 1st value: ");
	scanf("%d", &num1);

	magic1 = get_magic(num1);

	printf("Magic number = %d\n", magic1);

	printf("Enter 2nd value: ");
	scanf("%d", &num2);

	magic2 = get_magic(num2);

	printf("Magic number = %d\n", magic2);

	return 0;
}

int get_magic(int num) {

	int digi1,
		digi3,
		digi5,
		temp1,
		temp2,
		res;

	digi1 = num / 10000 ;
	digi5 = num % 10;
	temp1 = num % 1000;
	digi3 = temp1 / 100;

	temp2 = digi1 + digi3 + digi5;

	res = temp2 % 10;

	return res;

}



