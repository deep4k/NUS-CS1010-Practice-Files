/* cs1010 16/17 sem1 
 * lab0 exercise1  
 * box_volume.c
 * reads three positive integers representing the length, width and height of a box and computes the volume of that box.
 * Deepak Buddha
 * group31
 */

#include <stdio.h>

int main(void) {

	int length, width, height, volume;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width : ");
	scanf("%d", &width);

	printf("Enter height: ");
	scanf("%d", &height);

	volume = length * width * height;

	printf("Volume = %d\n", volume);

	return 0;
} 
