// Suffix.c
// This program reads a positive integer and 
// prints the value with the correct ordinal suffix.
#include <stdio.h>

void printSuffix(int);

int main(void) {    
	int value;

	printf("Enter value: ");
	scanf("%d", &value);

	printf("%d", value);
	printSuffix(value);

	return 0;
}

// This function prints the corresponding 
// ordinal suffix for value.
void printSuffix(int value) {

	value = value % 100;

	char suffix1, suffix2;

	if ((10 <= value) && (value <= 20)) {

		suffix1 = 't'; 
		suffix2 = 'h';
	}

	else {
		value = value % 10;

		switch (value) {
			case 1: suffix1 = 's'; suffix2 = 't'; break;
			case 2: suffix1 = 'n'; suffix2 = 'd'; break;
			case 3: suffix1 = 'r'; suffix2 = 'd'; break;
			default: suffix1 = 't'; suffix2 = 'h'; break;
		}
	}

	printf("%c%c\n", suffix1, suffix2);
}


