#include "pushswap.h"

//test
#include <stdio.h>
void printlst(t_stack *top)
{
	t_stack *curr = top->next;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}
//test

void init_stack(t_stack *top, char *data)
{
	t_stack *new;
	int num;
	
	num = ft_atoi(data);
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		error();
	new->next = NULL;
	stack_append(top, new, num);
}

int main(int argc, char *argv[])
{
	t_stack *top_a;
	t_stack *top_b;
	int i;

	if (argc == 1)
		error();
	if (!(top_a = (t_stack *)malloc(sizeof(t_stack))))
		error();
	if (!(top_b = (t_stack *)malloc(sizeof(t_stack))))
		error();
	top_a->next = NULL;
	top_b->next = NULL;
	i = 1;
	while (i < argc)
	{
		init_stack(top_a, argv[i]);
		i++;
	}
	if (is_sorted(top_a, top_b))
		return (0);
	//test
	push_swap(top_a, top_b);
//	printlst(top_a);
//	printf("%s\n", "-");
//	printlst(top_b);

	free_all(top_a, top_b);
	return (0);
}
