/**
 * CS1010 AY2016/7 Semester 1 Lab4 Ex2
 * Program: sequence.c
 *
 * Description:  Given a 12x12 integer array, fill it with integers(1-9), and
 * find the longest sequence of a digit that appears in 
 * the array horizontally, vertically or diagonally.
 * 
 * Name: Deepak Buddha
 * Group: SG31/C10
 */

#include <stdio.h>
#define DIM 12

int scanBoard(int [][DIM]);
int search(int [][DIM], int*, int*, int);


int main(void) {
	int board[DIM][DIM] = { {0} };
	int search_digit;     
	int length;           // length of the longest sequence of search digit
	int bestRow, bestCol; // where the longest sequence of search digit starts in the board

	search_digit = scanBoard(board);

	length = search(board, &bestRow, &bestCol, search_digit);


	if (length > 0) {
		printf("Length of longest sequence = %d\n", length); 
		printf("Start at (%d,%d)\n", bestRow, bestCol);      
	}
	else
		printf("No such sequence.\n");

	return 0;
}

// Reads data into the 12 x 12 array and scans 
// for a single integer and returns this 
// as digit
// Min digit = 1, Max digit = 9
int scanBoard(int arr[][DIM]) {

	int i,j;
	int digit;

	for(i=0;i<DIM;i++)
		for(j=0;j<DIM;j++)
			scanf("%d", &arr[i][j]);
	

	scanf("%d", &digit);
	return digit;

}


// Takes in 
// 1)12x12 array board
// 2)2  pointers to locations on the board and
// 3)search digit
// Then searches array for horizaontal,vertical or diagonal
// sequence of search digit.
// Then returns max length of the sequence(if it exisits)

int search(int arr[][DIM], int*row_point, int*col_point, int digit) {

	int i,j,k,l,m;
	int max = 0;

	for(i=0;i<DIM;i++) {
		for(j=0;j<DIM;j++){
			for(k=0;k<DIM-i;k++) {
				if(arr[i][j+k] != digit) {
					break;
				}
				else if (k+1>max) {
					max = k+1;
					*row_point = i;
					*col_point = j;
				}
			}

			for(l=0;l<DIM-i;l++) {
				if(arr[i+l][j] != digit) {
					break;
				}
				else if(l+1>max) {
					max = l+1;
					*row_point = i;
					*col_point = j;
				}
			}
			for(m=0;m<DIM-i;m++){
				if(arr[i+m][j+m] != digit) {
					break;
				}
				else if(m+1>max) {
					max = m+1;
					*row_point = i;
					*col_point = j;
				}
			}
		}
	}

	// for checking purposes
	// printf("Value of I is %d, J is %d, Max = %d.\n", i,j,max);
	return max;
}


