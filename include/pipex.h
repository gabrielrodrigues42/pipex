/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:11:48 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/09 22:41:44 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_vars
{
	int		pipe_fd[2];
	int		pid;
	int		argc;
	char	**argv;
	char	**envp;
	char	**env_path;

}	t_vars;

void	pipex(t_vars *vars);
void	init_vars(t_vars *vars, int argc, char **argv, char **envp);
void	handle_child(t_vars *vars, int *pipe_fd);
void	handle_parent(t_vars *vars, int *pipe_fd);
void	print_error(char *str);
void	clear_exit(int status, char **cmd_list, char *cmd_path, t_vars *vars);
char	**get_env_path(char **envp);
char	**get_cmd_list(char *argv);
char	*get_cmd_path(char *cmd, char **path_splited);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_strclear(char **str);
void	ft_strclear2(char **str);
void	ft_putendl_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);

#endif
