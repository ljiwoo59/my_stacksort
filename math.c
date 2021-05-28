#include "pushswap.h"

int min(t_stack *top)
{
	t_stack *tmp;
	int min;
	int i;

	tmp = top->next;
	min = tmp->data;
	i = 2;
	while (i--)
	{
		tmp = tmp->next;
		if (min > tmp->data)
			min = tmp->data;
	}
	return (min);
}

int max(t_stack *top)
{
	t_stack *tmp;
	int max;
	int i;

	tmp = top->next;
	max = tmp->data;
	i = 2;
	while (i--)
	{
		tmp = tmp->next;
		if (max < tmp->data)
			max = tmp->data;
	}
	return (max);
}
