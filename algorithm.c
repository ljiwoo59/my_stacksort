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
		j = 0
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				index_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int find_pivot(t_stack *top)
{
	int tmp_arr[stack_size(top)];
	t_stack *curr;

	curr = top->next;
	i = 0;
	while (curr != NULL)
	{
		tmp_arr[i++] = curr->data;
		curr = curr->next;
	}
	i = 0;
	bubble_sort(tmp_arr, stack_size(top));
	
	return (tmp_arr[(stack_size(top) / 2) - 1]);
}

void init_push(t_stack *top_a, t_stack *top_b)
{
	int pivot;
	int i;

	pivot = find_pivot(top_a);
	i = 0
	while (stack_size(top_a) - i)
	{
		if (top->next->data >= pivot)
			pb(top_a, top_b);
		else
			ra(top_a);
		i++;
	}
}

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

void size_3_sort(t_stack *top_a)
{
	t_stack *f;

	f = top->next;
	if (f->data == min(top_a) && f->next->data == max(top_a))
	{
		ra(top_a);
		sa(top_a);
		rra(top_a);
	}
	else if (f->next->data == min(top_a) && f->next->next->data == max(top_a))
		sa(top_a);
	else if (f->next->data == max(top_a) && f->next->next->data == min(top_a))
	{
		ra(top_a);
		sa(top_a);
		rra(top_a);
		sa(top_a);
	}
	else if (f->data == max(top_a) && f->next->data == min(top_a))
	{
		sa(top_a);
		ra(top_a);
		sa(top_a);
		rra(top_a);
	}
	else if (f->data == max(top_a) && f->next->next->data == min(top_a))
	{
		sa(top_a);
		ra(top_a);
		sa(top_a);
		rra(top_a);
		sa(top_a);
	}
}

void count_append(t_count *curr, int c)
{
	t_count *new;

	if (!(new = (t_count *)malloc(sizeof(t_count))))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	new->next = NULL;
	new->count = c;
	if (curr->next == NULL)
		curr->next = new;
	else
	{
		curr = top->next;
		while (curr != NULL)
			curr = curr->next;
		curr = new;
	}
}

void push_swap(t_stack *top_a, t_stack *top_b)
{
	t_count *here;
	t_count *curr;
	int pivot;
	int i;
	int c;

	if (!(here = (t_count)malloc(sizeof(t_count))))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	here->next = NULL;
	init_push(top_a, top_b);
	// loop a
	while (stack_size(top_a) < 3)
	{
		pivot = find_pivot(top_a);
		i = 0;
		c = 0;
		while (stack_size(top_a) - i)
		{
			if (top->next->data >= pivot)
			{
				pb(top_a, top_b);
				c++;
			}
			else
				ra(top_a);
			i++;
		}
		count_append(here, c);
	}
	// reput a
	while (stack_size(here))
	{
		if (stack_size(top_a) == 2)
		{
			if (top_a->next->data > top_a->next->next->data)
				sa(top_a);
		}
		else if (stack_size(top_a) == 3)
			size_3_sort(top_a);
		i = 0;
		curr = here;
		while (curr->next->next != NULL)
			curr = curr->next;
		while ((curr->next->count) - (i++))
			pa(top_b, top_a);
		if (curr->next->count == 2)
		{
			if (top_a->next->data > top_a->next->next->data)
				sa(top_a);
		}

		else if (curr->next->count == 3)
			size_3_sort(top_a);
		free(curr->next);
		curr->next = NULL;
	}
	// loop b
}
