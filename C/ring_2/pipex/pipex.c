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

static char	*get_cmd_path(char *cmd, char **envp, t_pipex *pipex)
{
	int		i;
	char	*cmd_path;
	char	*tmp;

	get_env_paths(pipex, envp);
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

static void	cmd_and_options(t_pipex	*pipex, char *str)
{
	char	**words;
	char	*tmp;

	pipex->options = ft_split(str, ' ');
	pipex->cmd = ft_strdup(pipex->options[0]);
}

static int	pipex_list(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		exit (1);
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex->outfile < 0)
		exit (1);
	return (0);
}

static int	exec_cmd(t_pipex pipex, char *str, char **envp)
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

static int	exec_cmd_2(t_pipex pipex, char *str, char **envp)
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

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_printf("Faltan argumentos\n"));
	else
	{
		if (pipe(pipex.ends) == -1)
			exit (1);
		pipex_list(&pipex, argc, argv, envp);
		pipex.pid = fork();
		if (pipex.pid == 0)
			exec_cmd(pipex, argv[2], envp);
		pipex.pid2 = fork();
		if (pipex.pid2 == 0)
			exec_cmd_2(pipex, argv[3], envp);
		waitpid(pipex.pid, NULL, 0);
		close(pipex.infile);
		waitpid(pipex.pid2, NULL, 0);
		close(pipex.outfile);
	}
	return (0);
}
