/* cs1010 16/17 sem1 
 ** freezer.c
 ** this program estimates the temperature in celsius given the time lapse(hours) since a power failure.
 ** T = 4(t*t)/t+2 -20 where T is temperature and t is time in hours 
 ** Deepak Buddha
 ** group31
 */


#include<stdio.h>
#include<math.h>

int main(void) {

	int hours,
		minutes;

	float time,
		  temperature;


	printf("Enter hours and minutes since power failure: ");
	scanf("%d %d", &hours, &minutes);

	time = hours + ((float)minutes/60.0);

	temperature = ( (4 * pow(time, 2)) / (time + 2) ) - 20 ;

	printf("Temperature in freezer = %.2f\n", temperature);

	return 0;
}

