/**
 * CS1010 AY2016/7 Semester 1 Lab4 Ex1
 * square.c
 * Author: Jin
 * Given the size of a square and the values in
 * in the square, this program determines whether 
 * the given square is a semi-magic square.
 * Clement Tan
 * C7A
 */

#include <stdio.h>
#define MAXSIZE 9

int scanSquare(int [][MAXSIZE]); // Incomplete
int isSemiMagic(int [][MAXSIZE], int);

int main(void) { 	// Incomplete
	// Use the following printf statements 
	// for printing the output.
	int arr[MAXSIZE][MAXSIZE], size;
	size = scanSquare(arr);
	if(isSemiMagic(arr, size)){
		printf("It is a semi-magic square.\n");  
	}
	else{
		printf("It is not a semi-magic square.\n");
	}
	return 0;
}
//read data into the array and returns the size of the square
int scanSquare(int arr[][MAXSIZE]) { // Incomplete
	// Use the following printf statements 
	// for printing the prompt messages.
	int size, i = 0, j;
	printf("Enter size of square: ");
	scanf("%d", &size);
	printf("Enter values in the square: \n");
	for(; i < size; i++){
		for(j = 0; j < size; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	return size;
}
//check if the square is a semi-magic square
int isSemiMagic(int arr[][MAXSIZE], int size){
	int i = 0, j, k, count = 0, num[9] = {1,2,3,4,5,6,7,8,9}, sums[9] = {0};
	for(; i < size; i++){
		for(j = 0; j < size; j++){
			for(k = 0; k < 9; k++){
				if(num[k] == arr[i][j]){
					count += 1;
					num[k] = 0;
					break;
				}
			}

		}
	}
	if(count < 9){
		return 0;
	}
	for(i = 0;i < size; i++){
		for(j = 0; j < size; j++){
			sums[i] += arr[j][i];
		}
		if(i > 0 && sums[i - 1] != sums[i]){
			return 0;
		}
	}
	return 1;
}
