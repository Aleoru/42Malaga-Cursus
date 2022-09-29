/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:44:25 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/09 18:44:27 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define RD		0
# define WR		1
# define STDOUT	"outfile"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "./libft/inc/libft.h"

typedef struct pipex
{
	pid_t	pid;
	int		ends[2];
	char	**paths;
	char	*cmd;
	char	**options;
}		t_pipex;

#endif
