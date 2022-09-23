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
		if (access(cmd_path, F_OK | X_OK) == 0)
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

static int	exec_cmd(t_pipex *pipex, char *str, char **envp)
{
	char	*cmd_path;

	cmd_and_options(pipex, str);
	cmd_path = get_cmd_path(pipex->cmd, envp, pipex);
	if (!cmd_path)
	{
		perror(cmd_path);
		return (-1);
	}
	execve(cmd_path, pipex->options, envp);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd_path;
	pid_t	pid;
	t_pipex	pipex;
	int		status;
	int		ends[2];
	char	*secret;
	char	buffer[30];
	int		reader;

	if (argc < 3)
		return (ft_printf("Faltan argumentos\n"));
	else
	{
		if (pipe(ends) == -1)
			return (1);
		pid = fork();
		if (pid == 0)
		{
			close(ends[0]);
			secret = ft_strdup("Hola que tal");
			write(ends[1], secret, ft_strlen(secret));
			close(ends[1]);
			return (0);
		}
			//exec_cmd(&pipex, argv[1], envp);
		else if (pid > 0)
		{
			/*waitpid(pid, &status, 0);
			pid = fork();
			if (pid == 0)
				exec_cmd(&pipex, argv[2], envp);
			buffer[reader] = '\0';*/
			close(ends[1]);
			waitpid(pid, NULL, 0);
			reader = read(ends[0], buffer, 30);
			close(ends[0]);
			buffer[reader] = '\0';
			ft_printf("\"%s\"\n", buffer);
		}
	}
	return (0);
}
