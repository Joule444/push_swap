/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:29:03 by jules             #+#    #+#             */
/*   Updated: 2022/09/30 13:29:29 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	res;
	long	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (sign * res);
}
