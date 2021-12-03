/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:46:36 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/02 21:54:35 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_child(t_vars *vars, int *pipe_fd)
{
	dup2(vars->infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(vars->infile);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	if (execve(vars->cmd1_path, vars->cmd1_args, vars->envp) == -1)
	{
		write(2, "Error\n", 6);
		clear_exit(vars);
	}
	return (0);
}
