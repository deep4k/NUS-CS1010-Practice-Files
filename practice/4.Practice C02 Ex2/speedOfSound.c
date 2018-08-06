/* cs1010 16/17 sem1 
 ** speedOfSound.c
 ** calculates speed of sound in feet/sec
 ** s = 1086 * sqrt ( (5T+297) / 247 ) where speed of sound is s in air , temperature is T (in fahrenheit)
 ** Deepak Buddha
 ** group31
 */

#include<stdio.h>
#include<math.h>

float speed_of_sound(float);

int main(void) {

	float temp,
	      speed;

	printf("Temperature in degree Fahrenheit: ");
	scanf("%f", &temp);

    speed = speed_of_sound(temp);
    
	printf("Speed of sound in air of %.2f degree = %.2f ft/sec\n", temp, speed);

	return 0;
}

float speed_of_sound(float temperature) {

	float res;

	res = 1086 * sqrt((5*temperature + 297) / 247 ) ;

	return res;
}
