/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-lee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:40:57 by ji-lee            #+#    #+#             */
/*   Updated: 2021/06/12 17:38:41 by ji-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_stack(t_stack *top, char *data)
{
	t_stack		*new;
	int			num;

	num = ft_atoi(data);
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		error();
	new->next = NULL;
	stack_append(top, new, num);
}

void	try_split(t_stack *top_a, char *argv)
{
	char	**n_arr;
	int		i;
	int		len;

	n_arr = ft_split(argv, ' ');
	i = 0;
	len = ft_sstrlen(n_arr);
	while (i < len)
	{
		init_stack(top_a, n_arr[i]);
		free(n_arr[i++]);
	}
	free(n_arr);
}

void	begin(t_stack *top_a, t_stack *top_b)
{
	push_swap(top_a, top_b);
	free_all(top_a, top_b);
}

int		main(int argc, char *argv[])
{
	t_stack	*top_a;
	t_stack	*top_b;
	int		i;

	if (argc == 1)
		error();
	if (!(top_a = (t_stack *)malloc(sizeof(t_stack))))
		error();
	if (!(top_b = (t_stack *)malloc(sizeof(t_stack))))
		error();
	top_a->next = NULL;
	top_b->next = NULL;
	if (argc == 2)
		try_split(top_a, argv[1]);
	else
	{
		i = 1;
		while (i < argc)
			init_stack(top_a, argv[i++]);
	}
	if (is_sorted(top_a, top_b))
		return (0);
	begin(top_a, top_b);
	return (0);
}
