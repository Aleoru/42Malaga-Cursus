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
# define ERROR_STDIN "Infile"
# define ERROR_STDOUT "Outfile"
# define ERROR_INPUT "Invalid number of arguments.\n"
# define ERROR_PIPE "Pipe"
# define ERROR_CMD "Command not found"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct pipex
{
	pid_t	pid;
	pid_t	pid2;
	int		ends[2];
	int		infile;
	int		outfile;
	char	**paths;
	char	*cmd;
	char	**options;
}		t_pipex;

size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
char	**ft_split(char const *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	exec_cmd(t_pipex pipex, char *str, char **envp);
void	exec_cmd_2(t_pipex pipex, char *str, char **envp);
void	free_child(t_pipex *pipex);
void	free_parent(t_pipex *pipex);
char	*get_cmd_path(char *cmd, t_pipex *pipex);
int		ret_error(char *error);
void	exit_error(char *error);
void	exit_strerror(void);

#endif
