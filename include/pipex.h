/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:11:48 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/02 21:52:51 by gandrade         ###   ########.fr       */
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

typedef struct s_vars
{
	char	**argv;
	char	**envp;
	int		argc;
	int		infile;
	int		outfile;
	char	*path;
	char	**splited_path;
	char	*cmd1;
	char	*cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**cmd1_args;
	char	**cmd2_args;
}	t_vars;

void	pipex(t_vars *vars);
int		init_vars(t_vars *vars, int argc, char **argv, char **envp);
int		open_files(t_vars *vars);
int		close_files(t_vars *vars);
int		handle_cmds(t_vars *vars);
int		clear_cmds(t_vars *vars);
int		handle_cmds_path(t_vars *vars);
int		clear_cmds_path(t_vars *vars);
char	*get_env_path(char **envp);
char	*get_cmd(char *argv);
char	*get_cmd_path(char *cmd, char **splited_path);
int		clear_double_pointer(char **str);
void	print_error(void);
void	clear_exit(t_vars *vars);
int		handle_parent(t_vars *vars, int *pipe_fd);
int		handle_child(t_vars *vars, int *pipe_fd);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_strclear(char **str);
size_t	ft_strlen(const char *s);

#endif
