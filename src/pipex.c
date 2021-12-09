/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:03:29 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/09 12:19:46 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_vars *vars)
{
	vars->env_path = get_env_path(vars->envp);
	if (pipe(vars->pipe_fd) == -1)
	{
		print_error(NULL);
		clear_exit(1, NULL, NULL, vars);
	}
	vars->pid = fork();
	if (vars->pid == -1)
	{
		print_error(NULL);
		clear_exit(1, NULL, NULL, vars);
	}
	if (vars->pid == 0)
	{
		close(vars->pipe_fd[0]);
		handle_child(vars, vars->pipe_fd);
	}
	else
	{
		wait(0);
		close(vars->pipe_fd[1]);
		handle_parent(vars, vars->pipe_fd);
	}
	clear_exit(0, NULL, NULL, vars);
}
