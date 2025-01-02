/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:22:03 by aoropeza          #+#    #+#             */
/*   Updated: 2022/10/05 13:22:06 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ret_error(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}

void	exit_error(char *error)
{
	perror(error);
	exit (127);
}

void	exit_strerror(void)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	exit(127);
}
