/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:09:37 by aoropeza          #+#    #+#             */
/*   Updated: 2022/11/18 12:09:41 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoli(const char *str)
{
	int		index;
	long	num;
	long	sign;

	index = 0;
	num = 0;
	sign = 1;
	while (str[index] == ' ' || str[index] == '\f' || str[index] == '\n'
		|| str[index] == '\r' || str[index] == '\t' || str[index] == '\v')
		index++;
	if (str[index] == '-')
	{
		sign = sign * -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	if (!ft_isdigit(str[index]))
		return (0);
	while (ft_isdigit(str[index]))
	{
		num = (num * 10) + str[index] - '0';
		index++;
	}
	return (num * sign);
}

int	ft_issign(int arg)
{
	if (arg == 43 || arg == 45)
		return (1);
	return (0);
}
