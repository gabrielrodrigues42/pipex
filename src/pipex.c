/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:03:29 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/10 23:25:26 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_vars *vars)
{
	int	pipefd[2];
	int	pid;

	vars->env_path = get_env_path(vars->envp);
	if (pipe(pipefd) == -1)
	{
		print_error(NULL);
		clear_exit(1, NULL, NULL, vars);
	}
	pid = fork();
	if (pid == -1)
	{
		print_error(NULL);
		clear_exit(1, NULL, NULL, vars);
	}
	if (pid == 0)
		handle_child(vars, pipefd);
	else
		handle_parent(vars, pid, pipefd);
	clear_exit(0, NULL, NULL, vars);
}
