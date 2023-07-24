#include "sort.h"

/**
 * swap - swap two elements in an array
 * @a: The first integer to be swapped
 * @b: the second integer to be swapped
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array of elements to sort
 * @size: size of the array
 * Return: array after each swap
 */

void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i,k, len = size;

	if (array == NULL || size < 2)
		return;

	while(1)
	{
		swapped = 0;

		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				for (k = 0; k < size - 1; k++)
				{
					printf("%d, ", array[k]);
				}
				printf("%d\n", array[size - 1]);
				swapped = 1;
			}
		}
		
		if (!swapped)
		{
			break;
		}

		len--;
	}
}
