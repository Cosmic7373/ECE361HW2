// Bubble sort in C 
// https://www.tutorialspoint.com/data_structures_algorithms/bubble_sort_program_in_c.htm


#include "bubblesort.h"

void display(int arr[], int size) {
	int i;

	printf("[");

	// navigate through all items 
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	printf("]\n");
}

int bubbleSort(int arr[], int size, int* ncompares_ptr, int* nswaps_ptr) {
	int temp;
	int i, j;

	bool swapped = false;

	// loop through all numbers 
	for (i = 0; i < size - 1; i++) {
		swapped = false;

		// loop through numbers falling ahead 
		for (j = 0; j < size - 1 - i; j++) {
#ifdef BS_VERBOSE
			printf("     Items compared: [ %d, %d ] ", arr[j], arr[j + 1]);
#endif
			*ncompares_ptr = *ncompares_ptr + 1;

			//	check if next number is lesser than current no
			//	swap the numbers. 
			//	(Bubble up the highest number)

			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				swapped = true;
#ifdef BS_VERBOSE
				printf(" => swapped [%d, %d]\n", arr[j], arr[j + 1]);
#endif
				*nswaps_ptr = *nswaps_ptr + 1;
			}
			else {
#ifdef BS_VERBOSE
				printf(" => not swapped\n");
#endif
			}

		}

		//	if no number was swapped that means 
		//	array is sorted now, break the loop. 
		if (!swapped) {
			break;
		}

#ifdef BS_VERBOSE
		printf("Iteration %d#: ", (i + 1));
		display(arr, size);
#endif
	}

	return *ncompares_ptr + *nswaps_ptr;
}