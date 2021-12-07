/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:03:29 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/06 23:17:34 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_vars *vars)
{
	open_files(vars);
	vars->env_path = get_env_path(vars->envp);
	handle_cmds(vars);
	handle_cmds_path(vars);
	vars->cmd1_args = ft_split(vars->argv[2], ' ');
	vars->cmd2_args = ft_split(vars->argv[3], ' ');
	if (pipe(vars->pipe_fd) == -1)
		print_error(NULL);
	vars->pid = fork();
	if (vars->pid == -1)
	{
		print_error(NULL);
		clear_exit(vars);
	}
	if (vars->pid == 0)
		handle_child(vars, vars->pipe_fd);
	else
	{
		wait(0);
		handle_parent(vars, vars->pipe_fd);
	}
	clear_exit(vars);
}
