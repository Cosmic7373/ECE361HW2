// Bliss
// Found Insertion sort at https://www.geeksforgeeks.org/insertion-sort/
// It was more efficient than my code so I replaced it.
//Can toggle between the two sort blocks by encapsulating with /**/

#include "insertionsort.h"

int insertionSort(int arr[], int size, int* ncompares_ptr, int* nswaps_ptr, int* removal_ptr, int* insertion_ptr) {
	
	int i = 0, key = 0, j = 0;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;

		*removal_ptr = *removal_ptr + 1;

		// Move elements of arr[0..i-1], that are
		// greater than key, to one position ahead
		// of their current position 
		while (j >= 0 && arr[j] > key)
		{
#ifdef IS_VERBOSE
			printf("     Items compared: [ %d, %d ] \n", arr[j], key);
#endif

			*ncompares_ptr = *ncompares_ptr + 1;

			arr[j + 1] = arr[j];
			j = j - 1;

			*nswaps_ptr = *nswaps_ptr + 1;
		}
		arr[j + 1] = key;

#ifdef IS_VERBOSE
		printf("     Inserting %d at location %d\n", key, j + 1);
		printf("Iteration %d#: ", i);
		display(arr, size);
#endif

		*insertion_ptr = *insertion_ptr + 1;
	}
	
	// My less efficient code
	/*
	int i = 0;
	int j = 0;
	int select = 0;
	int temp = 0;

	while (i < size) {
		j = i;
		select = arr[i];
		*removal_ptr = *removal_ptr + 1;

		while (j >= 0) {
#ifdef IS_VERBOSE
			printf("     Items compared: [ %d, %d ] ", arr[j], select);
#endif

			*ncompares_ptr = *ncompares_ptr + 1;

			if (arr[j] > select) {
				temp = arr[j];
				arr[j] = select;
				arr[j + 1] = temp;

#ifdef IS_VERBOSE
				printf(" => shifting [%d, %d]\n", arr[j], arr[j + 1]);
#endif

				*nswaps_ptr = *nswaps_ptr + 1;
			}
			else {
#ifdef IS_VERBOSE
				printf(" => not swapped\n");
#endif
			}

			j--;
		}
//#ifdef IS_VERBOSE
		printf("Iteration %d#: ", i);
		display(arr, size);
//#endif

		*insertion_ptr = *insertion_ptr + 1;
		i++;
	}
	*/
	return *nswaps_ptr + *ncompares_ptr + *removal_ptr + *insertion_ptr;
}