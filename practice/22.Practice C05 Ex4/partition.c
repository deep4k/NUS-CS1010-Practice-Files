// partition.c
#include <stdio.h>
#define MAX 20

void scanArray(int [], int);
void printArray(int [], int);
void partition(int [], int, int);

int main(void) {
	int size;
	int pivot;
	int arr[MAX] = {0};


	printf("Enter the number of elements: ");
	scanf("%d", &size);

	printf("Enter %d integers: ", size);
	scanArray(arr, size);

	printf("Enter pivot: ");
	scanf("%d", &pivot);

	partition(arr,size,pivot);
	printArray(arr,size);

	return 0;
}

// read input into array
void scanArray(int arr[], int size) {
	int i;

	for(i=0; i<size; i++) 
		scanf("%d", &arr[i]);
}

//rearranges array based on pivot
void partition(int arr[], int size, int pivot) {

	int i =0;
	int temp;
	int j = 0;

	for(i=0;i<size; i++) {

		if(arr[i]<pivot) {

			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp; 	
			j++;
		}
	}

}


// Print array arr
void printArray(int arr[], int size) {
	int i;

	for (i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

