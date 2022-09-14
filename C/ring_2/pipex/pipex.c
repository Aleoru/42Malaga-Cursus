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

char	*get_cmd_path(char *cmd, char **envp)
{
    int     i;
    char    *envp_PATH;
    char    **paths;
	char	*cmd_path;
	char	*tmp;

    i = 0;
    while (envp[i])
    {
        envp_PATH = ft_strnstr(envp[i], "PATH=", ft_strlen("PATH="));
        if (envp_PATH)
		{
            envp_PATH = ft_strdup(envp[i]);
			break ;
		}
		i++;
    }
    paths = ft_split(envp_PATH, ':');
    i = 0;
    while (paths[i])
    {
		tmp = paths[i];
        paths[i] = ft_strjoin(tmp, "/");
		free(tmp);
        i++;
    }
    i = 0;
    while (paths[i])
    {
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
    }
}

int main(int argc, char **argv, char **envp)
{
    char    *options[3] = {"ls", "-la", NULL};
	char	*cmd = "ls";
	char	*cmd_path;

    (void)argc;
    (void)argv;
	cmd_path = get_cmd_path(cmd, envp);
	if (!cmd_path)
	{
		perror(cmd_path);
		return (-1);
	}
    execve(cmd_path, options, envp);
    return (0);
}