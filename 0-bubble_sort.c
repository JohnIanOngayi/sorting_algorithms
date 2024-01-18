#include "sort.h"

/**
 * bubble_sort - sorts integers in ascending order
 * @array: integer array to be sorted
 * @size: no of elements in the integer array
 */

void bubble_sort(int *array, size_t size)
{
	size_t tmp = 0;
	size_t i = 0;
	size_t j = 0;

	if (size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			while ((j + 1) < size)
			{
				if (array[j] > array[j + 1])
				{
					tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
					print_array(array, size);
				}
				else
					break;
			}
		}
	}
}
