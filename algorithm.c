#include "pushswap.h"

int find_pivot(t_stack *top, int num)
{
	int tmp_arr[num];
	t_stack *curr;
	int i;

	curr = top->next;
	i = 0;
	while (i < num)
	{
		tmp_arr[i++] = curr->data;
		curr = curr->next;
	}
	bubble_sort(tmp_arr, num);
	if (num % 2 == 0)
		return (tmp_arr[(num / 2) - 1]);
	else
		return (tmp_arr[(num / 2)]);
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
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new;
	}
}

void free_all(t_stack *top_a, t_stack *top_b)
{
	t_stack *curr;
	t_stack *tmp;

	curr = top_a;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	curr = top_b;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}

void push_swap(t_stack *top_a, t_stack *top_b)
{
	t_count *here;
	t_count *curr;
	int left;
	int c;

	if (!(here = (t_count *)malloc(sizeof(t_count))))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	here->next = NULL;
	if (stack_size(top_a) == 3)
		size_3_sort2(top_a);
	else if (stack_size(top_a) == 5)
		div_a5(top_a, top_b, here, stack_size(top_a));
	else
		div_a(top_a, top_b, here, stack_size(top_a));
	free(here);
}
