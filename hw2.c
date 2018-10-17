// Bliss Brass 10-11-18
// ECE 361 HW 2
// Perform Bubble, Insertion and Selection sort then display their efficiency

#include "bubblesort.h"
#include "selectionsort.h"
#include "insertionsort.h"

#define MAX 15

// Original array
//int list[] = { 1,8,4,6,0,3,5,2,7,9 };

int random[] = { 1, 8, 4, 6, 0, 3, 5, 2, 7, 9, 5, 4, 7, 9, 1 };
int ascend[] = { 0, 1, 1, 2, 3, 4, 4, 5, 5, 6, 7, 7, 8, 9, 9 };
int descen[] = { 9, 9, 8, 7, 7, 6, 5, 5, 4, 4, 3, 2, 1, 1, 0 };
int randomSS[] = { 1, 8, 4, 6, 0, 3, 5, 2, 7, 9, 5, 4, 7, 9, 1 };
int ascendSS[] = { 0, 1, 1, 2, 3, 4, 4, 5, 5, 6, 7, 7, 8, 9, 9 };
int descenSS[] = { 9, 9, 8, 7, 7, 6, 5, 5, 4, 4, 3, 2, 1, 1, 0 };
int randomIS[] = { 1, 8, 4, 6, 0, 3, 5, 2, 7, 9, 5, 4, 7, 9, 1 };
int ascendIS[] = { 0, 1, 1, 2, 3, 4, 4, 5, 5, 6, 7, 7, 8, 9, 9 };
int descenIS[] = { 9, 9, 8, 7, 7, 6, 5, 5, 4, 4, 3, 2, 1, 1, 0 };

int main() {
	int ncompares_ptr = 0;
	int nswaps_ptr = 0;
	int stepsRan = 0, stepsAscend = 0, stepsDescen = 0;

	
	// *******************************************************************************************
	// Bubble Sort
	// *******************************************************************************************
	
	// Random array block
	printf("***BubbleSort*** \n\nRandom Input Array: ");
	display(random, MAX);
	
	stepsRan = bubbleSort(random, MAX, &ncompares_ptr, &nswaps_ptr);
	printf("Output Array:       ");
	display(random, MAX);
	printf("\n");

	// Ascending array block
	ncompares_ptr = 0, nswaps_ptr = 0;
	printf("BubblesSort \n\nAscending Input Array: ");
	display(ascend, MAX);

	stepsAscend = bubbleSort(ascend, MAX, &ncompares_ptr, &nswaps_ptr);
	printf("Output Array:          ");
	display(ascend, MAX);
	printf("\n");

	// Descending array block
	ncompares_ptr = 0, nswaps_ptr = 0;
	printf("BubblesSort \n\nDescending Input Array: ");
	display(descen, MAX);

	stepsDescen = bubbleSort(descen, MAX, &ncompares_ptr, &nswaps_ptr);
	printf("Output Array:           ");
	display(descen, MAX);
	printf("\n");

	// *******************************************************************************************
	// Selection Sort
	// *******************************************************************************************

	int stepsRanSS = 0, stepsAscendSS = 0, stepsDescenSS = 0;
	ncompares_ptr = 0, nswaps_ptr = 0;

	// Random array block
	printf("\n***Selection Sort***\n\nRandom Input Array: ");
	display(randomSS, MAX);

	stepsRanSS = selectionSort(randomSS, MAX, &ncompares_ptr, &nswaps_ptr);
	printf("Output Array:       ");
	display(randomSS, MAX);
	printf("\n");

	// Ascending array block
	ncompares_ptr = 0, nswaps_ptr = 0;
	printf("Selection Sort \n\nAscending Input Array: ");
	display(ascendSS, MAX);

	stepsAscendSS = selectionSort(ascendSS, MAX, &ncompares_ptr, &nswaps_ptr);
	printf("Output Array:          ");
	display(ascendSS, MAX);
	printf("\n");

	// Descending array block
	ncompares_ptr = 0, nswaps_ptr = 0;
	printf("Selection Sort \n\nDescending Input Array: ");
	display(descenSS, MAX);

	stepsDescenSS = selectionSort(descenSS, MAX, &ncompares_ptr, &nswaps_ptr);
	printf("Output Array:           ");
	display(descenSS, MAX);
	printf("\n");
	
	// *******************************************************************************************
	// Insertion Sort
	// *******************************************************************************************

	int removal_ptr = 0, insertion_ptr = 0;
	int stepsRanIS = 0, stepsAscendIS = 0, stepsDescenIS = 0;
	ncompares_ptr = 0, nswaps_ptr = 0;
	
	// Random array block
	printf("\n***Insertion Sort*** \n\nRandom Input Array: ");
	display(randomIS, MAX);

	stepsRanIS = insertionSort(randomIS, MAX, &ncompares_ptr, &nswaps_ptr, &removal_ptr, &insertion_ptr);
	printf("Output Array:       ");
	display(randomIS, MAX);
	printf("\n");

	// Ascending array blcok
	ncompares_ptr = 0, nswaps_ptr = 0, removal_ptr = 0, insertion_ptr = 0;
	printf("Insertion Sort \n\nAscending Input Array: ");
	display(ascendIS, MAX);

	stepsAscendIS = insertionSort(ascend, MAX, &ncompares_ptr, &nswaps_ptr, &removal_ptr, &insertion_ptr);
	printf("Output Array:          ");
	display(ascendIS, MAX);
	printf("\n");

	// Descending array block
	ncompares_ptr = 0, nswaps_ptr = 0, removal_ptr = 0, insertion_ptr = 0;
	printf("Insertion Sort \n\nDescending Input Array: ");
	display(descenIS, MAX);

	stepsDescenIS = insertionSort(descenIS, MAX, &ncompares_ptr, &nswaps_ptr, &removal_ptr, &insertion_ptr);
	printf("Output Array:           ");
	display(descenIS, MAX);
	printf("\n");
	
	printf("\nSteps taken per array --> | Bubblesort | Selectionsort | Insertionsort |");
	printf("\nRandomly ordered array:   |     %d    |      %d      |      %d      |", stepsRan, stepsRanSS, stepsRanIS);
	printf("\nAscending ordered array:  |     %d     |      %d      |      %d       |", stepsAscend, stepsAscendSS, stepsAscendIS);
	printf("\nDescending ordered array: |     %d    |      %d      |      %d      |\n", stepsDescen, stepsDescenSS, stepsDescenIS);

	getchar();
}