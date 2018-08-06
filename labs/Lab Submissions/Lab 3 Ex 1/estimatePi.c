/**
 * CS1010 AY 2016/7 Semester 1 Lab3 Ex1
 * Name: estimatePi.c
 * Description :This program reads a list of n distinct integers and
 * computes an estimate value for pi  
 * This program uses an external GCD function (provided in gcd.o).
 * Name: Deepak Buddha
 * Discussion Group: C02
 */ 

#include <stdio.h>
#include "gcd.h"
#include <math.h>

double pi(int[], int);

int main(void) {

	int size;
	int arr[50]; // an array storing random numbers of up to a max of 50

	int i; // i is a variable used as counter

	scanf("%d", &size);        
	// for checking pursposes
	// printf("size = %d\n", size);

	for (i=0; i<size; i++) {	   // to scan and read the input numbers into the array	
		scanf("%d", &arr[i]);
	}

	// for checking purposes
	// int c;
	// for (c=0;c<size;c++){
	//	printf("%d\n", arr[c]);
	// }

	printf("Estimated pi = %.4f\n", pi(arr,size));

	return 0;
}

// Function description: This function takes in an integer array that contains
// the values,number of values, size in that array. The function
// returns the estimated value of pi.

double pi(int arr[], int size) {

	double result;

	int i,j;                 // i,j  are variables used as counters
	int num_cf;              // the variable used for number of common factors among pair of numbers

	int common_factor;       // the variable used for the common factor between 2 numbers
	int total_pairs;         // the variable used total pairs formed

	num_cf = 0;
	total_pairs=0;

	for(i=0; i<size-1; i++) {
		for(j=i+1; j<size; j++) {
			common_factor = gcd(arr[i], arr[j]);
			if (common_factor == 1) {
				num_cf++; }
			total_pairs++;
		}
	}
   // for checking purpose
   //	 printf("%d:count=%d, total = %d\n", i, num_cf, total_pairs);


	result = sqrt(((6.0*total_pairs)/num_cf) );  // remember 6.0 and not 6 to have non-integer divide

	return result;
}
