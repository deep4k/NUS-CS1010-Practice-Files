/**
 * CS1010 AY2016/7 Semester 1 Lab5 Ex2
 * elevator.c
 * takes in an integer i, which represents number of elevators to be simulated and i strings of all digits
 * which represent sequence of floors. The program then simulates the running of the elavators and prints
 * the required outputs in the end.
 * Name: Deepak Buddha
 * Group : SG31/C02
 */

#include <stdio.h>
#include <string.h>
#define CAPACITY 15
#define MAX_LEN 21
#define MAX_ELEVATORS 5

typedef struct {
	int floor;
	int usage;
	int passengers;
} elevator_t;

void setupElevators(elevator_t [], int);
void readSequences(char [][MAX_LEN], int);
void runElevators(elevator_t [], char [][MAX_LEN], int);
void goToFloor(elevator_t *, int);
void printElevators(elevator_t [], int size);
int mostUsedElevator(elevator_t [], int);

// This function is given. You are NOT to modify it.
int main(void){
	int size;
	elevator_t elevators[MAX_ELEVATORS];
	char sequences[MAX_ELEVATORS][MAX_LEN];

	printf("Enter number of elevators: ");
	scanf("%d", &size);

	setupElevators(elevators, size);
	readSequences(sequences, size);

	runElevators(elevators, sequences, size);

	printElevators(elevators, size);
	printf("Most used elevator: %d\n", mostUsedElevator(elevators, size));

	return 0;
}

//this function sets each elavator simulator size chosen with a floor of 1 
//usage of 0 and passengers of 0.
void setupElevators(elevator_t elevators[], int size){
	int i;

	for (i=0; i<size; i++){
		elevators[i].floor = 1;
		elevators[i].usage = 0;
		elevators[i].passengers = 0;
	}
}	

// Read in the sequences of floors the elevators go to.
// This function is given. You are NOT to modify it.
void readSequences(char sequences[][MAX_LEN], int size){
	int i;

	for (i = 0; i<size; i++){
		printf("Enter sequence for elevator %d: ", i+1);
		scanf("%s", sequences[i]);
	}
}

// Runs the elevator simulator with the given sequences for each elevator chosen
// and changes floors accordingly;
// calls goToFloor function to update elevator while changing floors
// Precond: There must be at least 1 floor to number to at most 20 floor numbers in a sequence
void runElevators(elevator_t elevators[], char sequences[][MAX_LEN], int size){
	int i,j,len,floor;

	for (i=0; i<size; i++){
		len = strlen(sequences[i]);
		for (j=0; j<len; j++){ 
			floor = sequences[i][j] - '0';
			//printf("Floor to go is = %d.\n", floor);
			goToFloor(&elevators[i], floor);
		}
	}

}

// Changes floors of the elevator according to the sequence entered
// and updates passengers and usage of the elevator
// Precond : Floors range from 1 to 9
void goToFloor(elevator_t *elevator, int floor){

	int count_in,count_out;

	// If elevator is going up
	if (elevator->floor < floor){
		count_in = elevator->passengers + floor;
		if (count_in < 15){
			elevator->passengers = count_in;
		}
		else {
			elevator->passengers = 15;
		}

	}
	// If elevator is going down
	if (elevator->floor > floor){
		if(elevator->passengers < floor) {
			elevator->usage += elevator->passengers;
			elevator->passengers = 0;
		}
		else {
			count_out = elevator->passengers - floor;
			elevator->usage += floor;
			elevator->passengers = count_out;

		}
	}

	//for checking purposes
	//printf("This floor is %d.\n", floor);
	//printf("The passengers in this floor are %d.\n", elevator->passengers); 
	//printf("The usage for this floor is %d.\n", elevator->usage);

	elevator->floor = floor;
}


// Outputs the floor,passengers and usage of each elevator
// after the simulation is completed
// Precond: There is at least 1 elevator and at most 5
void printElevators(elevator_t elevators[], int size){
	int i,count;

	for (i=0; i<size; i++) {

		count = i+1;
		printf("Elevator %d:\n", count); 
		printf("Floor: %d\n", elevators[i].floor);
		printf("Number of passengers: %d\n", elevators[i].passengers);
		printf("Usage: %d\n", elevators[i].usage);
	}
}

// 1.Returns the most used elevator among all the elevators used in the simulator
// 2.if same usage, it returns the elevator with more passengers
// 3.if passengers are also same, it returns the smaller number elevator
// Precond: There is at least 1 elevator and at most 5.
int mostUsedElevator(elevator_t elevators[], int size){
	int i,answer=1;
	int max_usage = elevators[0].usage;
	int max_passengers = elevators[0].passengers;

	for (i=0; i<size; i++){                       // To satisfy condition 1(In the function description above)
		if (elevators[i].usage > max_usage) {
			max_usage = elevators[i].usage;
			max_passengers = elevators[i].passengers;
			answer = i+1;
		}
		if (elevators[i].usage == max_usage){       // To satisfy conditon 2
			if (elevators[i].passengers > max_passengers){ // to satisfy condition 3
				max_usage = elevators[i].usage;
				max_passengers = elevators[i].passengers;
				answer = i+1;
			}
		}
	}


	return answer;
}

