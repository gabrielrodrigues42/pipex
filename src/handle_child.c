/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:46:36 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/05 12:54:08 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_child(t_vars *vars, int *pipe_fd)
{
	dup2(vars->infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(vars->infile);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	if (execve(vars->cmd1_path, vars->cmd1_args, vars->envp) == -1)
	{
		print_error(NULL);
		clear_exit(vars);
	}
}
