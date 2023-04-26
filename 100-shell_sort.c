#include <stddef.h>
#include "sort.h"

int knuth(size_t);

/**
 * shell_sort - sorts an array using shell sort.
 * @array: the array to sort.
 * @size: the size of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, a, b, tmp;

	/* Calculate the initial gap size using the knuth sequence */
	gap = knuth(size);

	/* keep reducing the gap size until it becomes 1 */
	while (gap > 0)
	{
		/* perform the insertion sort on the subarrays of size gap */
		for (a = gap; a < size; a++)
		{
			tmp = array[a];
			b = a;

			while (b >= gap && (size_t)array[b - gap] > tmp)
			{
				array[b] = array[b - gap];
				b -= gap;
			}
			array[b] = tmp;
		}
		print_array(array, size);

		/* calculate the next gap size using knuth */

		gap = (gap - 1) / 3;
	}
}


/**
 * knuth - generates a gap sequence
 * @num: the size
 * Return: the size of the gap
 */

int knuth(size_t num)
{
	size_t n;

	n = 1;
	while (n < num)
		n = 3 * n + 1;
	return (n / 3);
}
