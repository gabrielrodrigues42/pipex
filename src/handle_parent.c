/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:45:23 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/05 12:54:01 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_parent(t_vars *vars, int *pipe_fd)
{
	dup2(vars->outfile, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(vars->outfile);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (execve(vars->cmd2_path, vars->cmd2_args, vars->envp) == -1)
	{
		print_error(NULL);
		clear_exit(vars);
	}
}
