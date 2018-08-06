/* 
 *  CS1010 AY2016/17 Semester 1 Lab2 Ex1
 *  candles.c
 *  Description:  finds out how many candles can be burnt in total 
 by prompting the user to enter  two positive integers n and k 
 where  n is total number of candles and k is number of residuals to make new candle.
 *  Name: Deepak Buddha
 *  Discussion Group: C02
 */ 

#include<stdio.h>

int count_candles(int, int);

int main(void) {

	int n,     // total number of candles
		k,     // number of residuals to make new candle
		total; // total number of candles burnt

	printf("Enter number of candles and \nnumber of residuals to make a new candle: ");
	scanf("%d %d", &n, &k);

	total = count_candles(n, k);

	printf("Total candles burnt = %d\n", total);

	return 0;
}

// this function calculates number of candles burned in total , precondition is that k>1
int count_candles(int n, int k) {

	int res,      // total number of candles burned(result)
		c_burned = 0; // is number of candles burned as a result of residual wax plus original candles burned

	while (n >= k) {

		c_burned  = c_burned  + ((n / k) * k);  // c_burned becomes candles burned is total number of candles formed from residual wax multiplied by  the number of candles in the original set.
		n = (n / k) + (n % k);          // n becomes number of new candles and additionally un burned remaining candles.
	}

	res = c_burned + n;

	return res;
}
