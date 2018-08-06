/**
 * CS1010 AY2016/7 Semester 1 Lab3 Ex2
 * Program: subsequence.c
 * Descrption: This program reads in a list of integers and find the
 * k-interval subsequence with the largest sum.
 * Name: Deepak Buddha
 * Discussion group: C02
 */

#include <stdio.h>

int scan_list(int []);
void sum_subsequence(int [], int, int []);

int main(void) {
	int list[10], size; // array and actual number of elements entered
	int answers[3];     // array to store the required answers

	size = scan_list(list); 

	sum_subsequence(list, size, answers);

	printf("Max sum %d of %d-interval subsequence starting at position %d.\n",
			answers[0], answers[1], answers[2]);

	return 0;
}

// Read in elements for the array arr and returns the 
// number of elements read.
// Postcond: i > 0
int scan_list(int arr[]) {
	int num, i;

	printf("Enter number of elements: ");
	scanf("%d", &num);
	printf("Enter %d element%s: ", num, (num>1)?"s":"");
	for (i=0; i<num; i++) {
		scanf("%d", &arr[i]);
	}

	return num;
}

//  This function calculates the maximum sum of a k-interval
//  subsequence among all k-interval subsequences.
//  It then stores the maximum sum, interval k and start position
//  of solution subsequence in ans[] array, as shown below;
//  Condition: There must be at least one element and at most 10
//  elements in the list
//   ans[0] = maximum sum of solution subsequence
//   ans[1] = interval k of the solution subsequence
//   ans[2] = start position of the solution subsequence
void sum_subsequence(int arr[], int size, int ans[]) {

	int i,j;   // variables used as counters
	int k;     // the interval of subsequence
	int start; // the start position of subsequence

	int sum;

	ans[0] = 0;  
	ans[1] = 1;  // Intialising the solution
	ans[2] = 0;  

	for(i=0; i<size; i++) {
		ans[0] = ans[0] + arr[i]; // maximum sum for interval k=1
	}

	for(k=2; k<=size; k++) {      // Loop to find the sum of numbers for each k
		for(start=0; start<k; start++) { // Loop to start from each position 
			sum = 0;
			for(j=start; j<size; j=j+k) { // Loop to find sum of numbers in same iteration
				sum = sum + arr[j];
			}
			if (sum > ans[0]) {  // conditional statement to only choose the max sum per iteration
				ans[0] = sum;
				ans[1] = k;
				ans[2] = start;
			}
		}
	}
}



