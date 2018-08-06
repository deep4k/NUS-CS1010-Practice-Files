/**
 * CS1010 AY2016/7 Semester 1 Lab4 Ex1
 * Program: square.c

 * Description: Given the size of a square and the values in
 * in the square, this program determines whether 
 * the given square is a semi-magic square.

 * Name: Deepak Buddha
 * Group: SG31/C10
 */

#include <stdio.h>
#define MAX 9

int scanSquare(int [][MAX]); 
int isSemiMagic(int [][MAX], int);

int main(void) {

	int size; // the size of square array 
	int arr[MAX][MAX]; // square array with max dimensions of 9x9

	size = scanSquare(arr);

	if(isSemiMagic(arr,size)) {  // if answer is 1(true) , then array is a semi-magic square
		                        // if answer is 0(false),  then array is not semi magic square
		printf("It is a semi-magic square.\n");  
	}
	else {
		printf("It is not a semi-magic square.\n");
	}

	return 0;
}

//reads data into square array and returns size of the square
//Precond: Min size = 1, Max size = 9
int scanSquare(int arr[][MAX]) {

	int size; // required size of array
	// array is square (n x n)
	int i,j;

	printf("Enter size of square: ");
	scanf("%d", &size);

	printf("Enter values in the square: \n");
	for(i=0;i<size;i++) {
		for(j=0;j<size;j++) {
			scanf("%d", &arr[i][j]); 
		}
	}

	return size;
}

// checks whether the square array is semi-magic square or not
// semi-magic square is when 
// A) all row sums and column sums are same
// B) and includes all integers from 1 to the square of size
// it returns 1 if array is semi-magic
// else it returns 0

// Precond: at least 1 row and at most 9 rows in array
int isSemiMagic(int arr[][MAX], int size) {

	int i,j;
	int k=0;
	int sumRow=0; // sum of each row in array
	int sumCol=0; // sum of each column in array
	int answer;
	int limit = size*size; // limit for integers up to size squared

	// Loop to check for Condition A	

	while((sumRow==sumCol) && (k<size)) {
		for(i=0;i<size;i++)
			sumRow += arr[k][i];

		for(j=0;j<size;j++)
			sumCol += arr[j][k];

		if(sumRow != sumCol)
			return 0;
		k++;
	}

	// Loop to check for Condition B

	for(k=1;k<=limit;k++) {
		answer=0;
		for(i=0;i<size;i++) {
			for(j=0;j<size;j++) {
				if(arr[i][j] == k) {
					answer =1;
				}
			}
		}
		if(answer==0) {
			return 0;
		}
	}	
	return 1;
}









