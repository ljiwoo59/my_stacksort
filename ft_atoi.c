/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-lee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:39:31 by ji-lee            #+#    #+#             */
/*   Updated: 2021/06/12 14:51:52 by ji-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	validation(char *str)
{
	if (*str == '+' || *str == '-')
	{
		str++;
		if (!(*str))
			error();
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			error();
		str++;
	}
}

int		ft_atoi(char *str)
{
	long long	num;
	int			minus;

	num = 0;
	minus = 1;
	validation(str);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	num *= minus;
	if (num > 2147483647 || num < -2147483648)
		error();
	return ((int)num);
}
