#include "sort.h"
/**
 * selection_sort - sorts array of integers using selection sort.
 * @array: the array to be sorted.
 * @size: the size of the array.
 */


void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;

	/* Move boundary of unsorted subarray one by one. */
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		/* find the smallest element in the array */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

	/* swap the found smallest number with the first element. */
	temp = array[min];
	array[min] = array[i];
	array[i] = temp;
	print_array(array, size);
}
}
