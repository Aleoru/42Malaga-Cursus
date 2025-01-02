/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:48:41 by aoropeza          #+#    #+#             */
/*   Updated: 2022/06/10 19:35:52 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);
void	check_conversion(char ch, va_list args, int	*ptrlen);
void	ft_putchar(char c, int *ptrlen);
void	ft_putstr(char *s, int *ptrlen);
void	ft_putnbr(int n, int *ptrlen);
void	ft_putunbr(unsigned int n, int *ptrlen);
void	ft_tohex(unsigned int nb, char c, int *ptrlen);
void	ft_toptr(unsigned long nb, int *ptrlen);

#endif
