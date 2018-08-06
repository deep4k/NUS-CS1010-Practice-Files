/**
 * rabbit.c 
 * A rabbit can jump at most 50 centimetres. It needs to cross a
 * river, with rocks positioned in a straight line in the river.
 * The program computes the minimum number of jumps for the rabbit
 * to cross to the other side of the river.
 */

#include <stdio.h>
#include <math.h>
#define MAX 20

int countJumps(int [], int);
void scanArray(int [], int);
void printArray(int [], int);

int main(void) {
	int num_rocks;            // including opposite bank
	int arr[MAX] = {0};

	printf("Enter number of rocks: ");
	scanf("%d", &num_rocks);

	scanArray(arr, num_rocks);
	// for checking purpose	printArray(arr, num_rocks);

	printf("%d\n",countJumps(arr, num_rocks));

	return 0;
}

void scanArray(int arr[], int size) {
	int i;

	for(i=0;i<size;i++) {
		scanf("%d", &arr[i]);
	}
}

// void printArray(int arr[], int size) {
//	int i;
//
//	for(i=0;i<size;i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}



// Counts the minimum number of jumps the rabbit needs
// to take to get to the other side of the river.
// Precond: size > 0
// -1 if impossible
int countJumps(int rocks[], int size) {

	int i=0;
	int j=0;
	int jump=0;
	int pos=0; // starting position of rabbit before crossing

	while(50>= rocks[i]){
		i++;
	}

	i--;    // locate the first rock in the array

	jump = 1;  // start the first jump

	pos=i;   // our 1st position in on the 1st rock


	while(pos<size) {  // as long as it is not across the river

		j=pos; // counter for the position at which rock the rabbit is

		while((j<=size-1) && ((rocks[pos] + 50) >= rocks[j+1])) { 
			// check if every rock ahead is +50 or not
			j++;   
		}      // keep checking until maximum then find that rock with j

		if(j == pos) {
			return -1;   // if no change has been made means no rock in range hence fail
		}

		pos = j;  // set new position to the maximum rock it can go and continue loop
		jump++;  // add one jump for each change in position 
	}

	return jump;
}

