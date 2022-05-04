/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:21:17 by aoropeza          #+#    #+#             */
/*   Updated: 2022/05/03 14:00:04 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*to_str(int len, int aux, int n, char *nb_str)
{
	int		index;
	int		aux_len;

	index = 0;
	if (n < 0)
	{
		nb_str[index] = '-';
		index++;
		n *= -1;
		len--;
	}
	while (len > 0)
	{
		len--;
		aux_len = len;
		aux = n;
		while (aux_len > 0)
		{
			aux = aux / 10;
			aux_len--;
		}
		nb_str[index++] = (aux % 10) + '0';
	}
	nb_str[index] = '\0';
	return (nb_str);
}

char	*ft_itoa(int n)
{
	char	*nb_str;
	int		aux;
	int		index;
	int		len;

	index = 0;
	aux = n;
	len = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		len++;
	while (aux != 0)
	{
		aux = aux / 10;
		len++;
	}
	nb_str = (char *)malloc((len + 1) * sizeof(char));
	nb_str[index] = *to_str(len, aux, n, nb_str);
	return (nb_str);
}
