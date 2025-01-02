/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:33:49 by aoropeza          #+#    #+#             */
/*   Updated: 2023/02/21 19:33:52 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int arg)
{
	if (arg >= 48 && arg <= 57)
		return (1);
	return (0);
}

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
