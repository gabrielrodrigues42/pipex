/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:03:29 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/08 22:21:58 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_vars *vars)
{
	int	pipe_fd[2];
	int	pid;

	vars->env_path = get_env_path(vars->envp);
	if (pipe(pipe_fd) == -1)
	{
		print_error(NULL);
		ft_strclear2(vars->env_path);
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		print_error(NULL);
		ft_strclear2(vars->env_path);
		exit(1);
	}
	if (pid == 0)
		handle_child(vars, pipe_fd);
	else
	{
		wait(0);
		handle_parent(vars, pipe_fd);
	}
	ft_strclear2(vars->env_path);
}
