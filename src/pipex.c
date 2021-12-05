/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:03:29 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/05 10:40:42 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_vars *vars)
{
	int	pipe_fd[2];
	int	pid;

	open_files(vars);
	vars->path = get_env_path(vars->envp);
	vars->splited_path = ft_split(vars->path, ':');
	handle_cmds(vars);
	handle_cmds_path(vars);
	vars->cmd1_args = ft_split(vars->argv[2], ' ');
	vars->cmd2_args = ft_split(vars->argv[3], ' ');
	pipe(pipe_fd);
	pid = fork();
	if (pid == -1)
	{
		write(2, "Error\n", 6);
		clear_exit(vars);
	}
	if (pid == 0)
		handle_child(vars, pipe_fd);
	else
	{
		wait(0);
		handle_parent(vars, pipe_fd);
	}
	clear_exit(vars);
}
