#include "sort.h"

/**
 * mergeSort - sorts subarrays for merge_sort
 * @array: array to be sorted
 * @size: no of elements in array
 * @start: starting index of array
 * @end: last index of array
 */

void mergeSort(int *array, size_t size, size_t start, size_t end)
{
	size_t mid = 0;

	mid = (start + end + 1) / 2;
	if (start == end)
		return;

	mergeSort(array, size, start, mid - 1);
	mergeSort(array, size, mid, end);
}


/**
 * merge - merges two sub arrays returned
 * @array: array of ints to be sorted
 * @size: no of elements in array
 * @lb: lower bound for merge
 * @mid: midpoint for array
 * @ub: upper bound for merge
 * Return: a pointer to a sorted array
 */

int *merge(int *array, size_t size, size_t lb, size_t mid, size_t ub)
{
	size_t i, j, k = 0;
	int *ret_array = (int *)malloc(sizeof(int) * size);

	if (ret_array == NULL)
		return (NULL);
	i = lb;
	j = mid;
	k = lb;
	while (i <= mid && j <= ub)
	{
		if (array[i] < array[j])
		{
			ret_array[k] = array[i];
			i++;
		}
		else
		{
			ret_array[k] = array[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		while (j <= ub)
		{
			ret_array[k] = array[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			ret_array[k] = array[j];
			j++;
			k++;
		}
	}
}


/**
 * merge_sort - sorts array in ascending order
 * @array: array of integers to be sorted
 * @size: no of elements in array
 */

void merge_sort(int *array, size_t size)
{
	mergeSort(array, size, 0, size - 1);

