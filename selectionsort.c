// Bliss

#include "selectionsort.h"

int selectionSort(int arr[], int size, int* ncompares_ptr, int* nswaps_ptr) {
	int min = 0; 
	int loc = 0;
	int i = 0;
	int j = 0;
	int temp = 0;

	while (i < size) {
		j = i;
		min = arr[j];
		loc = j;

		while (j < size) {
			*ncompares_ptr = *ncompares_ptr + 1;
#ifdef SS_VERBOSE
			printf("     Comparing min value %d with array value %d \n", min, arr[j]);
#endif

			if (arr[j] < min) {

				min = arr[j];
				loc = j;
#ifdef SS_VERBOSE
				printf("     New min value of %d \n", min);
#endif
			}

			j++;
		}
#ifdef SS_VERBOSE
		printf("Placing min value %d at location %d \n", min, i);

		printf("Iteration %d#: ", (i + 1));
		display(arr, size);
#endif

		*nswaps_ptr = *nswaps_ptr + 1;
		temp = arr[i];
		arr[i] = min;
		arr[loc] = temp;
		i++;
	}

	return *ncompares_ptr + *nswaps_ptr;
}