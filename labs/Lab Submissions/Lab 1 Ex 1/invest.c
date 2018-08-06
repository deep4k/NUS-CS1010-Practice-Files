/* invest.c
 ** computes amount of money earned from compound interest after the numYears
 ** investment = ( (principal * (1 -( pow(rate/100, numYears + 1)))) / ( 1 -(rate/100)) )
 ** Deepak Buddha
 ** group31
 */

#include<stdio.h>
#include<math.h>

int main(void) {

	int principal,
		rate,
		numYears;

	float mulah;

	printf("Enter principal amount: ");
	scanf("%d", &principal);

	printf("Enter interest rate   : ");
	scanf("%d", &rate);

	printf("Enter number of years : ");
	scanf("%d", &numYears);

	mulah = ( (principal * (1 -( pow(rate / 100.00, numYears +1)))) / (1 -(rate/100.00)) ); 

	printf("Amount = $%.2f\n", mulah);

	return 0;
}




