/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_childs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:28:09 by aoropeza          #+#    #+#             */
/*   Updated: 2022/10/04 14:28:13 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	cmd_and_options(t_pipex	*pipex, char *str)
{
	pipex->options = ft_split(str, ' ');
	pipex->cmd = ft_strdup(pipex->options[0]);
}

int	exec_cmd(t_pipex pipex, char *str, char **envp)
{
	char	*cmd_path;

	dup2(pipex.ends[1], 1);
	close(pipex.ends[0]);
	dup2(pipex.infile, 0);
	cmd_and_options(&pipex, str);
	cmd_path = get_cmd_path(pipex.cmd, envp, &pipex);
	if (!cmd_path)
	{
		perror(cmd_path);
		exit(1);
	}
	execve(cmd_path, pipex.options, envp);
	return (0);
}

int	exec_cmd_2(t_pipex pipex, char *str, char **envp)
{
	char	*cmd_path;

	dup2(pipex.ends[0], 0);
	close(pipex.ends[1]);
	dup2(pipex.outfile, 1);
	cmd_and_options(&pipex, str);
	cmd_path = get_cmd_path(pipex.cmd, envp, &pipex);
	if (!cmd_path)
	{
		perror(cmd_path);
		exit(1);
	}
	execve(cmd_path, pipex.options, envp);
	return (0);
}
