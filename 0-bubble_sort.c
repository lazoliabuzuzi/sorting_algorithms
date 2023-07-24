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
	size_t i, j, k;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
			}
		}

		/*printf("%u: ", (unsigned int)(i + 1));*/

		for (k = 0; k < size; k++)
		{
			printf("%d ", array[k]);
		}

		printf("\n");
		if (!swapped)
			break;
	}
}
