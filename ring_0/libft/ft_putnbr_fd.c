/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:35:27 by aoropeza          #+#    #+#             */
/*   Updated: 2022/05/04 18:17:13 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(int n, int dgt, int fd)
{
	int		aux;
	int		dgt_aux;
	char	c;

	if (n < 0)
		ft_putchar_fd('-', fd);
	while (dgt > 0)
	{
		dgt--;
		dgt_aux = dgt;
		if (n < 0)
			aux = n * -1;
		else
			aux = n;
		while (dgt_aux > 0)
		{
			aux = aux / 10;
			dgt_aux--;
		}
		c = (aux % 10) + '0';
		ft_putchar_fd(c, fd);
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	aux;
	int	dgt;

	dgt = 0;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		aux = n * -1;
	}
	else
		aux = n;
	while (aux > 0)
	{
		aux = aux / 10;
		dgt++;
	}
	ft_putchar(n, dgt, fd);
}
