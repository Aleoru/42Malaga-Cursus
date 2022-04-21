/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:01:07 by aoropeza          #+#    #+#             */
/*   Updated: 2022/04/20 13:26:51 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	index;
	int	num;
	int	sign;

	index = 0;
	num = 0;
	sign = 1;
	while (str && str[index] <= ' ')
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
