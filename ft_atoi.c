#include "pushswap.h"

int validation(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9')) 
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	return (0);
}

int			ft_atoi(char *str)
{
	long long	num;
	int			minus;

	num = 0;
	minus = 1;	
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
		if (!(*str))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
	}
	validation(str);
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	num *= minus;
	return ((int)num);
}
