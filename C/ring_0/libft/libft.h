/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:23:20 by aoropeza          #+#    #+#             */
/*   Updated: 2022/04/19 17:23:22 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int		ft_isalpha(int arg);
int		ft_isdigit(int arg);
int		ft_isalnum(int arg);
int		ft_isascii(int arg);
int		ft_isprint(int arg);
size_t	ft_strlen(char *str);
void	*ft_memset(void *str, int ch, size_t nb);
void	ft_bzero(void *str, size_t nb);
void	*ft_memcpy(void *dest, const void *src, size_t nb);
void	*ft_memmove(void *dest, const void *src, size_t nb);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
char	*ft_strchr(const char *str, int ch);
char	*ft_strrchr(const char *str, int ch);
int		ft_strncmp(const char *str_one, const char *str_two, size_t n);
void	*ft_memchr(const void *str, int ch, size_t nb);
int		ft_memcmp(const void *str_one, const void *str_two, size_t nb);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
int		ft_atoi(char *str);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strdup(const char *str);

#endif