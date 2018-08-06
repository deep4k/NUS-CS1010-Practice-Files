/**
 * CS1010 AY2016/7 Semester 1 Lab5 Ex1
 * prerequisites.c
 * Reads a positive integer indicating number of modules
 * and a list of module codes. It also reads a particular module code
 * and if that code exists, it displays all the prerequisites of that 
 * module in the same order as the entry of module codes.
 * Deepak Buddha
 * SG31/C02
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOD  10
#define MAX_LEN  7

int scanModules(char [][MAX_LEN]);
int computePrereq(char [][MAX_LEN], int, char [], char [][MAX_LEN]);
void printPrereq(char [][MAX_LEN], int, char []);

int main(void) {
	int numModules, numPrereq;
	char codes[MAX_MOD][MAX_LEN],         // the list of modules codes
		 target[MAX_LEN],                 // the target module
		 prerequisites[MAX_MOD][MAX_LEN]; // prerequisites of the target module

	numModules = scanModules(codes);

	printf("Choose a module: ");
	scanf("%s", target);

	numPrereq = computePrereq(codes, numModules, target, prerequisites);

	printPrereq(prerequisites, numPrereq, target);

	return 0;
}
// returns the number of modules read
// Precond: MAX 6 characters in a module and only 10 modules maximum.
int scanModules(char codes[][MAX_LEN]) {

	int num,i;

	printf("Enter number of modules: ");
	scanf("%d", &num);
	printf("Enter %d module%s:\n", num, (num>1)?"s":"");

	for(i=0;i<num;i++) {
		scanf("%s", codes[i]);
	}

	//	for(i=0;i<num;i++) {
	//		puts(codes[i]);
	//	}


	return num;
}

// returns number of prerequisites for the target module. If target module not included, returns -1.
// Precond: the first two characters are always capital alphabetical letters followed by 4 digits.
// Precond : MAX 6 characters in a module and only 10 modules maximum.
int computePrereq(char codes[][MAX_LEN], int num, char target[], char prereq[][MAX_LEN]) {

	int i,j;
	int k=0;
	int otherdigit;   // to act as a conditional variable for comment 3. below
	char *p;
	int outcome = -1;
	int numPrereq;

	for(i=0;i<num;i++) {
		p = strstr(codes[i],target);
		if(p != '\0') {
			outcome = 0;
		}
	}

	if(outcome == -1) {    // -1 Target module not found in module codes
		return -1;
	}

	for(i=0;i<num;i++) {
		otherdigit =0;
		if((target[0] == codes[i][0]) && (target[1] == codes[i][1])) {  // 1.if the 1st 2 letters are the same
			if(codes[i][2] < target[2]) {                               // 2.if the first digit is smaller 
				for(j=3;j<=5;j++) {                                     // 3.if other digits in same place are smaller
					if(codes[i][j] > target[j]) {
						otherdigit = 1;
					}
				}
				if(otherdigit == 0) {
					strcpy(prereq[k], codes[i]);
					outcome = 1;
					k++;
					//puts(prereq[i]);  for checking purposes
					//printf("Value of i = %d.\n",i);
				}
			}
		}
	}

	if(outcome == 0) {   // 0 No prerequisite modules
		return 0;
	}

	if(outcome == 1) {          // 1, returns number of prequisite modules
		for(i=0;i<num;i++) {
			if(!isalpha(prereq[i][0])) {
				break;
			}
		}
		numPrereq = i;
		return numPrereq;
	}

	return 0; // default case
}


// Print the prerequisites
void printPrereq(char prerequisites[][MAX_LEN], int numPrereq, char target[]) {
	int i;

	if (numPrereq == -1) {
		printf("No such module %s\n", target);
	}
	else if (numPrereq == 0) {
		printf("No prerequisites for %s\n", target);
	}
	else {
		printf("Prerequisites for %s:", target);
		for (i = 0; i < numPrereq; i++){
			printf(" %s", prerequisites[i]);
		}
		printf("\n");
	}
}

