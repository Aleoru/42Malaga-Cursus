/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:52:12 by aoropeza          #+#    #+#             */
/*   Updated: 2023/02/13 18:52:15 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;
	int		exe;
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("Current dir: %s\n", cwd);
	}
	exe = 1;
	while (exe)
	{
		input = readline("MiniHell> ");
		if (ft_strlen(input) == 4)
			if (ft_memcmp("exit", input, 4) == 0)
				exe = 0;
		add_history(input);
		printf("%s\n", input);
	}
	return (0);
}

/* para compilar readline: -lreadline */
/* readline: lee la linea */
/* add_history: almacena la linea */
/* getcwd: ruta absoluta actual */
