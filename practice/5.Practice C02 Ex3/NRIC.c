/* NRIC.c
 ** reads 7 digit positive integer representing an NRIC number and generates it check code
 ** Deepak Buddha
 ** group 31 
 */

#include<stdio.h>

char generateCode(int);

int main(void) {

	int nric;

	char code;

	printf("Enter 7-digit NRIC number: ");
	scanf("%d", &nric);

	code = generateCode(nric);

	printf("Check code is %c\n", code);

	return 0;
}

char generateCode(int nric) {

	int digi1,
		digi2,
		digi3,
		digi4,
		digi5,
		digi6,
		digi7,
		temp1,
		temp2;

	char code;

	digi1 = nric / 1000000 ;
	digi7 = nric % 10;
	digi6 = (nric % 100) / 10 ;
	digi5 = (nric % 1000) / 100;
	digi4 = (nric % 10000) / 1000;
	digi3 = (nric % 100000) / 10000;
	digi2 = (nric % 1000000) / 100000;

	temp1 = (2 * digi1) + (7 * digi2) + (6 * digi3) + (5 * digi4) + (4 * digi5) + (3 * digi6) + (2 * digi7) ;

	temp2 = 11 - (temp1 % 11) ;

	switch (temp2) {

		case 1:
			code = 'A';
			break;

		case 2:
			code = 'B';
			break;

		case 3:
			code = 'C';
			break;

		case 4:
			code = 'D';
			break;

		case 5:
			code = 'E';
			break;

		case 6:
			code = 'F';
			break;

		case 7:
			code = 'G';
			break;

		case 8:
			code = 'H';
			break;

		case 9:
			code = 'I';
			break;

		case 10:
			code = 'Z';
			break;

		case 11:
			code = 'J';
			break;

		default:
			printf("switch is wrong.");
			break;
	}

	return code;
}



