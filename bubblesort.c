#include "pushswap.h"

void index_swap(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

void bubble_sort(int *arr, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				index_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}
