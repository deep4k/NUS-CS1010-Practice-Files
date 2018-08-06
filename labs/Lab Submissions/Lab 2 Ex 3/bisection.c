/**
 * CS1010 AY2016/17 Semester 1 Lab2 Ex3
 * bisection.c
 * Description: Compute the root of a function by prompting the user to enter
 integer coefficients of a third degree polynomial and its end points.
 * Name: Deepak Buddha
 * Discussion Group: C02
 */

#include<stdio.h>
#include<math.h>
#define THRESHOLD 0.0001

double polynomial(double, int, int, int, int);

int main(void) {

	int    c3, c2, c1, c0; // coefficients of polynomial
	double a, b,           // end points
		   pA, pB;         // function values at end points
	double m, pM;          // midpoint and function value at midpoint

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);

	printf("Enter endpoints a and b: ");
	scanf("%lf %lf", &a, &b);

	do {
		m = (a + b)*0.5;
		pM = polynomial(m, c3, c2, c1, c0);

		pA = polynomial(a, c3, c2, c1, c0);
		pB = polynomial(b, c3, c2, c1, c0);

		if((fabs(a-b)<THRESHOLD)||(pM == 0)) {
			break;
		}

		if(pB>0){
			if(pM>0) {
				b = m;
			}
			else {
				a = m;
			}
		}

		else{
			if(pM>0) {
				a = m;
			}
			else {
				b = m;
			}
		}

	}while(1);

	printf("root = %.6f\n", m);
	printf("p(root) = %.6f\n", pM);

	return 0;
}

// this function  calculates the polynomial function value, where p is the point at which the function value is being calculated
double polynomial(double p, int c3, int c2, int c1, int c0) {

	double res; // res is the result which is the polynomial function value

	res = (c3*(pow(p, 3))) + (c2*(pow(p, 2))) + (c1*p) + c0;

	return res;
}






