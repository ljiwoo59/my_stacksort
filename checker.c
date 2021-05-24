#include "pushswap.h"

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return(0);
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	t_stack *top_a;
	t_stack *top_b;
	int i;
	char r;
	char buf[4];

	if (argc == 1)
		return (0);
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
	i = 0;
	while (read(0, &r, 1) == 1)
	{
		if (i >= 4)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		if (r == '\n')
		{
			buf[i] = 0;
			i = 0;
			if (ft_strcmp(buf, "sa"))
				sa(top_a);
			else if (ft_strcmp(buf, "sb"))
				sb(top_b);
			else if (ft_strcmp(buf, "ss"))
				ss(top_a, top_b);
			else if (ft_strcmp(buf, "pa"))
				pa(top_b, top_a);
			else if (ft_strcmp(buf, "pb"))
				pb(top_a, top_b);
			else if (ft_strcmp(buf, "ra"))
				ra(top_a);
			else if (ft_strcmp(buf, "rb"))
				rb(top_b);
			else if (ft_strcmp(buf, "rr"))
				rr(top_a, top_b);
			else if (ft_strcmp(buf, "rra"))
				rra(top_a);
			else if (ft_strcmp(buf, "rrb"))
				rrb(top_b);
			else if (ft_strcmp(buf, "rrr"))
				rrr(top_a, top_b);
			else
			{
				write(1, "Error\n", 6);
				exit(0);
			}
		}
		else
			buf[i++] = r;
	}
	if (is_sorted(top_a, top_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	//free
	return (0);
}
