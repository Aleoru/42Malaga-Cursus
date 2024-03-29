/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:44:11 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/09 18:44:13 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_env_paths(t_pipex *pipex, char **envp)
{
	int		i;
	char	*tmp;

	i = 0;
	while (envp[i])
	{
		tmp = ft_strnstr(envp[i], "PATH=", ft_strlen("PATH="));
		if (tmp)
		{
			tmp = ft_strdup(envp[i]);
			break ;
		}
		i++;
	}
	pipex->paths = ft_split(tmp, ':');
	i = 0;
	while (pipex->paths[i])
	{
		free(tmp);
		tmp = pipex->paths[i];
		pipex->paths[i] = ft_strjoin(tmp, "/");
		i++;
	}
}

char	*get_cmd_path(char *cmd, t_pipex *pipex)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (pipex->paths[++i])
	{
		cmd_path = ft_strjoin(pipex->paths[i], cmd);
		if (access(cmd_path, 0) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (0);
}

static int	pipex_list(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		exit_error(ERROR_STDIN);
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex->outfile < 0)
		exit_error(ERROR_STDOUT);
	if (pipe(pipex->ends) == -1)
		exit_error(ERROR_PIPE);
	get_env_paths(pipex, envp);
	return (1);
}

static void	close_pipex(t_pipex *pipex, int *status)
{
	close(pipex->ends[0]);
	close(pipex->ends[1]);
	waitpid(pipex->pid, status, 0);
	waitpid(pipex->pid2, status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;
	int		exit_code;

	exit_code = 1;
	if (argc != 5)
		return (ret_error(ERROR_INPUT));
	else
	{
		pipex_list(&pipex, argc, argv, envp);
		pipex.pid = fork();
		if (pipex.pid == 0)
			exec_cmd(pipex, argv[2], envp);
		pipex.pid2 = fork();
		if (pipex.pid2 == 0)
			exec_cmd_2(pipex, argv[3], envp);
		close_pipex(&pipex, &status);
		if (WIFEXITED(status) != 0)
			exit_code = WEXITSTATUS(status);
		free_parent(&pipex);
	}
	return (exit_code);
}
