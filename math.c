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

int stack_size(t_stack *top)
{
	t_stack *curr;
	int size;

	curr = top->next;
	size = 0;
	while (curr != NULL)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}

int count_size(t_count *here)
{
	t_count *curr;
	int size;

	curr = here->next;
	size = 0;
	while (curr != NULL)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}
