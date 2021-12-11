/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:45:23 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/10 23:16:10 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_parent(t_vars *vars, int *pipe_fd)
{
	char	**cmd_list;
	char	*cmd_path;
	int		outfile;

	waitpid(vars->pid, NULL, WNOHANG);
	close(vars->pipe_fd[1]);
	outfile = open(vars->argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (outfile < 0)
	{
		print_error(NULL);
		clear_exit(1, NULL, NULL, vars);
	}
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	cmd_list = get_cmd_list(vars->argv[3]);
	cmd_path = get_cmd_path(cmd_list[0], vars->env_path);
	if (!cmd_path)
		clear_exit(127, cmd_list, NULL, vars);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	if (execve(cmd_path, cmd_list, vars->envp) == -1)
	{
		print_error(NULL);
		clear_exit(1, cmd_list, cmd_path, vars);
	}
}
