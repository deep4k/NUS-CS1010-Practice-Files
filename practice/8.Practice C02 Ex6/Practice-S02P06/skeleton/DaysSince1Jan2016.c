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

	return 123;
}

