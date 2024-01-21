#include "sort.h"

/**
 * swap - swaps two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 * @array: parent array of integers a and b
 * @size: no of elements in array
 */
void swap(int *a, int *b, size_t size, int *array)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

	print_array(array, size);
}

/**
 * partition - moves abd returns the pivot
 * @array: sub array to be sorted
 * @start: first index of subarray
 * @end: last index of subarray
 * @size: no of elements in the array
 * Return: the index of the pivot element
 */
size_t partition(int *array, size_t start, size_t end, size_t size)
{
	size_t prev, curr, pivot;
	int tmp = 0;

	prev = start - 1;
	pivot = end;
	for (curr = start; curr <= end - 1; curr++)
	{
		if (array[curr] < array[pivot])
		{
			prev++;
			/*swap(&(array[curr]), &(array[prev]), size, array);*/
			 tmp = array[curr];
			 array[curr] = array[prev];
			 array[prev] = tmp;
		}
	}
	prev++;
	/*swap(&(array[end]), &(array[prev]), size, array);*/
	SWAP(&(array[end]), &(array[prev]), size, array);
	/**
	 * tmp = array[prev];
	 * array[prev] = array[end];
	 * array[end] = tmp;
	 */
	return (prev);
}


/**
 * partitionSort - does the lomuto partition sort for the quick sort function
 * @array: sub array to be sorted
 * @start: first index of subarray
 * @end: last index of subarray
 * @size: no of elements in the array
 */
void partitionSort(int *array, size_t start, size_t end, size_t size)
{
	size_t pivot;

	if (start >= end)
		return;
	pivot = partition(array, start, end, size);
	if (pivot > start)
		partitionSort(array, start, (pivot - 1), size);
	if (pivot < end)
		partitionSort(array, (pivot + 1), end, size);

}
/**
 * quick_sort - implements the quicksort algorithm by Lomuto Partition
 * @array: array of integers to be sorted
 * @size: no of elements in the array
 */

void quick_sort(int *array, size_t size)
{
	/**
	 * Keep three pointers prev, cur and pivot
	 * cur = -1
	 * prev = 0
	 * pivot = size - 1(last element)
	 * if a[cur] >= a[pivot]
	 *	cur++ and pass
	 * else
	 *	prev++ and swap(a[cur], a[prev])
	 * if(cur == pivot)
	 *	prev++ and swap(a[prev], a[pivot])
	 * a[pivot] is in right pos create subarrays and recurse on subarrays
	 */
	if (!array || size < 2)
		return;
	partitionSort(array, 0, size - 1, size);
}
