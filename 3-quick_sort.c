#include "sort.h"

void swap(int *a, int *b);
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size);
void quick_sort(int *array, size_t size);
/**
 * swap - swaps two integers.
 * @a: pointer to the first integer.
 * @b: pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Uses the lomuto partition for quick sort.
 * @array: pointer to the array to be partitioned.
 * @low: starting index of partition.
 * @high: ending index of partition.
 * @size: size of the array.
 * Return: the pivot index.
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1, j;
	size_t k;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				for (k = 0; k < size - 1; k++)
					printf("%d, ", array[k]);
				printf("%d\n", array[size - 1]);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		for (k = 0; k < size - 1; k++)
			printf("%d, ", array[k]);
		printf("%d\n", array[size - 1]);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - recursive function to use quick sort.
 * @array: pointer to the array to be sorted.
 * @low: starting index of partition.
 * @high: ending index of partition.
 * @size: size of the array.
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order.
 * @array: pointer to the array to be sorted.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
