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

void	exec_cmd(t_pipex pipex, char *str, char **envp)
{
	char	*cmd_path;

	dup2(pipex.ends[WR], WR);
	close(pipex.ends[RD]);
	dup2(pipex.infile, RD);
	cmd_and_options(&pipex, str);
	cmd_path = get_cmd_path(pipex.cmd, &pipex);
	if (!cmd_path)
	{
		free_child(&pipex);
		exit_error(ERROR_CMD);
	}
	if (execve(cmd_path, pipex.options, envp))
		exit_strerror();
	exit (127);
}

void	exec_cmd_2(t_pipex pipex, char *str, char **envp)
{
	char	*cmd_path;

	dup2(pipex.ends[RD], RD);
	close(pipex.ends[WR]);
	dup2(pipex.outfile, WR);
	cmd_and_options(&pipex, str);
	cmd_path = get_cmd_path(pipex.cmd, &pipex);
	if (!cmd_path)
	{
		free_child(&pipex);
		exit_error(ERROR_CMD);
	}
	if (execve(cmd_path, pipex.options, envp))
		exit_strerror();
	exit (127);
}
