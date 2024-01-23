#include "sort.h"

void heap_over(int *array, size_t size, size_t base, size_t r);
void swap(int *a, int *b);

/**
 * heap_sort - sorts an array using heap_sort algorithm
 *
 * @array: array of integers to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int k;

	if (!array || size < 2)
	{
		return;
	}
	for (k = (size / 2) - 1; k >= 0; k--)
	{
		heap_over(array, size, size, k);
	}
	for (k = size - 1; k > 0; k--)
	{
		swap(array, array + k);
		print_array(array, size);

		heap_over(array, size, k, 0);
	}
}

/**
 * heap_over - turns  binary tree into complete binary heap.
 *
 * @array: an array of integers representing a binary tree.
 * @size: size of the array/tree.
 * @base: index of the base row of the tree.
 * @r: root node of the binary tree.
 */
void heap_over(int *array, size_t size, size_t base, size_t r)
{
	size_t largest, left, right;

	largest = r;
	left = 2 * r + 1;
	right = 2 * r + 2;

	if (left < base && array[left] > array[largest])
	{
		largest = left;
	}
	if (right < base && array[right] > array[largest])
	{
		largest = right;
	}
	if (largest != r)
	{
		swap(array + r, array + largest);
		print_array(array, size);

		heap_over(array, size, base, largest);
	}
}

/**
 * swap - swaps two integers
 *
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
