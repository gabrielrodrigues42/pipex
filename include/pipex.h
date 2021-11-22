/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:11:48 by gandrade          #+#    #+#             */
/*   Updated: 2021/11/22 19:54:41 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>

# define ERROR -1
# define CHILD 0
# define STDIN 0
# define STDOUT 1
# define STDERR 2

/* Core */
char	*get_env_path(char **envp);
void	*clear_double_pointer(char **str);

/* Utils */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_strclear(char **str);
size_t	ft_strlen(const char *s);

#endif
