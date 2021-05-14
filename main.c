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
	t_stack *curr;
	t_stack *tmp;
	int num;
	
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	num = ft_atoi(data);
	if (top->next == NULL)
	{
		top->next = new;
		new->data = num;
	}
	else
	{
		curr = top->next;
		while (curr != NULL)
		{
			tmp = curr;
			if (curr->data == num)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			curr = curr->next;
		}
		new->data = num;
		tmp->next = new;
	}
}

int main(int argc, char *argv[])
{
	t_stack *top_a;
	t_stack *top_b;
	int i;

	if (!(top_a = (t_stack *)malloc(sizeof(t_stack))))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	if (!(top_b = (t_stack *)malloc(sizeof(t_stack))))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	i = 1;
	while (i < argc)
	{
		init_stack(top_a, argv[i]);
		i++;
	}

	//pb(top_a, top_b);
	//test	
	printlst(top_a);
	printf("%s\n", "-");
	printlst(top_b);

	//free
	return (0);
}
