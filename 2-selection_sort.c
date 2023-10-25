#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of array
 * @array: list with nums
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, index;
	int temp, swap, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		temp = i;
		flag = 0;
		for (index = i + 1; index < size; index++)
		{
			if (array[temp] > array[index])
			{
				temp = index;
				flag += 1;
			}
		}
		swap = array[i];
		array[i] = array[temp];
		array[temp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
