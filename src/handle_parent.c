/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:45:23 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/02 21:55:07 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_parent(t_vars *vars, int *pipe_fd)
{
	dup2(vars->outfile, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(vars->outfile);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (execve(vars->cmd2_path, vars->cmd2_args, vars->envp) == -1)
	{
		write(2, "Error\n", 6);
		clear_exit(vars);
	}
	return (0);
}
