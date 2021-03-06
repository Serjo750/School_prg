/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:34:10 by bleaf             #+#    #+#             */
/*   Updated: 2022/07/11 19:55:53 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	error(t_list **a)
{
	ft_clear_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

int	ps_atoi(const char *str, t_list **a)
{
	int		i;
	long	res;
	int		neg;

	neg = 1;
	res = 0;
	i = 0;
	if (str[0] == '-')
	{
		i = 1;
		neg = -1;
		if (!ft_isdigit(str[1]))
			error(a);
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i] - '0');
		else
			error(a);
		if (res * neg > INT_MAX || res * neg < INT_MIN)
			error(a);
		i++;
	}
	return (res * neg);
}
