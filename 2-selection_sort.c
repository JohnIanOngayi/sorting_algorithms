#include "sort.h"

/**
 * selection_sort - sorts an array of integers using the selction sort algo
 * @array: array of integers to be sorted
 * @size: number of elements in array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min  = 0;
	int tmp = 0;

	if (!array || size == 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				continue;
			}
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
