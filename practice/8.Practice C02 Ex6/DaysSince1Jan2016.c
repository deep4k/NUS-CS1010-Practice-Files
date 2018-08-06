// DaysSince1Jan2016.c
// This program reads the day and month of 2016 and computes
// the number of days since 1st January 2016.
#include <stdio.h>

int computeDays(int, int);

int main(void) {    
	int day, month;

	printf("Enter day and month: ");
	scanf("%d %d", &day, &month);

	printf("Day %d of month %d is the %dth day of 2016.\n", 
			day, month, computeDays(day, month));

	return 0;
}

// This function computes the number of days that have elapsed 
// for the given day and month since 1st January 2016.
int computeDays(int day, int mth) {

	int days;

	mth = mth - 1;

	switch (mth) {
		case 0: days = 0; break;
		case 1: days = 31+1; break;
		case 2: days = 59+1; break;
		case 3: days = 90+1; break;
		case 4: days = 120+1; break;
		case 5: days = 151+1; break;
		case 6: days = 181+1; break;
		case 7: days = 212+1; break;
		case 8: days = 243+1; break;
		case 9: days = 273+1; break;
		case 10: days = 304+1; break;
		case 11: days = 334+1; break;
		default: printf("Incorrect input.\n");
	}

	days += day;

	return days;
}





